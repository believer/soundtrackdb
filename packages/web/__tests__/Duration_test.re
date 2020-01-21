open Jest;
open Duration;
open Expect;

describe("#make", () => {
  test("returns time with h:min:s", () =>
    expect(make(5000)) |> toEqual("1:23:20")
  );

  test("returns time with min:s", () =>
    expect(make(500)) |> toEqual("8:20")
  );

  test("returns time with min:s", () =>
    expect(make(65)) |> toEqual("1:05")
  );

  test("returns time with 0:s", () =>
    expect(make(50)) |> toEqual("0:50")
  );

  test("returns when seconds are super close to 60", () =>
    expect(make(59)) |> toEqual("0:59")
  );

  test("returns when seconds are exactly 60", () =>
    expect(make(60)) |> toEqual("1:00")
  );

  test("returns when minutes are super close to 60", () =>
    expect(make(3599)) |> toEqual("59:59")
  );

  test("returns when minutes are exactly 60", () =>
    expect(make(3600)) |> toEqual("1:00:00")
  );
});

describe("#fromString", () => {
  test("parses time from seconds", () => {
    fromString("0:50") |> expect |> toEqual(50)
  });

  test("parses time from seconds and minutes", () => {
    fromString("1:50") |> expect |> toEqual(110)
  });

  test("handles exact time", () => {
    fromString("2:00") |> expect |> toEqual(120)
  });

  test("parses time from seconds, minutes and hours", () => {
    fromString("1:10:50") |> expect |> toEqual(4250)
  });

  test("defaults to zero", () => {
    fromString("0:00") |> expect |> toEqual(0)
  });
});
