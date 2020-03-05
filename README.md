# Soundtrack DB

A database of soundtracks for movies and games.

## Get started

`npx lerna bootstrap` to install all dependencies

### Frontend

```sh
$ cd packages/web
$ yarn start # Start BuckleScript compiler
$ yarn relay:watch # In another terminal, start Relay compiler
$ yarn server # In another terminal, start Webpack
```

Open http://localhost:8000 in your favorite browser

### API

API is only PostGraphile at this point.

```sh
$ cd packages/api
$ docker-compose up -d # Start database
$ yarn migrate up # Insert tables and data
$ yarn db:restore # Seed database
$ yarn start
```

## Tech

- [ReasonML (ReasonReact)](https://reasonml.github.io/reason-react/)
- [Relay](https://relay.dev/)
- [PostgreSQL](https://www.postgresql.org/)
- [PostGraphile](https://www.graphile.org/postgraphile/)
