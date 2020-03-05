const { makeExtendSchemaPlugin, gql } = require('graphile-utils')
const axios = require('axios')
const cheerio = require('cheerio')

const getSpotifyId = async title => {
  const {
    data: { tracks: [spotify] = [] },
  } = await axios.get(
    `https://wejay.willcodefor.beer/search?q=album:${encodeURI(title)}`
  )

  return spotify ? spotify.albumId : null
}

const getIMDbId = async title => {
  const { data: imdbData } = await axios.get(
    `https://www.imdb.com/find?q=${encodeURI(title)}`
  )
  const $ = cheerio.load(imdbData)

  const id = $('.result_text a')
    .first()
    .attr('href')
    .match(/tt\d+/)

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

const getComposer = $ => {
  return $('#cbox_3 a[href^="/person"]')
    .map(function() {
      return $(this).text()
    })
    .get()
}

const SoundtrackPlaylistPlugin = makeExtendSchemaPlugin(() => {
  return {
    typeDefs: gql`
      type SoundtrackPlaylist {
        composer: [String!]!
        title: String!
        imdbId: String
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
          const { data } = await axios.get(url)
          const $ = cheerio.load(data)

          const title = $('#titlebox h1').text()
          const spotifyId = await getSpotifyId(title)
          const imdbId = await getIMDbId(title)
          const releaseDate = await getReleaseDate($)
          const playlist = await getPlaylist($)
          const composer = await getComposer($)

          return {
            composer,
            imdbId,
            playlist,
            releaseDate,
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
