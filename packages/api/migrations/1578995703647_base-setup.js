/* eslint-disable camelcase */

exports.shorthands = undefined

exports.up = pgm => {
  pgm.sql(`
CREATE TYPE "soundtrack_type" AS ENUM (
  'game',
  'movie'
);

CREATE TABLE "composer" (
  "id" SERIAL PRIMARY KEY,
  "first_name" text NOT NULL,
  "last_name" text,
  "created_at" timestamp NOT NULL DEFAULT (now()),
  "updated_at" timestamp NOT NULL DEFAULT (now())
);

CREATE TABLE "soundtrack" (
  "id" SERIAL PRIMARY KEY,
  "title" text NOT NULL,
  "imdb_id" text,
  "soundtrack_type" soundtrack_type NOT NULL,
  "release_year" timestamp NOT NULL,
  "created_at" timestamp NOT NULL DEFAULT (now()),
  "updated_at" timestamp NOT NULL DEFAULT (now())
);

CREATE TABLE "soundtrack_composer" (
  "composer_id" int NOT NULL,
  "soundtrack_id" int NOT NULL,
  PRIMARY KEY (composer_id, soundtrack_id)
);

CREATE TABLE "track" (
  "id" SERIAL PRIMARY KEY,
  "title" text NOT NULL,
  "duration" int NOT NULL,
  "soundtrack_id" int NOT NULL,
  "track_number" int NOT NULL,
  "created_at" timestamp NOT NULL DEFAULT (now()),
  "updated_at" timestamp NOT NULL DEFAULT (now())
);

CREATE TABLE "track_composer" (
  "track_id" int NOT NULL,
  "composer_id" int NOT NULL,
  PRIMARY KEY (track_id, composer_id)
);

ALTER TABLE "soundtrack_composer" ADD FOREIGN KEY ("composer_id") REFERENCES "composer" ("id");

ALTER TABLE "soundtrack_composer" ADD FOREIGN KEY ("soundtrack_id") REFERENCES "soundtrack" ("id");

ALTER TABLE "track" ADD FOREIGN KEY ("soundtrack_id") REFERENCES "soundtrack" ("id");

ALTER TABLE "track_composer" ADD FOREIGN KEY ("track_id") REFERENCES "track" ("id");

ALTER TABLE "track_composer" ADD FOREIGN KEY ("composer_id") REFERENCES "composer" ("id");
  `)

  pgm.sql(`
    create function composer_full_name(composer composer) returns text as $$
      select composer.first_name || COALESCE(' ' || composer.last_name, '')
    $$ language sql stable;

    -- Simple search function
    create function search(query text) returns setof soundtrack as $$
      SELECT *
      FROM soundtrack AS s 
      WHERE s.title ILIKE ('%' || query || '%') 
    $$ language sql stable;
  `)

  //pgm.sql(`
  //INSERT INTO composer (first_name, last_name) VALUES ('Thomas', 'Newman');
  //INSERT INTO composer (first_name, last_name) VALUES ('Clint', 'Mansell');
  //INSERT INTO composer (first_name, last_name) VALUES ('Kronos', 'Quartet');

  //-- The Fountain
  //INSERT INTO soundtrack (title, imdb_id, soundtrack_type, release_year) VALUES ('The Fountain', 'tt0414993', 'movie', '2006-11-27');
  //INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (2, 1);
  //INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (3, 1);

  //-- Tracks
  //INSERT INTO track (title, duration, soundtrack_id, track_number) VALUES
  //('The Last Man', 369, 1, 1),
  //('Holy Dread!', 232, 1, 2),
  //('Tree of Life', 225, 1, 3),
  //('Stay with Me', 216, 1, 4),
  //('Death Is a Disease', 154, 1, 5),
  //('Xibalba', 323, 1, 6),
  //('First Snow', 189, 1, 7),
  //('Finish It', 265, 1, 8),
  //('Death Is the Road to Awe', 506, 1, 9),
  //('Together We Will Live Forever', 302, 1, 10);

  //-- Add Kronos Quartet to some tracks
  //INSERT INTO track_composer (track_id, composer_id) VALUES
  //(2, 3),
  //(3, 3),
  //(4, 3),
  //(6, 3),
  //(7, 3),
  //(8, 3),
  //(9, 3);

  //-- 1917
  //INSERT INTO soundtrack (title, imdb_id, soundtrack_type, release_year) VALUES
  //('1917', 'tt8579674', 'movie', '2019-12-20');

  //INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (1,2);
  //INSERT INTO track (title, duration, soundtrack_id, track_number) VALUES
  //('1917', 77, 2, 1),
  //('Up the Down Trench', 379, 2, 2),
  //('Gehenna', 215, 2, 3),
  //('A Scrap of Ribbon', 390, 2, 4),
  //('The Night Window', 221, 2, 5),
  //('The Boche', 202, 2, 6),
  //('Tripwire', 101, 2, 7),
  //('A Bit of Tin', 123, 2, 8),
  //('Lockhouse', 244, 2, 9),
  //('Blake and Schofield', 260, 2, 10),
  //('Milk', 610, 2, 11),
  //('Écoust-Saint-Mein', 157, 2, 12),
  //('Les Arbres', 217, 2, 13),
  //('Engländer', 269, 2, 14),
  //('The Rapids', 90, 2, 15),
  //('Croisilles Wood', 127, 2, 16),
  //('Sixteen Hundred Men', 392, 2, 17),
  //('Mentions in Dispatches', 224, 2, 18),
  //('Come Back to Us', 340, 2, 19);

  //-- Requiem for a Dream
  //INSERT INTO soundtrack (title, imdb_id, soundtrack_type, release_year) VALUES ('Requiem for a Dream', 'tt0180093', 'movie', '2000-05-14');
  //INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (2, 3);
  //INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (3, 3);

  //INSERT INTO track (title, duration, soundtrack_id, track_number) VALUES
  //('Summer Overture', 155, 3, 1),
  //('Party', 29, 3, 2),
  //('Coney Island Dreaming', 65, 3, 3),
  //('Party', 36, 3, 4),
  //('Chocolate Charms', 26, 3, 5),
  //('Ghosts of Things to Come', 94, 3, 6),
  //('Dreams', 44, 3, 7),
  //('Tense', 38, 3, 8),
  //('Dr. Pill', 42, 3, 9),
  //('High on Life', 11, 3, 10),
  //('Ghosts', 82, 3, 11),
  //('Crimin'' & Dealin''', 105, 3, 12),
  //('Hope Overture', 151, 3, 13),
  //('Tense', 28, 3, 14),
  //('Bialy & Lox Conga', 45, 3, 15),
  //('Cleaning Apartment', 86, 3, 16),
  //('Ghosts-Falling', 71, 3, 17),
  //('Dreams', 63, 3, 18),
  //('Arnold', 155, 3, 19),
  //('Marion Barfs', 142, 3, 20),
  //('Supermarket Sweep', 134, 3, 21),
  //('Dreams', 33, 3, 22),
  //('Sara Goldfarb Has Left the Building', 77, 3, 23),
  //('Bugs Got a Devilish Grin Conga', 57, 3, 24),
  //('Winter Overture', 19, 3, 25),
  //('Southern Hospitality', 83, 3, 26),
  //('Fear', 147, 3, 27),
  //('Full Tense', 64, 3, 28),
  //('The Beginning of the End', 269, 3, 29),
  //('Ghosts of a Future Lost', 115, 3, 30),
  //('Meltdown', 236, 3, 31),
  //('Lux Aeterna', 234, 3, 32),
  //('Coney Island Low', 134, 3, 33);
  //`);
}

exports.down = pgm => {
  pgm.dropFunction('search', ['text'])
  pgm.dropFunction('composer_full_name', ['composer'])

  pgm.dropTable('track_composer')
  pgm.dropTable('track')
  pgm.dropTable('soundtrack_composer')
  pgm.dropTable('soundtrack')
  pgm.dropTable('composer')

  pgm.dropType('soundtrack_type')
}
