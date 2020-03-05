module Query = [%relay.query
  {|
  query HomeQuery {
    ...Soundtracks_query
    ...LatestSoundtracks_soundtracks
  }
|}
];

[@react.component]
let make = () => {
  let query = Query.use(~variables=(), ());

  <div className="grid grid-template-1140 my-20">
    <div className="grid-column-center">
      <div className="grid grid-template-soundtrack grid-gap-20 items-start">
        <div> <Soundtracks query={query.getFragmentRefs()} /> </div>
        <LatestSoundtracks query={query.getFragmentRefs()} />
      </div>
    </div>
  </div>;
};
