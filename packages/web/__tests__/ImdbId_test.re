open Jest;
open Expect;

test("it handles IMDb id with only id", () => {
  ImdbId.make("tt2592614") |> expect |> toEqual(Some("tt2592614"))
});

test("it handles IMDb id as URL", () => {
  ImdbId.make("https://www.imdb.com/title/tt2592614/?ref_=nv_sr_srsg_0")
  |> expect
  |> toEqual(Some("tt2592614"))
});

test("it handles IMDb id as URL without params", () => {
  ImdbId.make("https://www.imdb.com/title/tt2592614")
  |> expect
  |> toEqual(Some("tt2592614"))
});
