module Format = {
  type t =
    | Year
    | FullDate;
};

module Parse = {
  open Js.Date;

  let make = date => {
    switch (date) {
    | "" => ""
    | _ =>
      let parsedDate = fromString(date);

      parsedDate->getFullYear->Belt.Float.toString
      ++ "-"
      ++ (parsedDate->getMonth +. 1.)->Duration.LeadingZero.add
      ++ "-"
      ++ parsedDate->getDate->Duration.LeadingZero.add;
    };
  };
};

[@react.component]
let make = (~date, ~format=Format.Year) => {
  let parsedDate = date |> Js.Date.fromString;

  let date =
    switch (format) {
    | Year => parsedDate |> Js.Date.getFullYear |> Belt.Float.toString
    | FullDate => Parse.make(date)
    };

  date->React.string;
};
