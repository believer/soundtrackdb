/* eslint-disable camelcase */

exports.shorthands = undefined

exports.up = pgm => {
  pgm.sql(
    `ALTER TABLE soundtrack ALTER COLUMN soundtrack_type TYPE VARCHAR(255);`
  )

  pgm.dropType('soundtrack_type')
  pgm.createType('soundtrack_type', ['game', 'movie', 'tv'])

  pgm.sql(
    `ALTER TABLE soundtrack ALTER COLUMN soundtrack_type TYPE soundtrack_type USING (soundtrack_type::soundtrack_type);`
  )
}

exports.down = pgm => {}
