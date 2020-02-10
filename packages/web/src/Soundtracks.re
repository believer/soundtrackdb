module TrackListFragment = [%relay.fragment
  {|
  fragment Soundtracks_query on Query {
    allSoundtracks(orderBy: TITLE_ASC) {
      edges {
        node {
          id
          title
          releaseYear
          ...Composer_soundtrack
        }
      }
    }
  }
|}
];

[@react.component]
let make = (~query as queryRef) => {
  let soundtracks = TrackListFragment.use(queryRef);

  switch (soundtracks.allSoundtracks) {
  | Some({edges}) =>
    <div className="grid-column-center">
      {edges
       ->Belt.Array.map(soundtrack => {
           switch (soundtrack.node) {
           | Some({title, id, releaseYear} as node) =>
             <Link.Internal path={Route.Soundtrack(id)}>
               <div
                 className="border-b border-gray-200 grid-template-track-list
                 grid items-center py-4
                 justify-between"
                 key=id>
                 <div className="font-black text-gray-800">
                   {React.string(title)}
                 </div>
                 <div> <Composer query={node.getFragmentRefs()} /> </div>
                 <div className="text-sm text-gray-600">
                   <DateTime date=releaseYear />
                 </div>
               </div>
             </Link.Internal>
           | None => React.null
           }
         })
       ->React.array}
    </div>
  | None => React.null
  };
};
