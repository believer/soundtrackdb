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
         <ul>
           {soundtrackComposersByComposerId.edges
            ->Belt.Array.map(({node}) => {
                switch (node) {
                | Some({soundtrackBySoundtrackId}) =>
                  switch (soundtrackBySoundtrackId) {
                  | Some({id, title}) =>
                    <li>
                      <Link.Internal path={Route.Soundtrack(id)} key=id>
                        {React.string(title)}
                      </Link.Internal>
                    </li>
                  | None => React.null
                  }
                | None => React.null
                }
              })
            ->React.array}
         </ul>
       </div>
     | None => React.null
     }}
  </div>;
};
