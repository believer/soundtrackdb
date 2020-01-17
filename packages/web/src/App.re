[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let route = Route.getPath(url.path);

  switch (route) {
  | Some(Index) => <Home />
  | Some(Composer(id)) => <ComposerById id />
  | None => <div> {React.string("404")} </div>
  };
};
