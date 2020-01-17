# Soundtrack DB

A database of soundtracks for movies and games.

## Get started

### Frontend

`sh $ cd packages/web $ npm run start # Start BuckleScript compiler $ npm run relay:watch # In another terminal, start Relay compiler $ npm run server # In another terminal, start Webpack`

Open http://localhost:8000 in your favorite browser

### API

API is only Postgraphile at this point.

`sh $ cd packages/api $ docker-compose up -d # Start database $ npm run migrate up # Insert tables and data $ npm run start`

## Tech

- [ReasonML (ReasonReact)](https://reasonml.github.io/reason-react/)
- [Relay](https://relay.dev/)
- [PostgreSQL](https://www.postgresql.org/)
- [PostGraphile](https://www.graphile.org/postgraphile/)
