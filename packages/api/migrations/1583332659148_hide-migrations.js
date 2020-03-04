/* eslint-disable camelcase */

exports.shorthands = undefined

exports.up = pgm => {
  pgm.sql(`
    comment on table pgmigrations is E'@omit :CRUDFOAM';
  `)
}

exports.down = pgm => {
  pgm.sql(`
    comment on table pgmigrations is '';
  `)
}
