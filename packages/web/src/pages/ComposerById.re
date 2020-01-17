module ComposerByIdQuery = [%relay.query
  {|
  query ComposerByIdQuery($id: ID!) {
    composer(id: $id) {
      fullName
      soundtrackComposersByComposerId {
        edges {
          node {
            soundtrackBySoundtrackId {
              id
              title
            }
          }
        }
      }
    }
  }
|}
];

[@react.component]
let make = (~id) => {
  let query = ComposerByIdQuery.use(~variables={id: id}, ());

  <div className="grid grid-template-960 mt-12">
    {switch (query.composer) {
     | Some({fullName, soundtrackComposersByComposerId}) =>
       <div className="grid-column-center">
         {React.string(fullName->Belt.Option.getWithDefault(""))}
         {soundtrackComposersByComposerId.edges
          ->Belt.Array.map(({node}) => {
              switch (node) {
              | Some({soundtrackBySoundtrackId}) =>
                switch (soundtrackBySoundtrackId) {
                | Some({id, title}) =>
                  <div key=id> {React.string(title)} </div>
                | None => React.null
                }
              | None => React.null
              }
            })
          ->React.array}
       </div>
     | None => React.null
     }}
  </div>;
};
