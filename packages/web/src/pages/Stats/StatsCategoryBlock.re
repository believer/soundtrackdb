[@react.component]
let make = (~title, ~stat) => {
  <div className="text-center flex-1">
    <div className="text-xs text-gray-600"> {React.string(title)} </div>
    <div className="font-bold text-6xl">
      {stat->Belt.Int.toString->React.string}
    </div>
  </div>;
};
