module ComposerByIdQuery = [%relay.query
  {|
  query ComposerByIdQuery($id: ID!) {
    composer(id: $id) {
      fullName
      soundtrackComposersByComposerId(orderBy: SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_YEAR_DESC) {
        edges {
          node {
            soundtrackBySoundtrackId {
              id
              title
              releaseYear
            }
          }
        }
        totalCount
      }
    }
  }
|}
];

[@react.component]
let make = (~id) => {
  let query = ComposerByIdQuery.use(~variables={id: id}, ());

  <div className="grid grid-template-960 my-20">
    {switch (query.composer) {
     | Some({fullName, soundtrackComposersByComposerId}) =>
       <div className="grid-column-center">
         <h1 className="text-4xl text-gray-900 font-black">
           {React.string(fullName->Belt.Option.getWithDefault(""))}
         </h1>
         <div className="grid grid-template-soundtrack grid-gap-20 mt-8">
           <ul>
             {soundtrackComposersByComposerId.edges
              ->Belt.Array.map(({node}) => {
                  switch (node) {
                  | Some({soundtrackBySoundtrackId}) =>
                    switch (soundtrackBySoundtrackId) {
                    | Some({id, title, releaseYear}) =>
                      <Link.Internal path={Route.Soundtrack(id)} key=id>
                        <li
                          className="py-3 border-b border-gray-300 flex items-center justify-between">
                          {React.string(title)}
                          <div className="text-right text-sm text-gray-500">
                            <DateTime date=releaseYear />
                          </div>
                        </li>
                      </Link.Internal>
                    | None => React.null
                    }
                  | None => React.null
                  }
                })
              ->React.array}
           </ul>
           <div>
             <h2 className="font-bold text-gray-800 mb-1">
               {React.string("Number of soundtracks")}
             </h2>
             <div className="text-gray-600 mb-4">
               {soundtrackComposersByComposerId.totalCount
                ->Belt.Int.toString
                ->React.string}
             </div>
           </div>
         </div>
       </div>
     | None => React.null
     }}
  </div>;
};
