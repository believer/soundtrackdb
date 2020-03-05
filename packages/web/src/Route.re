type t =
  | Index
  | AddSoundtrack
  | Soundtrack(string)
  | Composer(string)
  | Stats;

let toString =
  fun
  | Index => "/"
  | AddSoundtrack => "/add"
  | Soundtrack(id) => "/soundtrack/" ++ id
  | Composer(id) => "/composer/" ++ id
  | Stats => "/stats";

let go = path => path->toString->ReasonReactRouter.push;

let getPath = path =>
  switch (path) {
  | [] => Some(Index)
  | ["add"] => Some(AddSoundtrack)
  | ["soundtrack", id] => Some(Soundtrack(id))
  | ["composer", id] => Some(Composer(id))
  | ["stats"] => Some(Stats)
  | _ => None
  };
