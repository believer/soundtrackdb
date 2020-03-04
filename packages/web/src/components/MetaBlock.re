[@react.component]
let make = (~title, ~children) => {
  <>
    <Typography.H2> {React.string(title)} </Typography.H2>
    <div className="text-gray-600 mb-4"> children </div>
  </>;
};
