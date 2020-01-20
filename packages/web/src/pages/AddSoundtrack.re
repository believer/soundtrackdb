module UpdateMutation = [%relay.mutation
  {|
  mutation AddSoundtrackMutation(
    $title: String!
    $soundtrackType: SoundtrackType!
    $releaseYear: Datetime!
    $imdbId: String!
  ) {
    createSoundtrack(
      input: {
        soundtrack: {
          title: $title
          soundtrackType: $soundtrackType
          releaseYear: $releaseYear
          imdbId: $imdbId
        }
      }
    ) {
      soundtrack {
        id
      }
    }
  }
|}
];

module AddSountrackForm = {
  /*open Formality;*/

  type field =
    | ReleaseDate
    | ImdbId
    | SoundtrackType
    | Title;

  type state = {
    imdbId: string,
    releaseDate: string,
    soundtrackType: SchemaAssets.Enum_SoundtrackType.t,
    title: string,
  };

  type message = string;
  type submissionError = unit;

  module TitleField = {
    let update = (state, title) => {...state, title};
  };

  module ImdbIdField = {
    let update = (state, imdbId) => {...state, imdbId};
  };

  module SoundtrackTypeField = {
    let update = (state, soundtrackType) => {...state, soundtrackType};
  };

  module ReleaseDateField = {
    let update = (state, releaseDate) => {...state, releaseDate};
  };

  let validators = [];
};

module AddSountrackFormHook = Formality.Make(AddSountrackForm);

[@react.component]
let make = () => {
  let form =
    AddSountrackFormHook.useForm(
      ~initialState=
        AddSountrackForm.{
          title: "",
          imdbId: "",
          releaseDate: "",
          soundtrackType: `MOVIE,
        },
      ~onSubmit=(state, form) => {
        Js.log2("Submit", state);
        form.notifyOnSuccess(None);
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
          onChange={handleChange(ImdbId, AddSountrackForm.ImdbIdField.update)}
          placeholder="IMDb ID"
          value={form.state.imdbId}
        />
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
        <div>
          <select
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
            }}>
            <option value="MOVIE"> {React.string("Movie")} </option>
            <option value="GAME"> {React.string("Game")} </option>
          </select>
        </div>
        <button type_="submit"> {React.string("Save")} </button>
      </form>
    </div>
  </div>;
};
