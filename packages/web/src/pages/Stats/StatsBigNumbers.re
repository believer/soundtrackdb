module StatsBigNumbersFragment = [%relay.fragment
  {|
  fragment StatsBigNumbers on Query {
    soundtracks {
      totalCount
    }
    stats {
      totalDuration
    }
  }
|}
];

[@react.component]
let make = (~query as queryRef) => {
  let data = StatsBigNumbersFragment.use(queryRef);

  <div className="flex">
    {switch (data.soundtracks) {
     | Some({totalCount}) =>
       <StatsCategoryBlock stat=totalCount title="Number of soundtracks" />
     | None => React.null
     }}
    <div className="text-center flex-1">
      <div className="text-xs text-gray-600">
        {React.string("Total duration")}
      </div>
      <div className="font-bold text-6xl">
        {data.stats.totalDuration
         ->Belt.Int.fromFloat
         ->Duration.make
         ->React.string}
      </div>
    </div>
  </div>;
};
