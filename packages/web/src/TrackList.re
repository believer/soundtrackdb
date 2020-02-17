module Fragment = [%relay.fragment
  {|
  fragment TrackList_soundtrack on Soundtrack {
    imdbId
    spotifyId
    releaseYear
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
                    let allComposers =
                      trackComposers.edges
                      ->Belt.Array.map(composer => {
                          switch (composer.node) {
                          | Some({composer}) =>
                            switch (composer) {
                            | Some({fullName}) =>
                              fullName->Belt.Option.getWithDefault("")
                            | None => ""
                            }
                          | None => ""
                          }
                        })
                      ->Js.Array2.joinWith(", ");

                    <span className="text-gray-500 ml-4 text-sm">
                      {React.string(allComposers)}
                    </span>;
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
    <div>
      <h2 className="font-bold text-gray-800 mb-1">
        {React.string("Release date")}
      </h2>
      <div className="text-gray-600 mb-4">
        <DateTime
          date={trackList.releaseYear}
          format=DateTime.Format.FullDate
        />
      </div>
      <h2 className="font-bold text-gray-800 mb-1">
        {React.string("Number of tracks")}
      </h2>
      <div className="text-gray-600 mb-4">
        {trackList.tracks.totalCount->Belt.Int.toString->React.string}
      </div>
      <h2 className="font-bold text-gray-800 mb-1">
        {React.string("Playtime")}
      </h2>
      <div className="text-gray-600 mb-12">
        {trackList.tracks.edges
         ->Belt.Array.reduce(0, (acc, track) => {
             switch (track.node) {
             | Some({duration}) => acc + duration
             | None => acc
             }
           })
         ->Duration.make
         ->React.string}
      </div>
      {switch (trackList.imdbId) {
       | Some(id) =>
         <Link.External
           className="mr-2" href={"https://www.imdb.com/title/" ++ id}>
           {React.string("IMDb")}
         </Link.External>
       | None => React.null
       }}
      {switch (trackList.spotifyId) {
       | Some(id) =>
         <Link.External
           className="mr-2" href={"https://open.spotify.com/album/" ++ id}>
           {React.string("Spotify")}
         </Link.External>
       | None => React.null
       }}
    </div>
  </div>;
};
