module StatsQuery = [%relay.query
  {|
  query StatsQuery {
    ...StatsBigNumbers
    stats {
      ...StatsComposers_composers
      ...StatsYears_years
      ...StatsCategories_categories
    }
  }
|}
];

[@react.component]
let make = () => {
  let query = StatsQuery.use(~variables=(), ());

  <div className="grid grid-template-1140 my-20">
    <div className="grid-column-center">
      <StatsBigNumbers query={query.getFragmentRefs()} />
      <StatsCategories query={query.stats.getFragmentRefs()} />
      <StatsComposers query={query.stats.getFragmentRefs()} />
      <StatsYears query={query.stats.getFragmentRefs()} />
    </div>
  </div>;
};
