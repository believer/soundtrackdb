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
  "imdb_id" text NOT NULL,
  "soundtrack_type" soundtrack_type NOT NULL,
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
  "order" int NOT NULL,
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
