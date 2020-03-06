module Item: {
  type t;
  type view = {
    label: string,
    value: string,
  };

  let view: t => view;
  let make: (~label: string, ~value: string) => t;
} = {
  type t = {
    label: string,
    value: string,
  };

  type view = {
    label: string,
    value: string,
  };

  let view: t => view = t => {label: t.label, value: t.value};

  let make: (~label: string, ~value: string) => t =
    (~label, ~value) => {label, value};
};

[@react.component]
let make = (~options: list(Item.t), ~onChange, ~value) => {
  <div className="relative">
    <select
      className="block appearance-none w-full bg-white border text-gray-700
               border-gray-400 hover:border-gray-500 px-4 py-2 pr-8 rounded
               leading-tight focus:outline-none focus:shadow-outline"
      onChange
      value>
      {options
       ->Belt.List.map(Item.view)
       ->Belt.List.map(({label, value}) => {
           <option key=label value> {React.string(label)} </option>
         })
       ->Belt.List.toArray
       ->React.array}
    </select>
    <div
      className="pointer-events-none absolute inset-y-0 right-0 flex items-center px-2 text-gray-700">
      <svg
        className="w-5 h-5"
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 64 64"
        ariaLabelledby="title"
        ariaDescribedby="desc">
        <path
          fill="none"
          stroke="#1A202C"
          strokeMiterlimit="10"
          strokeWidth="2"
          d="M20 26l11.994 14L44 26"
          strokeLinejoin="round"
          strokeLinecap="round"
        />
      </svg>
    </div>
  </div>;
};
