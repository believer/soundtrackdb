module TrackDuration = {
  [@bs.module "track-duration"] external parse: int => string = "parse";
};

let make = value => (value * 1000)->TrackDuration.parse;

module LeadingZero = {
  let cleanFloat = value => value |> int_of_float |> string_of_int;

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
