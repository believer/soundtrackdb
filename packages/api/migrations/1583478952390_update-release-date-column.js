/* eslint-disable camelcase */

exports.shorthands = undefined

exports.up = pgm => {
  pgm.renameColumn('soundtrack', 'release_year', 'release_date')

  pgm.addColumns('soundtrack', { year: 'text' })

  pgm.sql(`
    UPDATE soundtrack AS s1 SET year = 
    (SELECT EXTRACT(YEAR FROM release_date)::text FROM soundtrack AS s2 WHERE s1.id = s2.id);
  `)
}

exports.down = pgm => {
  pgm.renameColumn('soundtrack', 'release_date', 'release_year')
  pgm.dropColumns('soundtrack', ['year'])
}
