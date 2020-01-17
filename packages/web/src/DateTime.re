external datetimeToString: ReasonRelay.any => string = "%identity";

[@react.component]
let make = (~date) => {
  let year =
    date |> datetimeToString |> Js.Date.fromString |> Js.Date.getFullYear;

  year->Belt.Float.toString->React.string;
};
