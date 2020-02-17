/* eslint-disable camelcase */

exports.shorthands = undefined

exports.up = pgm => {
  pgm.sql(
    `CREATE FUNCTION tracks_totalDuration () RETURNS bigint AS $$
      SELECT SUM(duration)
      FROM track;
   $$ LANGUAGE sql STABLE`
  )
}

exports.down = pgm => {}
