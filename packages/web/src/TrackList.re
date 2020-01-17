module Fragment = [%relay.fragment
  {|
  fragment TrackList_soundtrack on Soundtrack {
    releaseYear
    soundtrackType
    tracksBySoundtrackId(orderBy: TRACK_NUMBER_ASC) {
      totalCount
      edges {
        node {
          id
          title
          duration
          trackNumber
          trackComposersByTrackId {
            totalCount
            edges {
              node {
                composerByComposerId {
                  fullName
                }
              }
            }
          }
        }
      }
    }
  }
|}
];

module Style = {
  open Css;

  let trackListRow =
    merge([
      "grid odd:bg-gray-100 px-2 py-1 items-center",
      style([gridTemplateColumns([`px(40), `fr(1.0), `px(100)])]),
    ]);
};

[@react.component]
let make = (~query as queryRef) => {
  let trackList = Fragment.use(queryRef);

  <>
    <div className="text-sm text-gray-600 flex justify-between">
      <div>
        <DateTime date={trackList.releaseYear} />
        {switch (trackList.tracksBySoundtrackId.totalCount) {
         | 0 => React.null
         | 1 => " ~ 1 track ~ "->React.string
         | l => " ~ " ++ l->Belt.Int.toString ++ " tracks ~ " |> React.string
         }}
        {trackList.tracksBySoundtrackId.edges
         ->Belt.Array.reduce(0, (acc, track) => {
             switch (track.node) {
             | Some({duration}) => acc + duration
             | None => acc
             }
           })
         ->Duration.make
         ->React.string}
      </div>
      <div>
        {switch (trackList.soundtrackType) {
         | `MOVIE => <div className="rounded-full bg-blue-200 h-4 w-4" />
         | `GAME => <div className="rounded-full bg-green-200 h-4 w-4" />
         | `FUTURE_ADDED_VALUE__ => <div> {React.string("Unknown")} </div>
         }}
      </div>
    </div>
    <ul className="mt-6">
      {trackList.tracksBySoundtrackId.edges
       ->Belt.Array.map(track => {
           switch (track.node) {
           | Some({title, id, duration, trackNumber, trackComposersByTrackId}) =>
             <li className=Style.trackListRow key=id>
               <div className="text-gray-700">
                 {React.string(trackNumber->string_of_int)}
               </div>
               <div id="test">
                 {React.string(title)}
                 {switch (trackComposersByTrackId.totalCount) {
                  | 0 => React.null
                  | _ =>
                    let allComposers =
                      trackComposersByTrackId.edges
                      ->Belt.Array.map(composer => {
                          switch (composer.node) {
                          | Some({composerByComposerId}) =>
                            switch (composerByComposerId) {
                            | Some({fullName}) =>
                              fullName->Belt.Option.getWithDefault("")
                            | None => ""
                            }
                          | None => ""
                          }
                        })
                      ->Js.Array2.joinWith(", ");

                    <span className="text-gray-600 ml-4 text-sm">
                      {React.string(allComposers)}
                    </span>;
                  }}
               </div>
               <div className="text-right text-sm text-gray-600">
                 {React.string(Duration.make(duration))}
               </div>
             </li>
           | None => React.null
           }
         })
       ->React.array}
    </ul>
  </>;
};
