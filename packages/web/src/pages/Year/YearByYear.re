module YearByYearQuery = [%relay.query
  {|
    query YearByYearQuery($condition: SoundtrackCondition) {
      soundtracks(condition: $condition) {
        edges {
          node {
            id
            title
            releaseDate
            ...Composer_soundtrack
          }
        }
      }
    }
  |}
];

[@react.component]
let make = (~year) => {
  let query =
    YearByYearQuery.use(
      ~variables={
        condition:
          Some({
            year: Some(year),
            rowId: None,
            title: None,
            imdbId: None,
            soundtrackType: None,
            releaseDate: None,
            createdAt: None,
            updatedAt: None,
            spotifyId: None,
          }),
      },
      (),
    );

  <div className="grid grid-template-1140 my-12">
    <div className="grid-column-center">
      {switch (query.soundtracks) {
       | Some({edges}) =>
         edges
         ->Belt.Array.map(({node}) => {
             switch (node) {
             | Some({title, id, releaseDate} as node) =>
               <Link.Internal key=id path={Route.Soundtrack(id)}>
                 <div
                   className="border-b border-gray-200 grid-template-track-list
                   grid items-center py-4
                   justify-between">
                   <div>
                     <div className="font-bold text-gray-900">
                       {React.string(title)}
                     </div>
                     <Composer query={node.getFragmentRefs()} />
                   </div>
                   <div className="text-sm text-gray-600 font-variant-tabular">
                     <DateTime date=releaseDate />
                   </div>
                 </div>
               </Link.Internal>
             | None => React.null
             }
           })
         ->React.array
       | None => React.null
       }}
    </div>
  </div>;
};
