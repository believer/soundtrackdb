module TrackListFragment = [%relay.fragment
  {|
  fragment Soundtracks_query on Query {
    allSoundtracks(orderBy: TITLE_ASC) {
      edges {
        node {
          id
          title
          ...TrackList_soundtrack
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
           | Some({title, id} as node) =>
             <div className="mb-10" key=id>
               <h2 className="text-xl font-black"> {React.string(title)} </h2>
               <Composer query={node->TrackListFragment.unwrapFragment_node} />
               <TrackList
                 query={node->TrackListFragment.unwrapFragment_node}
               />
             </div>
           | None => React.null
           }
         })
       ->React.array}
    </div>
  | None => React.null
  };
};
