const { makeExtendSchemaPlugin, gql } = require('graphile-utils')
const got = require('got')
const cheerio = require('cheerio')

const cleanTitle = title =>
  title
    .toLowerCase()
    .replace(' - original score', '')
    .replace(' - original motion picture score')

const getSpotifyId = async (title, composer) => {
  const {
    body: { tracks: [spotify] = [] },
  } = await got(
    `https://wejay.willcodefor.beer/search?q=album:${encodeURI(
      cleanTitle(title)
    )}%20artist:${encodeURI(composer)}`,
    { responseType: 'json' }
  )

  return spotify ? spotify.albumId : null
}

const getIMDbId = async title => {
  const { body: imdbData } = await got(
    `https://www.imdb.com/find?q=${encodeURI(cleanTitle(title))}`
  )
  const $ = cheerio.load(imdbData)

  const matchedTitle = $('.result_text a')
    .first()
    .attr('href')
  const id = matchedTitle ? matchedTitle.match(/tt\d+/) : []

  return id.length ? id[0] : null
}

const getReleaseDate = $ => {
  return $('#titlebox p')
    .filter(function() {
      return $(this)
        .text()
        .includes('Release Date:')
    })
    .text()
    .replace('Release Date: ', '')
    .trim()
}

const getPlaylist = $ => {
  return $('.cbox_table tbody tr:not(:last-child)')
    .map(function(i) {
      const title = $(this)
        .find('td:nth-child(2)')
        .contents()
        .first()
        .text()
        .trim()
      const playtime = $(this)
        .find('td:nth-child(3)')
        .text()
        .trim()

      return `${i + 1};${title};${playtime}`
    })
    .get()
    .join('\n')
}

const getComposers = $ => {
  return $('#cbox_3 a[href^="/person"]')
    .map(function() {
      return $(this).text()
    })
    .get()
}

const getSoundtrackType = $ => {
  const href = $('#cbox_2 a').attr('href')

  if (href.includes('movie')) {
    return 'movie'
  } else if (href.includes('videogame')) {
    return 'game'
  } else if (href.includes('tv')) {
    return 'tv'
  }
}

const SoundtrackPlaylistPlugin = makeExtendSchemaPlugin(() => {
  return {
    typeDefs: gql`
      type SoundtrackPlaylist {
        composers: [String!]!
        title: String!
        imdbId: String
        soundtrackType: SoundtrackType
        spotifyId: String
        releaseDate: String!
        playlist: String!
      }

      extend type Mutation {
        """
        Gets a playlist from Soundtrack.net
        """
        soundtrackPlaylist(url: String!): SoundtrackPlaylist!
      }
    `,
    resolvers: {
      Mutation: {
        soundtrackPlaylist: async (_, { url }) => {
          const { body } = await got(url)
          const $ = cheerio.load(body)

          const title = $('#titlebox h1').text()
          const imdbId = await getIMDbId(title)
          const releaseDate = await getReleaseDate($)
          const playlist = await getPlaylist($)
          const composers = await getComposers($)
          const soundtrackType = await getSoundtrackType($)
          const spotifyId = await getSpotifyId(title, composers[0])

          return {
            composers,
            imdbId,
            playlist,
            releaseDate,
            soundtrackType,
            spotifyId,
            title,
          }
        },
      },
    },
  }
})

module.exports = {
  SoundtrackPlaylistPlugin,
}
