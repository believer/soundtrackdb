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
let make = (~options: list(Item.t), ~onChange) => {
  <div className="relative">
    <select
      className="block appearance-none w-full bg-white border
               border-gray-400 hover:border-gray-500 px-4 py-2 pr-8 rounded shadow
               leading-tight focus:outline-none focus:shadow-outline"
      onChange>
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
        className="fill-current h-4 w-4"
        xmlns="http://www.w3.org/2000/svg"
        viewBox="0 0 20 20">
        <path
          d="M9.293 12.95l.707.707L15.657 8l-1.414-1.414L10 10.828 5.757 6.586 4.343 8z"
        />
      </svg>
    </div>
  </div>;
};
