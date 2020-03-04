open Jest;
open Expect;
open CSV;

describe("#Parse", () => {
  test("should parse CSV to a list of tracks", () => {
    let input = {j|"1;The Aldridge Mansion;2:57
2;The Garrett Attack;1:29
3;Never Invited;1:23"|j};

    Parse.make(input)
    |> expect
    |> toEqual([
         Track.{duration: "2:57", title: "The Aldridge Mansion"},
         Track.{duration: "1:29", title: "The Garrett Attack"},
         Track.{duration: "1:23", title: "Never Invited"},
       ]);
  });

  test("can convert back to string", () => {
    let input = [
      (CUID.make(), Track.{duration: "2:57", title: "The Aldridge Mansion"}),
      (CUID.make(), Track.{duration: "1:29", title: "The Garrett Attack"}),
      (CUID.make(), Track.{duration: "1:23", title: "Never Invited"}),
    ];

    let expected = {j|1;The Aldridge Mansion;2:57
2;The Garrett Attack;1:29
3;Never Invited;1:23|j};

    Parse.toString(input) |> expect |> toEqual(expected);
  });
});
