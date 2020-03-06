module AllComposers = [%relay.query
  {|
   query AddSoundtrackQuery {
    composers(orderBy: FIRST_NAME_ASC) {
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

module AddSoundtrackForm = {
  type field =
    | ReleaseDate
    | ImdbId
    | SpotifyId
    | SoundtrackType
    | Title
    | AddTrack
    | InsertTracks
    | InsertSoundtrackData
    | RemoveTrack
    | Composer
    | UpdateTrackTitle
    | UpdateTrackDuration;

  type state = {
    imdbId: string,
    spotifyId: string,
    releaseDate: string,
    soundtrackType: SchemaAssets.Enum_SoundtrackType.t,
    title: string,
    tracks: list((CUID.t, Track.t)),
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
      | Some(_) => {
          ...state,
          tracks:
            state.tracks
            ->Belt.List.concat([(CUID.make(), Track.makeEmpty())]),
        }
      | None => state
      };
    };
  };

  module InsertTracks = {
    let update = (state, tracks) => {
      {
        ...state,
        tracks: tracks->Belt.List.map(track => (CUID.make(), track)),
      };
    };
  };

  module InsertSoundtrackData = {
    let update =
        (
          state,
          data: AddFromURL.AddFromURLResponse.soundtrackPlaylist,
          matchedComposer,
        ) => {
      {
        title: data.title,
        releaseDate: data.releaseDate,
        soundtrackType:
          switch (data.soundtrackType) {
          | Some(stype) => SchemaAssets.Enum_SoundtrackType.fromString(stype)
          | None => state.soundtrackType
          },
        composerId:
          switch (matchedComposer) {
          | Some((_, id)) => id
          | None => state.composerId
          },
        spotifyId:
          switch (data.spotifyId) {
          | Some(id) => id
          | None => state.spotifyId
          },
        imdbId:
          switch (data.imdbId) {
          | Some(id) => id
          | None => state.imdbId
          },
        tracks:
          data.playlist
          ->CSV.Parse.make
          ->Belt.List.map(track => (CUID.make(), track)),
      };
    };
  };

  module RemoveTrack = {
    let update = (state, id) => {
      switch (Belt.List.length(state.tracks)) {
      | 1 => state
      | _ => {
          ...state,
          tracks: state.tracks->Belt.List.removeAssoc(id, (===)),
        }
      };
    };
  };

  let validators = [];
};

module AddSoundtrackFormHook = Formality.Make(AddSoundtrackForm);

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
    AddSoundtrackFormHook.useForm(
      ~initialState=
        AddSoundtrackForm.{
          composerId:
            switch (composers.composers) {
            | Some({edges}) =>
              switch (edges->Belt.Array.get(0)) {
              | Some({node}) =>
                switch (node) {
                | Some({rowId}) => rowId
                | None => 0
                }
              | None => 0
              }
            | None => 0
            },
          title: "",
          imdbId: "",
          spotifyId: "",
          releaseDate: "",
          soundtrackType: `MOVIE,
          tracks: [(CUID.make(), Track.makeEmpty())],
        },
      ~onSubmit=(state, form) => {
        form.notifyOnSuccess(None);

        AddSoundtrackMutation.commitMutation(
          ~environment=RelayEnv.environment,
          ~variables={
            input: {
              soundtrack: {
                title: state.title,
                imdbId: IMDb.Id.make(state.imdbId),
                soundtrackType: state.soundtrackType,
                releaseDate: DateTime.Parse.make(state.releaseDate),
                createdAt: None,
                rowId: None,
                updatedAt: None,
                year:
                  Some(
                    state.releaseDate
                    |> Js.Date.fromString
                    |> Js.Date.getFullYear
                    |> Belt.Float.toString,
                  ),
                spotifyId: Spotify.Id.make(state.spotifyId),
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
             ->Belt.List.forEachWithIndex((i, (_, track)) => {
                 AddTrackMutation.commitMutation(
                   ~environment=RelayEnv.environment,
                   ~variables={
                     input: {
                       track: {
                         trackNumber: i + 1,
                         title: TitleCase.make(track.title),
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

             form.reset();

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

  <div className="grid grid-template-1140 mt-12">
    <div className="grid-column-center">
      <form
        className="mb-6" onSubmit={form.submit->Formality.Dom.preventDefault}>
        <div className="mb-12 w-3/5">
          <FormFields.Text
            className="text-4xl font-black text-gray-900"
            error={Title->(form.result)}
            label="Title"
            name="soundtrack-title"
            onChange={handleChange(
              Title,
              AddSoundtrackForm.TitleField.update,
            )}
            placeholder="Title"
            value={form.state.title}
          />
        </div>
        <div className="grid grid-template-soundtrack grid-gap-20">
          <div>
            {form.state.tracks
             ->Belt.List.mapWithIndex((i, (id, track)) => {
                 <div className="flex items-center" key={CUID.toString(id)}>
                   <div className="mr-4 text-gray-600">
                     {(i + 1)->Belt.Int.toString->React.string}
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
                           AddSoundtrackForm.UpdateTrackTitleField.update(
                             form.state,
                             (id, value),
                           ),
                         );
                       }}
                       placeholder="Title"
                       value={track.title}
                     />
                   </div>
                   <div className="mr-4 w-20">
                     <FormFields.Text
                       error={UpdateTrackDuration->(form.result)}
                       label="Duration"
                       name="soundtrack-track-duration"
                       onChange={event => {
                         let value = event->ReactEvent.Form.target##value;

                         form.change(
                           UpdateTrackTitle,
                           AddSoundtrackForm.UpdateTrackDurationField.update(
                             form.state,
                             (id, value),
                           ),
                         );
                       }}
                       placeholder="Duration"
                       value={track.duration}
                     />
                   </div>
                   <button
                     type_="button"
                     onClick={_ =>
                       form.change(
                         RemoveTrack,
                         AddSoundtrackForm.RemoveTrack.update(form.state, id),
                       )
                     }>
                     <Icon.Trash />
                   </button>
                 </div>
               })
             ->Belt.List.toArray
             ->React.array}
            <div>
              {switch (
                 form.state.tracks
                 ->Belt.List.reduce(0, (acc, (_id, track)) =>
                     acc + Duration.fromString(track.duration)
                   )
               ) {
               | 0 => React.null
               | duration =>
                 <div className="text-sm mt-4 text-gray-600 text-right">
                   {React.string("Total playtime: ")}
                   {duration->Duration.make->React.string}
                 </div>
               }}
              <div className="mt-8 justify-end flex">
                <Button.Secondary
                  leading={<Icon.Add />}
                  onClick={_ =>
                    form.change(
                      AddTrack,
                      AddSoundtrackForm.AddTrack.update(form.state),
                    )
                  }>
                  {React.string("Add track")}
                </Button.Secondary>
              </div>
            </div>
          </div>
          <div>
            <div className="mb-4">
              <FormFields.Text
                error={ImdbId->(form.result)}
                helper={
                  switch (IMDb.Id.make(form.state.imdbId)) {
                  | Some("")
                  | None => React.null
                  | Some(id) =>
                    <a
                      href={IMDb.Link.make(id)}
                      target="_blank"
                      rel="noopener noreferrer">
                      {React.string("IMDb - " ++ id)}
                    </a>
                  }
                }
                label="IMDb ID"
                name="soundtrack-imdbid"
                onChange={handleChange(
                  ImdbId,
                  AddSoundtrackForm.ImdbIdField.update,
                )}
                placeholder="IMDb ID"
                value={form.state.imdbId}
              />
            </div>
            <div className="mb-4">
              <FormFields.Text
                error={SpotifyId->(form.result)}
                helper={
                  switch (Spotify.Id.make(form.state.spotifyId)) {
                  | Some("")
                  | None => React.null
                  | Some(id) =>
                    <a
                      href={Spotify.Link.make(id)}
                      target="_blank"
                      rel="noopener noreferrer">
                      {React.string("Spotify - " ++ id)}
                    </a>
                  }
                }
                label="Spotify ID"
                name="soundtrack-spotifyid"
                onChange={handleChange(
                  SpotifyId,
                  AddSoundtrackForm.SpotifyIdField.update,
                )}
                placeholder="Spotify ID"
                value={form.state.spotifyId}
              />
            </div>
            <div className="mb-8">
              <FormFields.Text
                error={ReleaseDate->(form.result)}
                helper={
                  switch (form.state.releaseDate) {
                  | "" => React.null
                  | _ =>
                    React.string(DateTime.Parse.make(form.state.releaseDate))
                  }
                }
                label="Release date"
                name="soundtrack-release-date"
                onChange={handleChange(
                  ReleaseDate,
                  AddSoundtrackForm.ReleaseDateField.update,
                )}
                placeholder="Release date"
                value={form.state.releaseDate}
              />
            </div>
            <div className="mb-4">
              {switch (composers.composers) {
               | Some({edges}) =>
                 <Dropdown
                   onChange={event => {
                     form.change(
                       Composer,
                       AddSoundtrackForm.ComposerField.update(
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
                               ~label=
                                 fullName->Belt.Option.getWithDefault(""),
                               ~value=rowId->Belt.Int.toString,
                             ),
                           )
                         | None => None
                         }
                       })
                     ->Belt.Array.keepMap(t => t)
                     ->Belt.List.fromArray
                   }
                   value={Belt.Int.toString(form.state.composerId)}
                 />
               | None => React.null
               }}
            </div>
            <div className="mb-8">
              <Dropdown
                onChange={event => {
                  form.change(
                    SoundtrackType,
                    AddSoundtrackForm.SoundtrackTypeField.update(
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
                  make(~label="TV", ~value="TV"),
                ]
                value={
                  form.state.soundtrackType
                  ->SchemaAssets.Enum_SoundtrackType.toString
                }
              />
            </div>
            <div className="mb-10">
              <AddFromURL
                updateData={(
                  data: AddFromURL.AddFromURLResponse.soundtrackPlaylist,
                ) => {
                  let composers =
                    switch (composers.composers) {
                    | Some({edges}) =>
                      edges
                      ->Belt.Array.map(composer => {
                          switch (composer.node) {
                          | Some({fullName, rowId}) =>
                            Some((
                              fullName->Belt.Option.getWithDefault(""),
                              rowId,
                            ))
                          | None => None
                          }
                        })
                      ->Belt.Array.keepMap(t => t)
                    | None => [||]
                    };

                  let matchedComposer =
                    data.composers
                    ->Belt.Array.map(name => {
                        composers->Js.Array2.find(((fullName, _)) =>
                          fullName === name
                        )
                      })
                    ->Belt.Array.keepMap(c => c)
                    ->Belt.Array.get(0);

                  form.change(
                    InsertSoundtrackData,
                    AddSoundtrackForm.InsertSoundtrackData.update(
                      form.state,
                      data,
                      matchedComposer,
                    ),
                  );
                }}
              />
            </div>
            <div className="flex justify-end">
              <Button.Primary type_="submit">
                {React.string("Save")}
              </Button.Primary>
            </div>
          </div>
        </div>
      </form>
    </div>
  </div>;
};
