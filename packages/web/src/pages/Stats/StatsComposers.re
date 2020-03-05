open BsRecharts;

module ComposersFragment = [%relay.fragment
  {|
  fragment StatsComposers_composers on Stats {
    composers {
      fullName
      count
    }
  }
|}
];

module CustomLabel = {
  [@react.component]
  let make = (~x, ~y, ~payload) => {
    <g transform={j|translate($x,$y)|j}>
      <text
        x="0"
        y="0"
        dy="16"
        textAnchor="end"
        fill="#666"
        fontSize="11"
        transform="rotate(-35)">
        {payload##value}
      </text>
    </g>;
  };
};

[@react.component]
let make = (~query as queryRef) => {
  let data = ComposersFragment.use(queryRef);

  <div className="mt-12">
    <ResponsiveContainer height={Px(300.)} width={Prc(100.)}>
      <BarChart
        margin={"top": 20, "right": 30, "bottom": 80, "left": 20}
        data={data.composers}>
        <CartesianGrid stroke="#eee" strokeDasharray="5 5" />
        <XAxis
          dataKey="fullName"
          reversed=true
          tick=CustomLabel.make
          interval={Num(0)}
        />
        <YAxis dataKey="count" interval={Num(0)} />
        <Tooltip cursor={"fill": "#F7FAFC"} />
        <Bar dataKey="count" fill="#718096" />
      </BarChart>
    </ResponsiveContainer>
  </div>;
};
