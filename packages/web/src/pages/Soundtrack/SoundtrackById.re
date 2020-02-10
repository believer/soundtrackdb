module SoundtrackByIdQuery = [%relay.query
  {|
  query SoundtrackByIdQuery($id: ID!) {
    soundtrack(id: $id) {
    releaseYear
      title
      ...Composer_soundtrack
      ...TrackList_soundtrack
    }
  }
|}
];

[@react.component]
let make = (~id) => {
  let query = SoundtrackByIdQuery.use(~variables={id: id}, ());

  <div className="grid grid-template-960 my-20">
    {switch (query.soundtrack) {
     | Some({title, releaseYear} as node) =>
       <div className="grid-column-center">
         <div className="text-sm text-gray-600 mb-2">
           <DateTime date=releaseYear />
         </div>
         <h1 className="text-4xl text-gray-900 font-black">
           {React.string(title)}
         </h1>
         <Composer query={node.getFragmentRefs()} />
         <TrackList query={node.getFragmentRefs()} />
       </div>
     | None => React.null
     }}
  </div>;
};
