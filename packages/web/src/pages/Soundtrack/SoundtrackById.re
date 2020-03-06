module SoundtrackByIdQuery = [%relay.query
  {|
  query SoundtrackByIdQuery($id: ID!) {
    soundtrackById(id: $id) {
      id
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

  <div className="grid grid-template-1140 my-20">
    {switch (query.soundtrackById) {
     | Some({title} as node) =>
       <div className="grid-column-center">
         <ul className="flex mb-8 breadcrumbs">
           <li className="font-bold text-gray-600">
             <Link.Internal path=Route.Index>
               {React.string("Soundtracks")}
             </Link.Internal>
           </li>
           <li className="text-gray-600"> {React.string(title)} </li>
         </ul>
         <Typography.H1> {React.string(title)} </Typography.H1>
         <Composer query={node.getFragmentRefs()} />
         <TrackList query={node.getFragmentRefs()} />
       </div>
     | None => React.null
     }}
  </div>;
};
