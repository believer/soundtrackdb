module LatestSoundtracksFragment = [%relay.fragment
  {|
  fragment LatestSoundtracks_soundtracks on Query {
    latestSoundtracks: soundtracks(orderBy: CREATED_AT_DESC, first: 10) {
      edges {
        node {
          createdAt
          id
          title
          ...Composer_soundtrack
        }
      }
    }
  }
|}
];

[@react.component]
let make = (~query as queryRef) => {
  let data = LatestSoundtracksFragment.use(queryRef);

  <div className="bg-gray-100 rounded p-8">
    <Typography.H2> {React.string("Latest additions")} </Typography.H2>
    <div className="mt-4">
      {switch (data.latestSoundtracks) {
       | Some({edges}) =>
         edges
         ->Belt.Array.map(soundtrack => {
             switch (soundtrack.node) {
             | Some({title, id, createdAt} as node) =>
               <Link.Internal key=id path={Route.Soundtrack(id)}>
                 <div className="mb-2">
                   <div className="text-xs text-gray-500">
                     <DateTime
                       date=createdAt
                       format=DateTime.Format.FullDate
                     />
                   </div>
                   <div className="font-bold text-gray-800 text-sm">
                     {React.string(title)}
                   </div>
                   <div> <Composer query={node.getFragmentRefs()} /> </div>
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
