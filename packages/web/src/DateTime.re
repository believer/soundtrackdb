external fromDateTime: ReasonRelay.any => string = "%identity";
external toDateTime: string => ReasonRelay.any = "%identity";

[@react.component]
let make = (~date) => {
  let year = date |> fromDateTime |> Js.Date.fromString |> Js.Date.getFullYear;

  year->Belt.Float.toString->React.string;
};
