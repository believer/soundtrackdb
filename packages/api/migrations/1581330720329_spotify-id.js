/* eslint-disable camelcase */

exports.shorthands = undefined

exports.up = pgm => {
  pgm.sql(`
    ALTER TABLE soundtrack ADD COLUMN spotify_id text unique;
  `)
}

exports.down = pgm => {}
