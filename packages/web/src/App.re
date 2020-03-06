[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = Route.getPath(url.path);

  <div>
    <Navigation />
    {switch (route) {
     | Some(Index) => <Home />
     | Some(Composer(id)) => <ComposerById id />
     | Some(Soundtrack(id)) => <SoundtrackById id />
     | Some(AddSoundtrack) => <AddSoundtrack />
     | Some(Stats) => <Stats />
     | Some(Year(year)) => <YearByYear year />
     | None => <div> {React.string("404")} </div>
     }}
  </div>;
};
