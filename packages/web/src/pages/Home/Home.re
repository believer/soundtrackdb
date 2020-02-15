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

  <div className="grid grid-template-960 my-20">
    <Soundtracks query={query.getFragmentRefs()} />
  </div>;
};
