open Jest;
open Expect;

test("it handles spotify id with only id", () => {
  SpotifyId.make("7q18n1Pnq7mx6satptDoJ3")
  |> expect
  |> toEqual(Some("7q18n1Pnq7mx6satptDoJ3"))
});

test("it handles spotify id as URI", () => {
  SpotifyId.make("spotify:album:7q18n1Pnq7mx6satptDoJ3")
  |> expect
  |> toEqual(Some("7q18n1Pnq7mx6satptDoJ3"))
});

test("it handles spotify id as URL", () => {
  SpotifyId.make(
    "https://open.spotify.com/album/2BWSDz2lMwJnxxwDuy8WP0?si=u0CvLKm0THqGN0-rHSenLA",
  )
  |> expect
  |> toEqual(Some("2BWSDz2lMwJnxxwDuy8WP0"))
});
