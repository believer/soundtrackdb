module StatsCategoriesFragment = [%relay.fragment
  {|
  fragment StatsCategories_categories on Stats {
    categories {
      movie
      game
      tv
    }
  }
|}
];

[@react.component]
let make = (~query as queryRef) => {
  let data = StatsCategoriesFragment.use(queryRef);

  <div className="flex mt-12">
    <StatsCategoryBlock stat={data.categories.movie} title="Movie" />
    <StatsCategoryBlock stat={data.categories.tv} title="TV" />
    <StatsCategoryBlock stat={data.categories.game} title="Game" />
  </div>;
};
