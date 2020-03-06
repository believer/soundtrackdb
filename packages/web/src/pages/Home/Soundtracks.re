module TrackListFragment = [%relay.fragment
  {|
  fragment Soundtracks_query on Query {
    soundtracks(orderBy: TITLE_ASC) {
      edges {
        node {
          id
          title
          releaseDate
          year
          ...Composer_soundtrack
        }
      }
    }
  }
|}
];

type state = {
  soundtracks: array(TrackListFragment.Operation.Types.edges),
  query: string,
};

type action =
  | SetSearch(string)
  | SetSoundtracks(array(TrackListFragment.Operation.Types.edges));

[@react.component]
let make = (~query as queryRef) => {
  let soundtracks = TrackListFragment.use(queryRef);

  let (state, dispatch) =
    React.useReducer(
      (state, action) => {
        switch (action) {
        | SetSoundtracks(soundtracks) => {...state, soundtracks}
        | SetSearch(query) => {...state, query}
        }
      },
      {soundtracks: [||], query: ""},
    );

  React.useEffect0(() => {
    switch (soundtracks.soundtracks) {
    | Some({edges}) => dispatch(SetSoundtracks(edges))
    | None => ()
    };

    None;
  });

  <>
    <div className="rounded-full border-2 border-gray-200 mb-8">
      <input
        className="w-full bg-gray-100 py-2 px-8 pl-12 focus:bg-white rounded-full border-2
        border-gray-100 focus:outline-none focus:border-blue-300"
        type_="text"
        placeholder="Search soundtracks"
        value={state.query}
        style={ReactDOMRe.Style.make(
          ~backgroundImage="url(/assets/icons/search.svg)",
          ~backgroundRepeat="no-repeat",
          ~backgroundSize="20px 20px",
          ~backgroundPosition="16px center",
          (),
        )}
        onChange={event =>
          dispatch(SetSearch(event->ReactEvent.Form.target##value))
        }
      />
    </div>
    {state.soundtracks
     ->Belt.Array.keep(({node}) => {
         Js.String2.(
           switch (node) {
           | Some({title}) =>
             title->toLowerCase->includes(state.query->toLowerCase)
           | None => true
           }
         )
       })
     ->Belt.Array.map(({node}) => {
         switch (node) {
         | Some({title, id, releaseDate, year} as node) =>
           <Link.Internal key=id path={Route.Soundtrack(id)}>
             <div
               className="border-b border-gray-200 grid-template-track-list
                 grid items-center py-4
                 justify-between">
               <div>
                 <div className="font-bold text-gray-900">
                   {React.string(title)}
                 </div>
                 <Composer query={node.getFragmentRefs()} />
               </div>
               <div className="text-sm text-gray-600 font-variant-tabular">
                 {switch (year) {
                  | Some(year) =>
                    <Link.Internal key=id path={Route.Year(year)}>
                      <DateTime date=releaseDate />
                    </Link.Internal>
                  | None => <DateTime date=releaseDate />
                  }}
               </div>
             </div>
           </Link.Internal>
         | None => React.null
         }
       })
     ->React.array}
  </>;
};
