[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = Route.getPath(url.path);

  switch (route) {
  | Some(Index) => <Home />
  | Some(Composer(id)) => <ComposerById id />
  | Some(Soundtrack(id)) => <SoundtrackById id />
  | Some(AddSoundtrack) => <AddSoundtrack />
  | Some(Stats) => <Stats />
  | None => <div> {React.string("404")} </div>
  };
};
