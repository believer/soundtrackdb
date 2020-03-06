type t =
  | Index
  | AddSoundtrack
  | Soundtrack(string)
  | Composer(string)
  | Year(string)
  | Stats;

let toString =
  fun
  | Index => "/"
  | AddSoundtrack => "/add"
  | Soundtrack(id) => "/soundtrack/" ++ id
  | Composer(id) => "/composer/" ++ id
  | Year(year) => "/year/" ++ year
  | Stats => "/stats";

let go = path => path->toString->ReasonReactRouter.push;

let getPath = path =>
  switch (path) {
  | [] => Some(Index)
  | ["add"] => Some(AddSoundtrack)
  | ["stats"] => Some(Stats)
  | ["soundtrack", id] => Some(Soundtrack(id))
  | ["composer", id] => Some(Composer(id))
  | ["year", year] => Some(Year(year))
  | _ => None
  };
