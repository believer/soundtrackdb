open BsRecharts;

module YearsFragment = [%relay.fragment
  {|
  fragment StatsYears_years on Stats {
    years {
      year
      count
    }
  }
|}
];

[@react.component]
let make = (~query as queryRef) => {
  let data = YearsFragment.use(queryRef);

  <div className="mt-12">
    <ResponsiveContainer height={Px(300.)} width={Prc(100.)}>
      <LineChart
        margin={"top": 20, "right": 30, "bottom": 20, "left": 0}
        data={data.years}>
        <CartesianGrid stroke="#eee" strokeDasharray="5 5" />
        <XAxis dataKey="year" />
        <YAxis dataKey="count" interval={Num(0)} />
        <Line
          name="Soundtracks per year"
          dataKey="count"
          stroke="#718096"
          _type=`monotone
        />
        <Tooltip />
        <Legend align=`center />
      </LineChart>
    </ResponsiveContainer>
  </div>;
};
