const express = require('express')
const { postgraphile } = require('postgraphile')

const app = express()

app.use(
  postgraphile(
    process.env.DATABASE_URL ||
      'postgres://postgres:example@localhost:5432/soundtrackdb',
    'public',
    {
      appendPlugins: [
        require('@graphile-contrib/pg-simplify-inflector'),
        require('@graphile-contrib/pg-order-by-related'),
      ],
      classicIds: true,
      enableCors: true,
      enableQueryBatching: true,
      enhanceGraphiql: true,
      extendedErrors: ['hint', 'detail', 'errcode'],
      graphiql: true,
      ignoreIndexes: false,
      ignoreRBAC: false,
      showErrorStack: 'json',
      watchPg: true,
    }
  )
)

app.listen(process.env.PORT || 5000)
