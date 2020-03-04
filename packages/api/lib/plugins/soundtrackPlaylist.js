const { makeExtendSchemaPlugin, gql } = require('graphile-utils')
const axios = require('axios')
const cheerio = require('cheerio')

const SoundtrackPlaylistPlugin = makeExtendSchemaPlugin(() => {
  return {
    typeDefs: gql`
      type SoundtrackPlaylist {
        title: String!
        imdbId: String
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

          const { data: imdbData } = await axios.get(
            `https://www.imdb.com/find?q=${title}`
          )
          const imdb = cheerio.load(imdbData)

          const imdbId = imdb('.result_text a')
            .first()
            .attr('href')

            .match(/tt\d+/)

          const releaseDate = $('#titlebox p')
            .filter(function() {
              return $(this)
                .text()
                .includes('Release Date:')
            })
            .text()
            .replace('Release Date: ', '')
            .trim()

          const playlist = $('.cbox_table tbody tr:not(:last-child)')
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

          return {
            title,
            releaseDate,
            imdbId: imdbId.length ? imdbId[0] : null,
            playlist,
          }
        },
      },
    },
  }
})

module.exports = {
  SoundtrackPlaylistPlugin,
}
