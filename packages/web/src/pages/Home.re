module Query = [%relay.query
  {|
  query HomeQuery {
    ...Soundtracks_query
  }
|}
];

[@react.component]
let make = () => {
  let query = Query.use(~variables=(), ());

  <div className="grid grid-template-960 mt-12">
    <Soundtracks query={query.getFragmentRefs()} />
  </div>;
};