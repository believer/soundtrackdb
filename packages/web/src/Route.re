type t =
  | Index
  | Composer(string);

let toString =
  fun
  | Index => "/"
  | Composer(id) => "/composer/" ++ id;

let go = path => path->toString->ReasonReactRouter.push;

let getPath = path =>
  switch (path) {
  | [] => Some(Index)
  | ["composer", id] => Some(Composer(id))
  | _ => None
  };
