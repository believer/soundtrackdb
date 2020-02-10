module AllComposers = [%relay.query
  {|
   query AddSoundtrackQuery {
    allComposers(orderBy: FIRST_NAME_ASC) {
      edges {
        node {
          id
          fullName
          rowId
        }
      }
    }
  }
|}
];

module AddSoundtrackMutation = [%relay.mutation
  {|
  mutation AddSoundtrackMutation($input: CreateSoundtrackInput!) {
    createSoundtrack(input: $input) {
      soundtrack {
        id
        rowId
      }
    }
  }
|}
];

module AddTrackMutation = [%relay.mutation
  {|
  mutation AddSoundtrackAddTrackMutation($input: CreateTrackInput!) {
    createTrack(input: $input) {
      track {
        id
      }
    }
  }
|}
];

module SoundtrackComposerMutation = [%relay.mutation
  {|
  mutation AddSoundtrackComposerMutation($input: CreateSoundtrackComposerInput!) {
     createSoundtrackComposer(input: $input) {
      soundtrackComposer {
        composerId
      }
    }
  }
|}
];

module Track = {
  type t = {
    title: string,
    duration: string,
  };

  let make = () => {title: "", duration: ""};
};

module AddSountrackForm = {
  type field =
    | ReleaseDate
    | ImdbId
    | SpotifyId
    | SoundtrackType
    | Title
    | AddTrack
    | Composer
    | UpdateTrackTitle
    | UpdateTrackDuration;

  type state = {
    imdbId: string,
    spotifyId: string,
    releaseDate: string,
    soundtrackType: SchemaAssets.Enum_SoundtrackType.t,
    title: string,
    tracks: list((int, Track.t)),
    composerId: int,
  };

  type message = string;
  type submissionError = unit;

  module TitleField = {
    let update = (state, title) => {...state, title};
  };

  module ImdbIdField = {
    let update = (state, imdbId) => {...state, imdbId};
  };

  module SpotifyIdField = {
    let update = (state, spotifyId) => {...state, spotifyId};
  };

  module SoundtrackTypeField = {
    let update = (state, soundtrackType) => {...state, soundtrackType};
  };

  module ReleaseDateField = {
    let update = (state, releaseDate) => {...state, releaseDate};
  };

  module ComposerField = {
    let update = (state, composerId) => {...state, composerId};
  };

  module UpdateTrackTitleField = {
    let update = (state, (trackNumber, title)) => {
      switch (state.tracks->Belt.List.getAssoc(trackNumber, (===))) {
      | Some(track) => {
          ...state,
          tracks:
            state.tracks
            ->Belt.List.setAssoc(trackNumber, {...track, title}, (===)),
        }
      | None => state
      };
    };
  };

  module UpdateTrackDurationField = {
    let update = (state, (trackNumber, duration)) => {
      switch (state.tracks->Belt.List.getAssoc(trackNumber, (===))) {
      | Some(track) => {
          ...state,
          tracks:
            state.tracks
            ->Belt.List.setAssoc(trackNumber, {...track, duration}, (===)),
        }
      | None => state
      };
    };
  };

  module AddTrack = {
    let update = state => {
      let lastId =
        state.tracks->Belt.List.get(Belt.List.length(state.tracks) - 1);

      switch (lastId) {
      | Some((id, _)) => {
          ...state,
          tracks: state.tracks->Belt.List.concat([(id + 1, Track.make())]),
        }
      | None => state
      };
    };
  };

  let validators = [];
};

module AddSountrackFormHook = Formality.Make(AddSountrackForm);

module AddSoundtrackResponse = {
  [@decco.decode]
  type soundtrack = {
    id: string,
    rowId: int,
  };

  [@decco.decode]
  type createSoundtrack = {soundtrack};

  [@decco.decode]
  type t = {createSoundtrack};

  let make = json =>
    switch (t_decode(json)) {
    | Ok(data) => data
    | Error(err) => failwith(err.message)
    };
};

