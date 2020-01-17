/* eslint-disable camelcase */

exports.shorthands = undefined;

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
  "soundtrack_id" int NOT NULL
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
  "composer_id" int NOT NULL
);

ALTER TABLE "soundtrack_composer" ADD FOREIGN KEY ("composer_id") REFERENCES "composer" ("id");

ALTER TABLE "soundtrack_composer" ADD FOREIGN KEY ("soundtrack_id") REFERENCES "soundtrack" ("id");

ALTER TABLE "track" ADD FOREIGN KEY ("soundtrack_id") REFERENCES "soundtrack" ("id");

ALTER TABLE "track_composer" ADD FOREIGN KEY ("track_id") REFERENCES "track" ("id");

ALTER TABLE "track_composer" ADD FOREIGN KEY ("composer_id") REFERENCES "composer" ("id");
  `);

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
  `);

  pgm.sql(`
    INSERT INTO composer (first_name, last_name) VALUES ('Thomas', 'Newman');
    INSERT INTO composer (first_name, last_name) VALUES ('Clint', 'Mansell');
    INSERT INTO composer (first_name, last_name) VALUES ('Kronos', 'Quartet');

    -- The Fountain
    INSERT INTO soundtrack (title, imdb_id, soundtrack_type, release_year) VALUES ('The Fountain', 'tt0414993', 'movie', '2006-11-27');
    INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (2, 1);
    INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (3, 1);

    -- Tracks
    INSERT INTO track (title, duration, soundtrack_id, track_number) VALUES
      ('The Last Man', 369, 1, 1),
      ('Holy Dread!', 232, 1, 2),
      ('Tree of Life', 225, 1, 3),
      ('Stay with Me', 216, 1, 4),
      ('Death Is a Disease', 154, 1, 5),
      ('Xibalba', 323, 1, 6),
      ('First Snow', 189, 1, 7),
      ('Finish It', 265, 1, 8),
      ('Death Is the Road to Awe', 506, 1, 9),
      ('Together We Will Live Forever', 302, 1, 10);

    -- Add Kronos Quartet to some tracks
    INSERT INTO track_composer (track_id, composer_id) VALUES
      (2, 3),
      (3, 3),
      (4, 3),
      (6, 3),
      (7, 3),
      (8, 3),
      (9, 3);

    -- 1917
    INSERT INTO soundtrack (title, imdb_id, soundtrack_type, release_year) VALUES ('1917', 'tt8579674', 'movie', '2019-12-20');
    INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (1,2);
    INSERT INTO track (title, duration, soundtrack_id, track_number) VALUES ('1917', 77, 2, 1);

    -- Requiem for a Dream
    INSERT INTO soundtrack (title, imdb_id, soundtrack_type, release_year) VALUES ('Requiem for a Dream', 'tt0180093', 'movie', '2000-05-14');
    INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (2, 3);
    INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (3, 3);

    INSERT INTO track (title, duration, soundtrack_id, track_number) VALUES
      ('Summer Overture', 157, 3, 1);
  `);
};

exports.down = pgm => {
  pgm.dropFunction("search", ["text"]);
  pgm.dropFunction("composer_full_name", ["composer"]);

  pgm.dropTable("track_composer");
  pgm.dropTable("track");
  pgm.dropTable("soundtrack_composer");
  pgm.dropTable("soundtrack");
  pgm.dropTable("composer");

  pgm.dropType("soundtrack_type");
};
