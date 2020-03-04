module H2 = {
  [@react.component]
  let make = (~children) => {
    <h2 className="font-bold text-gray-800 mb-1"> children </h2>;
  };
};