[@react.component]
let make = () => {
  let composers = AllComposers.use(~variables=(), ());

  let form =
    AddSountrackFormHook.useForm(
      ~initialState=
        AddSountrackForm.{
          composerId: 0,
          title: "",
          imdbId: "",
          spotifyId: "",
          releaseDate: "",
          soundtrackType: `MOVIE,
          tracks: [(1, Track.make())],
        },
      ~onSubmit=(state, form) => {
        Js.log2("Submit", state);
        form.notifyOnSuccess(None);

        AddSoundtrackMutation.commitMutation(
          ~environment=RelayEnv.environment,
          ~variables={
            input: {
              soundtrack: {
                title: state.title,
                imdbId: Some(state.imdbId),
                soundtrackType: state.soundtrackType,
                releaseYear: state.releaseDate,
                createdAt: None,
                rowId: None,
                updatedAt: None,
                spotifyId: Some(state.spotifyId),
              },
              clientMutationId: None,
            },
          },
          (),
        )
        |> Js.Promise.then_(res => {
             let response = AddSoundtrackResponse.make(res);
             let soundtrackId = response.createSoundtrack.soundtrack.rowId;

             SoundtrackComposerMutation.commitMutation(
               ~environment=RelayEnv.environment,
               ~variables={
                 input: {
                   clientMutationId: None,
                   soundtrackComposer: {
                     soundtrackId,
                     composerId: state.composerId,
                   },
                 },
               },
               (),
             )
             |> ignore;

             state.tracks
             ->Belt.List.forEach(((trackNumber, track)) => {
                 AddTrackMutation.commitMutation(
                   ~environment=RelayEnv.environment,
                   ~variables={
                     input: {
                       track: {
                         trackNumber,
                         title: track.title,
                         duration: Duration.fromString(track.duration),
                         createdAt: None,
                         updatedAt: None,
                         rowId: None,
                         soundtrackId,
                       },
                       clientMutationId: None,
                     },
                   },
                   (),
                 )
               })
             |> ignore;

             Js.Promise.resolve();
           })
        |> ignore;
      },
    );

  let handleChange = (field, fieldUpdater, event) => {
    form.change(
      field,
      fieldUpdater(form.state, event->ReactEvent.Form.target##value),
    );
  };

  <div className="grid grid-template-960 mt-12">
    <div className="grid-column-center">
      <form
        className="mb-6" onSubmit={form.submit->Formality.Dom.preventDefault}>
        <div className="grid grid-template-2-column grid-gap-4">
          <FormFields.Text
            error={Title->(form.result)}
            label="Title"
            name="soundtrack-title"
            onChange={handleChange(Title, AddSountrackForm.TitleField.update)}
            placeholder="Title"
            value={form.state.title}
          />
          <FormFields.Text
            error={ImdbId->(form.result)}
            label="IMDb ID"
            name="soundtrack-imdbid"
            onChange={handleChange(
              ImdbId,
              AddSountrackForm.ImdbIdField.update,
            )}
            placeholder="IMDb ID"
            value={form.state.imdbId}
          />
        </div>
        <div className="grid grid-template-2-column grid-gap-4">
          <FormFields.Text
            error={ReleaseDate->(form.result)}
            label="Release date"
            name="soundtrack-release-date"
            onChange={handleChange(
              ReleaseDate,
              AddSountrackForm.ReleaseDateField.update,
            )}
            placeholder="Release date"
            value={form.state.releaseDate}
          />
          <FormFields.Text
            error={SpotifyId->(form.result)}
            label="Spotify ID"
            name="soundtrack-spotifyid"
            onChange={handleChange(
              SpotifyId,
              AddSountrackForm.SpotifyIdField.update,
            )}
            placeholder="Spotify ID"
            value={form.state.spotifyId}
          />
        </div>
        <div className="grid grid-template-2-column grid-gap-4 mt-4">
          {switch (composers.allComposers) {
           | Some({edges}) =>
             <Dropdown
               onChange={event => {
                 form.change(
                   Composer,
                   AddSountrackForm.ComposerField.update(
                     form.state,
                     event->ReactEvent.Form.target##value->int_of_string,
                   ),
                 )
               }}
               options={
                 edges
                 ->Belt.Array.map(composer => {
                     switch (composer.node) {
                     | Some({fullName, rowId}) =>
                       Some(
                         Dropdown.Item.make(
                           ~label=fullName->Belt.Option.getWithDefault(""),
                           ~value=rowId->string_of_int,
                         ),
                       )
                     | None => None
                     }
                   })
                 ->Belt.Array.keepMap(t => t)
                 ->Belt.List.fromArray
               }
             />
           | None => React.null
           }}
          <Dropdown
            onChange={event => {
              form.change(
                SoundtrackType,
                AddSountrackForm.SoundtrackTypeField.update(
                  form.state,
                  event->ReactEvent.Form.target##value
                  ->Js.String2.toUpperCase
                  ->SchemaAssets.Enum_SoundtrackType.fromString,
                ),
              )
            }}
            options=Dropdown.Item.[
              make(~label="Game", ~value="GAME"),
              make(~label="Movie", ~value="MOVIE"),
            ]
          />
        </div>
        <div className="mt-4">
          <h2> {React.string("Tracklist")} </h2>
          {form.state.tracks
           ->Belt.List.map(((trackNumber, track)) => {
               <div
                 className="flex items-center"
                 key={Belt.Int.toString(trackNumber)}>
                 <div className="mr-4">
                   {trackNumber->Belt.Int.toString->React.string}
                 </div>
                 <div className="flex-1 mr-4">
                   <FormFields.Text
                     error={UpdateTrackTitle->(form.result)}
                     label="Title"
                     name="soundtrack-track-title"
                     onChange={event => {
                       let value = event->ReactEvent.Form.target##value;

                       form.change(
                         UpdateTrackTitle,
                         AddSountrackForm.UpdateTrackTitleField.update(
                           form.state,
                           (trackNumber, value),
                         ),
                       );
                     }}
                     placeholder="Title"
                     value={track.title}
                   />
                 </div>
                 <div>
                   <FormFields.Text
                     error={UpdateTrackDuration->(form.result)}
                     label="Duration"
                     name="soundtrack-track-duration"
                     onChange={event => {
                       let value = event->ReactEvent.Form.target##value;

                       form.change(
                         UpdateTrackTitle,
                         AddSountrackForm.UpdateTrackDurationField.update(
                           form.state,
                           (trackNumber, value),
                         ),
                       );
                     }}
                     placeholder="Duration"
                     value={track.duration}
                   />
                 </div>
               </div>
             })
           ->Belt.List.toArray
           ->React.array}
        </div>
        <div className="mt-2">
          <button
            className="w-full bg-gray-100 p-2"
            type_="button"
            onClick={_ =>
              form.change(
                AddTrack,
                AddSountrackForm.AddTrack.update(form.state),
              )
            }>
            {React.string("Add track")}
          </button>
        </div>
        <div className="flex justify-end mt-4">
          <button className="px-4 py-2 bg-green-200" type_="submit">
            {React.string("Save")}
          </button>
        </div>
      </form>
    </div>
  </div>;
};
