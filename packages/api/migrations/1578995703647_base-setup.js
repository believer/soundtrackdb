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
