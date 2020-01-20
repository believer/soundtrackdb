[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = Route.getPath(url.path);

  switch (route) {
  | Some(Index) => <Home />
  | Some(Composer(id)) => <ComposerById id />
  | Some(AddSoundtrack) => <AddSoundtrack />
  | None => <div> {React.string("404")} </div>
  };
};
