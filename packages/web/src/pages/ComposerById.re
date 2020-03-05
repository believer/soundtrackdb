module ComposerByIdQuery = [%relay.query
  {|
  query ComposerByIdQuery($id: ID!) {
    composerById(id: $id) {
      fullName
      soundtrackComposers(orderBy: SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_YEAR_DESC) {
        edges {
          node {
            soundtrack {
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

  <div className="grid grid-template-1140 my-20">
    {switch (query.composerById) {
     | Some({fullName, soundtrackComposers}) =>
       <div className="grid-column-center">
         <ul className="flex mb-8 breadcrumbs">
           <li className="font-bold text-gray-600">
             <Link.Internal path=Route.Index>
               {React.string("Soundtracks")}
             </Link.Internal>
           </li>
           <li className="text-gray-600">
             {React.string(fullName->Belt.Option.getWithDefault(""))}
           </li>
         </ul>
         <h1 className="text-4xl text-gray-900 font-black">
           {React.string(fullName->Belt.Option.getWithDefault(""))}
         </h1>
         <div className="grid grid-template-soundtrack grid-gap-20 mt-8">
           <ul>
             {soundtrackComposers.edges
              ->Belt.Array.map(({node}) => {
                  switch (node) {
                  | Some({soundtrack}) =>
                    switch (soundtrack) {
                    | Some({id, title, releaseYear}) =>
                      <Link.Internal path={Route.Soundtrack(id)} key=id>
                        <li
                          className="py-3 border-b border-gray-300 flex items-center justify-between">
                          {React.string(title)}
                          <div
                            className="text-right text-sm text-gray-500
                            font-variant-tabular">
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
             <MetaBlock title="Number of soundtracks">
               {soundtrackComposers.totalCount->Belt.Int.toString->React.string}
             </MetaBlock>
           </div>
         </div>
       </div>
     | None => React.null
     }}
  </div>;
};
