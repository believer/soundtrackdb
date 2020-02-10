module Format = {
  type t =
    | Year
    | FullDate;
};

[@react.component]
let make = (~date, ~format=Format.Year) => {
  let parsedDate = date |> Js.Date.fromString;

  let date =
    switch (format) {
    | Year => parsedDate |> Js.Date.getFullYear |> Belt.Float.toString
    | FullDate =>
      parsedDate->Js.Date.getFullYear->Belt.Float.toString
      ++ "-"
      ++ (parsedDate->Js.Date.getMonth +. 1.)->Duration.LeadingZero.add
      ++ "-"
      ++ parsedDate->Js.Date.getDate->Duration.LeadingZero.add
    };

  date->React.string;
};
