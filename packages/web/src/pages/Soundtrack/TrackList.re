module Fragment = [%relay.fragment
  {|
  fragment TrackList_soundtrack on Soundtrack {
    ...SoundtrackMeta_data
    tracks(orderBy: TRACK_NUMBER_ASC) {
      totalCount
      edges {
        node {
          id
          title
          duration
          trackNumber
          trackComposers {
            totalCount
            edges {
              node {
                composer {
                  id
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
      "grid py-3 items-center border-b border-gray-200",
      style([gridTemplateColumns([`px(40), `fr(1.0), `px(100)])]),
    ]);
};

[@react.component]
let make = (~query as queryRef) => {
  let trackList = Fragment.use(queryRef);

  <div className="grid grid-template-soundtrack grid-gap-20 mt-8">
    <ul>
      {trackList.tracks.edges
       ->Belt.Array.map(track => {
           switch (track.node) {
           | Some({title, id, duration, trackNumber, trackComposers}) =>
             <li className=Style.trackListRow key=id>
               <div className="text-gray-500">
                 {React.string(trackNumber->string_of_int)}
               </div>
               <div className="text-gray-800">
                 {React.string(title)}
                 {switch (trackComposers.totalCount) {
                  | 0 => React.null
                  | _ =>
                    trackComposers.edges
                    ->Belt.Array.map(composer => {
                        switch (composer.node) {
                        | Some({composer}) =>
                          switch (composer) {
                          | Some({fullName, id}) =>
                            <Link.Internal
                              path={Route.Composer(id)}
                              className="text-gray-500 ml-4 text-sm">
                              {React.string(
                                 fullName->Belt.Option.getWithDefault(""),
                               )}
                            </Link.Internal>
                          | None => React.null
                          }
                        | None => React.null
                        }
                      })
                    ->React.array
                  }}
               </div>
               <div className="text-right text-sm text-gray-500">
                 {React.string(Duration.make(duration))}
               </div>
             </li>
           | None => React.null
           }
         })
       ->React.array}
    </ul>
    <SoundtrackMeta
      query={trackList.getFragmentRefs()}
      totalTracks={trackList.tracks.totalCount}
      totalDuration={
        trackList.tracks.edges
        ->Belt.Array.reduce(0, (acc, track) => {
            switch (track.node) {
            | Some({duration}) => acc + duration
            | None => acc
            }
          })
        ->Duration.make
      }
    />
  </div>;
};
