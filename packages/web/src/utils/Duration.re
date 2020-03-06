let cleanFloat = value => value |> int_of_float |> string_of_int;

module TrackDuration = {
  [@bs.module "track-duration"] external parse: int => string = "parse";
};

let make = value => (value * 1000)->TrackDuration.parse;

module LeadingZero = {
  let add = value =>
    switch (value) {
    | v when v < 10. => "0" ++ value->cleanFloat
    | _ => value->cleanFloat
    };
};

let fromString = time => {
  switch (time->Js.String2.split(":")->Belt.Array.map(Belt.Int.fromString)) {
  | [|Some(0), Some(s)|] => s
  | [|Some(m), Some(s)|] => m * 60 + s
  | [|Some(h), Some(m), Some(s)|] => h * 3600 + m * 60 + s
  | _ => 0
  };
};

module Long = {
  module Minutes = {
    let make = (d, h, s) => s /. 60.0 -. 60.0 *. h -. d *. 24. *. 60.;
  };

  module Seconds = {
    let make = seconds =>
      (mod_float(seconds /. 60.0, 1.0) *. 60.0)
      ->Js.Math.round
      ->LeadingZero.add;
  };

  let make = seconds => {
    let seconds = seconds->float_of_int;
    Js.log(seconds);
    let d = floor(seconds /. (3600.0 *. 24.));
    let h = floor(seconds /. 3600.0) -. d *. 24.;

    let s = Seconds.make(seconds);
    let min = Minutes.make(d, h, seconds);

    switch (d, h, min, s) {
    | (0.0, 0.0, min, s) => min->cleanFloat ++ ":" ++ s
    | (0.0, h, min, s) =>
      h->cleanFloat ++ ":" ++ LeadingZero.add(min) ++ ":" ++ s
    | (d, h, min, s) =>
      d->cleanFloat
      ++ (
        switch (d) {
        | 1.0 => " day "
        | _ => " days "
        }
      )
      ++ h->cleanFloat
      ++ " h "
      ++ LeadingZero.add(min)
      ++ " min "
      ++ s
      ++ " s"
    };
  };
};
