[@react.component]
let make = (~date) => {
  let year = date |> Js.Date.fromString |> Js.Date.getFullYear;

  year->Belt.Float.toString->React.string;
};