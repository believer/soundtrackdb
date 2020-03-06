const { makeExtendSchemaPlugin, gql } = require('graphile-utils')

const StatsPlugin = makeExtendSchemaPlugin(() => {
  return {
    typeDefs: gql`
      type ComposerStat {
        count: Int!
        fullName: String!
      }

      type YearStat {
        count: Int!
        year: String!
      }

      type Categories {
        movie: Int!
        game: Int!
        tv: Int!
      }

      type Stats {
        categories: Categories!
        composers: [ComposerStat!]!
        totalDuration: Float!
        years: [YearStat!]!
      }

      extend type Query {
        stats: Stats!
      }
    `,
    resolvers: {
      Query: {
        stats: () => ({}),
      },
      Stats: {
        totalDuration: async (_, _args, { pgClient }) => {
          const {
            rows: [first],
          } = await pgClient.query(`
            SELECT SUM(duration) FROM track
          `)

          return parseInt(first.sum, 10)
        },

        categories: async (_, _args, { pgClient }) => {
          const { rows } = await pgClient.query(`
            SELECT
              soundtrack_type,
              COUNT(*)
            FROM soundtrack
            GROUP BY soundtrack_type;
          `)

          return rows.reduce(
            (acc, { soundtrack_type, count }) => {
              switch (soundtrack_type) {
                case 'movie':
                  return { ...acc, movie: count }
                case 'tv':
                  return { ...acc, tv: count }
                case 'game':
                  return { ...acc, game: count }
                default:
                  return acc
              }
            },
            { movie: 0, game: 0, tv: 0 }
          )
        },

        composers: async (_, _args, { pgClient }) => {
          const { rows } = await pgClient.query(`
            SELECT
                c.first_name as "firstName",
                c.last_name as "lastName",
                COUNT(*)
            FROM
              soundtrack_composer AS sc
              INNER JOIN composer AS c ON c.id = sc.composer_id
            GROUP BY
               sc.composer_id, c.first_name, c.last_name
            HAVING COUNT(*) > 1
            ORDER BY count DESC;
          `)

          return rows.map(({ count, lastName, firstName }) => ({
            count,
            fullName: lastName ? `${firstName} ${lastName}` : firstName,
          }))
        },

        years: async (_query, args, { pgClient }) => {
          const { rows } = await pgClient.query(`
            SELECT
              year,
              COUNT(*)
            FROM soundtrack
            GROUP BY year
            ORDER BY year;
          `)

          return rows
        },
      },
    },
  }
})

module.exports = {
  StatsPlugin,
}
