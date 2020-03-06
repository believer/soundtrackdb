module Primary = {
  [@react.component]
  let make = (~children, ~leading=?, ~onClick=?, ~type_="button") => {
    <button
      type_
      className="bg-blue-500 text-white rounded border border-blue-500 flex
      items-center py-2 px-4 focus:outline-none"
      ?onClick>
      {switch (leading) {
       | Some(leading) => <span className="mr-2"> leading </span>
       | None => React.null
       }}
      children
    </button>;
  };
};

module Secondary = {
  [@react.component]
  let make = (~children, ~leading=?, ~onClick=?, ~type_="button") => {
    <button
      type_
      className="bg-white text-blue-500 rounded border border-blue-500 flex
      items-center py-2 px-4 hover:bg-blue-500 hover:text-white focus:outline-none"
      ?onClick>
      {switch (leading) {
       | Some(leading) => <span className="mr-2"> leading </span>
       | None => React.null
       }}
      children
    </button>;
  };
};
