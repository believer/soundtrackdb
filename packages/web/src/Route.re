type t =
  | Index
  | AddSoundtrack
  | Composer(string);

let toString =
  fun
  | Index => "/"
  | AddSoundtrack => "/add"
  | Composer(id) => "/composer/" ++ id;

let go = path => path->toString->ReasonReactRouter.push;

let getPath = path =>
  switch (path) {
  | [] => Some(Index)
  | ["add"] => Some(AddSoundtrack)
  | ["composer", id] => Some(Composer(id))
  | _ => None
  };
