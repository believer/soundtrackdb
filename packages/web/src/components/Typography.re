module H1 = {
  [@react.component]
  let make = (~children) => {
    <h1 className="font-black text-4xl text-gray-900"> children </h1>;
  };
};

module H2 = {
  [@react.component]
  let make = (~children) => {
    <h2 className="font-bold text-gray-800 mb-1"> children </h2>;
  };
};
