/* eslint-disable camelcase */

exports.up = pgm => {
  pgm.sql(`
    INSERT INTO composer (first_name, last_name) VALUES ('Hans', 'Zimmer');

    -- The Fountain
    INSERT INTO soundtrack (title, imdb_id, soundtrack_type, release_year) VALUES ('Inception', 'tt1375666', 'movie', '2010-07-13');
    INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (4, 4);

    -- Tracks
    INSERT INTO track (title, duration, soundtrack_id, track_number) VALUES
      ('Half Remembered Dream', 72, 4, 1),
      ('We Build Our Own World', 116, 4, 2),
      ('Dream Is Collapsing', 144, 4, 3),
      ('Radical Notion', 223, 4, 4),
      ('Old Souls', 464, 4, 5),
      ('528491', 144, 4, 6),
      ('Mombasa', 294, 4, 7),
      ('One Simple Idea', 148, 4, 8),
      ('Dream Within a Dream', 304, 4, 9),
      ('Waiting for a Train', 570, 4, 10),
      ('Paradox', 205, 4, 11),
      ('Time', 276, 4, 12);

    -- The Legend Of Iya
    INSERT INTO composer (first_name) VALUES ('Philter');

    INSERT INTO soundtrack (title, soundtrack_type, release_year) VALUES ('The Legend Of Iya', 'game', '2014-09-05');
    INSERT INTO soundtrack_composer (composer_id, soundtrack_id) VALUES (5, 5);

    -- Tracks
    INSERT INTO track (title, duration, soundtrack_id, track_number) VALUES
      ('The Legens Of Iya', 156, 5, 1),
      ('Dance Of The Fireflies', 181, 5, 2),
      ('Forest Of Wonder', 202, 5, 3),
      ('Lotus Land', 186, 5, 4),
      ('Back To Yesterday', 194, 5, 5),
      ('A Quest Unfolds', 207, 5, 6),
      ('Robotic Wings', 192, 5, 7),
      ('Safe', 101, 5, 8),
      ('Neverland', 184, 5, 9),
      ('Strange Noises', 198, 5, 10),
      ('Song Of Sirens', 178, 5, 11),
      ('The Ocean Floor', 205, 5, 12),
      ('Staring At The Moon', 108, 5, 13),
      ('Chant Of The Wild', 200, 5, 14),
      ('Spiked Bat', 154, 5, 15),
      ('Battle Scars', 178, 5, 16),
      ('Iya Sleeps', 126, 5, 17),
      ('Below The Surface', 204, 5, 18),
      ('Remembering Home', 81, 5, 19),
      ('Slow Motion', 182, 5, 20),
      ('Robotropolis', 193, 5, 21),
      ('Goosebumps', 165, 5, 22),
      ('Howl', 205, 5, 23),
      ('Panic Attack', 214, 5, 24),
      ('The Story Of A Girl', 192, 5, 25);
  `);
};

exports.down = pgm => {
  pgm.sql(`DELETE FROM soundtrack WHERE id = 4 AND id = 5`);
  pgm.sql(`DELETE FROM composer WHERE id = 4 AND id = 5`);
};
