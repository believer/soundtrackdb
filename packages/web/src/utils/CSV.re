module Parse = {
  open Belt.List;

  let toString = tracks => {
    switch (length(tracks)) {
    | 0
    | 1 => ""
    | _ =>
      tracks
      ->mapWithIndex((i, (_, Track.{duration, title})) => {
          let index = Belt.Int.toString(i + 1);

          {j|$index;$title;$duration|j};
        })
      ->Belt.List.toArray
      ->Js.Array2.joinWith("\n")
    };
  };

  let make = data => {
    data
    ->Js.String2.split("\n")
    ->fromArray
    ->map(row => row->Js.String2.split(";"))
    ->map(row => {
        switch (row) {
        | [|_, title, duration|] =>
          Some(
            Track.make(
              ~title,
              ~duration=duration->Js.String2.replace("\"", ""),
            ),
          )
        | _ => None
        }
      })
    ->keepMap(track => track);
  };
};

[@react.component]
let make = (~onChange, ~hasTracks, ~value) => {
  let (displayTextarea, toggleTextarea) = Toggle.useToggle();

  <div>
    <button
      className="w-full bg-gray-100 p-2"
      type_="button"
      onClick={_ => toggleTextarea()}>
      {React.string("Add using CSV")}
    </button>
    {switch (displayTextarea) {
     | Display =>
       <textarea
         disabled=hasTracks
         onChange={event => {
           event->ReactEvent.Form.target##value->Parse.make->onChange
         }}
         placeholder="Paste CSV (separated with ;) here"
         className="mt-4 border border-gray-300 w-full p-4 disabled:bg-gray-100"
         value={Parse.toString(value)}
       />
     | Hidden => React.null
     }}
  </div>;
};
