open Jest;
open Expect;

describe("Parse", () => {
  test("handles empty string", () => {
    DateTime.Parse.make("") |> expect |> toEqual("")
  });

  test("handles YYYY-MM-DD", () => {
    DateTime.Parse.make("2020-11-12") |> expect |> toEqual("2020-11-12")
  });

  test("handles MMMM DD, YYYY", () => {
    DateTime.Parse.make("October 27, 2020")
    |> expect
    |> toEqual("2020-10-27")
  });

  test("handles DD MMMM, YYYY", () => {
    DateTime.Parse.make("29 May, 2020") |> expect |> toEqual("2020-05-29")
  });

  test("handles lowercase", () => {
    DateTime.Parse.make("21 march 2020") |> expect |> toEqual("2020-03-21")
  });
});
