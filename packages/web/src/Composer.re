module ComposerFragment = [%relay.fragment
  {|
  fragment Composer_soundtrack on Soundtrack {
    soundtrackComposers {
      edges {
        node {
          composer {
            fullName
            id
          }
        }
      }
    }
  }
|}
];

[@react.component]
let make = (~query as queryRef) => {
  let composer = ComposerFragment.use(queryRef);

  composer.soundtrackComposers.edges
  ->Belt.Array.map(composer => {
      switch (composer.node) {
      | Some({composer}) =>
        switch (composer) {
        | Some({id, fullName}) =>
          <Link.Internal
            key=id
            path={Route.Composer(id)}
            className="mr-1 text-gray-600 text-sm">
            {React.string(fullName->Belt.Option.getWithDefault(""))}
          </Link.Internal>
        | None => React.null
        }
      | None => React.null
      }
    })
  ->React.array;
};
