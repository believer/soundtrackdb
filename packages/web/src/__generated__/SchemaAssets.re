/** This file is autogenerated by ReasonRelay and should not be modified manually. */
/**
 * ENUMS
 * Helpers for wrapping/unwrapping enums.
 */
module Enum_ComposersOrderBy: {
  type t = [
    | `NATURAL
    | `ID_ASC
    | `ID_DESC
    | `FIRST_NAME_ASC
    | `FIRST_NAME_DESC
    | `LAST_NAME_ASC
    | `LAST_NAME_DESC
    | `CREATED_AT_ASC
    | `CREATED_AT_DESC
    | `UPDATED_AT_ASC
    | `UPDATED_AT_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC
    | `SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC
    | `TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC
    | `TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;
  let unwrap: wrapped => t;
  let wrap: t => wrapped;
  let toString: t => string;
  let fromString: string => t;
} = {
  type t = [
    | `NATURAL
    | `ID_ASC
    | `ID_DESC
    | `FIRST_NAME_ASC
    | `FIRST_NAME_DESC
    | `LAST_NAME_ASC
    | `LAST_NAME_DESC
    | `CREATED_AT_ASC
    | `CREATED_AT_DESC
    | `UPDATED_AT_ASC
    | `UPDATED_AT_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC
    | `SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC
    | `TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC
    | `TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;

  external __unwrap: wrapped => string = "%identity";
  external __wrap: string => wrapped = "%identity";

  let unwrap = wrapped =>
    switch (wrapped |> __unwrap) {
    | "NATURAL" => `NATURAL
    | "ID_ASC" => `ID_ASC
    | "ID_DESC" => `ID_DESC
    | "FIRST_NAME_ASC" => `FIRST_NAME_ASC
    | "FIRST_NAME_DESC" => `FIRST_NAME_DESC
    | "LAST_NAME_ASC" => `LAST_NAME_ASC
    | "LAST_NAME_DESC" => `LAST_NAME_DESC
    | "CREATED_AT_ASC" => `CREATED_AT_ASC
    | "CREATED_AT_DESC" => `CREATED_AT_DESC
    | "UPDATED_AT_ASC" => `UPDATED_AT_ASC
    | "UPDATED_AT_DESC" => `UPDATED_AT_DESC
    | "PRIMARY_KEY_ASC" => `PRIMARY_KEY_ASC
    | "PRIMARY_KEY_DESC" => `PRIMARY_KEY_DESC
    | "SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC" => `SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC
    | "SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC" => `SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC
    | "TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC" => `TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC
    | "TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC" => `TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC
    | _ => `FUTURE_ADDED_VALUE__
    };

  let wrap = t =>
    (
      switch (t) {
      | `NATURAL => "NATURAL"
      | `ID_ASC => "ID_ASC"
      | `ID_DESC => "ID_DESC"
      | `FIRST_NAME_ASC => "FIRST_NAME_ASC"
      | `FIRST_NAME_DESC => "FIRST_NAME_DESC"
      | `LAST_NAME_ASC => "LAST_NAME_ASC"
      | `LAST_NAME_DESC => "LAST_NAME_DESC"
      | `CREATED_AT_ASC => "CREATED_AT_ASC"
      | `CREATED_AT_DESC => "CREATED_AT_DESC"
      | `UPDATED_AT_ASC => "UPDATED_AT_ASC"
      | `UPDATED_AT_DESC => "UPDATED_AT_DESC"
      | `PRIMARY_KEY_ASC => "PRIMARY_KEY_ASC"
      | `PRIMARY_KEY_DESC => "PRIMARY_KEY_DESC"
      | `SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC => "SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC"
      | `SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC => "SOUNDTRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC"
      | `TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC => "TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_ASC"
      | `TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC => "TRACK_COMPOSERS_BY_COMPOSER_ID__COUNT_DESC"
      | `FUTURE_ADDED_VALUE__ => ""
      }
    )
    |> __wrap;

  let toString = t => t |> wrap |> __unwrap;
  let fromString = str => str |> __wrap |> unwrap;
};

module Enum_SoundtrackComposersOrderBy: {
  type t = [
    | `NATURAL
    | `COMPOSER_ID_ASC
    | `COMPOSER_ID_DESC
    | `SOUNDTRACK_ID_ASC
    | `SOUNDTRACK_ID_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `COMPOSER_BY_COMPOSER_ID__ID_ASC
    | `COMPOSER_BY_COMPOSER_ID__ID_DESC
    | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC
    | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC
    | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC
    | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC
    | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC
    | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC
    | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC
    | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;
  let unwrap: wrapped => t;
  let wrap: t => wrapped;
  let toString: t => string;
  let fromString: string => t;
} = {
  type t = [
    | `NATURAL
    | `COMPOSER_ID_ASC
    | `COMPOSER_ID_DESC
    | `SOUNDTRACK_ID_ASC
    | `SOUNDTRACK_ID_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `COMPOSER_BY_COMPOSER_ID__ID_ASC
    | `COMPOSER_BY_COMPOSER_ID__ID_DESC
    | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC
    | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC
    | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC
    | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC
    | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC
    | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC
    | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC
    | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;

  external __unwrap: wrapped => string = "%identity";
  external __wrap: string => wrapped = "%identity";

  let unwrap = wrapped =>
    switch (wrapped |> __unwrap) {
    | "NATURAL" => `NATURAL
    | "COMPOSER_ID_ASC" => `COMPOSER_ID_ASC
    | "COMPOSER_ID_DESC" => `COMPOSER_ID_DESC
    | "SOUNDTRACK_ID_ASC" => `SOUNDTRACK_ID_ASC
    | "SOUNDTRACK_ID_DESC" => `SOUNDTRACK_ID_DESC
    | "PRIMARY_KEY_ASC" => `PRIMARY_KEY_ASC
    | "PRIMARY_KEY_DESC" => `PRIMARY_KEY_DESC
    | "COMPOSER_BY_COMPOSER_ID__ID_ASC" => `COMPOSER_BY_COMPOSER_ID__ID_ASC
    | "COMPOSER_BY_COMPOSER_ID__ID_DESC" => `COMPOSER_BY_COMPOSER_ID__ID_DESC
    | "COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC" => `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC
    | "COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC" => `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC
    | "COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC" => `COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC
    | "COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC" => `COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC
    | "COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC" => `COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC
    | "COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC" => `COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC
    | "COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC" => `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC
    | "COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC" => `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC
    | _ => `FUTURE_ADDED_VALUE__
    };

  let wrap = t =>
    (
      switch (t) {
      | `NATURAL => "NATURAL"
      | `COMPOSER_ID_ASC => "COMPOSER_ID_ASC"
      | `COMPOSER_ID_DESC => "COMPOSER_ID_DESC"
      | `SOUNDTRACK_ID_ASC => "SOUNDTRACK_ID_ASC"
      | `SOUNDTRACK_ID_DESC => "SOUNDTRACK_ID_DESC"
      | `PRIMARY_KEY_ASC => "PRIMARY_KEY_ASC"
      | `PRIMARY_KEY_DESC => "PRIMARY_KEY_DESC"
      | `COMPOSER_BY_COMPOSER_ID__ID_ASC => "COMPOSER_BY_COMPOSER_ID__ID_ASC"
      | `COMPOSER_BY_COMPOSER_ID__ID_DESC => "COMPOSER_BY_COMPOSER_ID__ID_DESC"
      | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC => "COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC"
      | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC => "COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC"
      | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC => "COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC"
      | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC => "COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC"
      | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC => "COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC"
      | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC => "COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC"
      | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC => "COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC"
      | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC => "COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC"
      | `FUTURE_ADDED_VALUE__ => ""
      }
    )
    |> __wrap;

  let toString = t => t |> wrap |> __unwrap;
  let fromString = str => str |> __wrap |> unwrap;
};

module Enum_SoundtrackType: {
  type t = [ | `GAME | `MOVIE | `TV | `FUTURE_ADDED_VALUE__];
  type wrapped;
  let unwrap: wrapped => t;
  let wrap: t => wrapped;
  let toString: t => string;
  let fromString: string => t;
} = {
  type t = [ | `GAME | `MOVIE | `TV | `FUTURE_ADDED_VALUE__];
  type wrapped;

  external __unwrap: wrapped => string = "%identity";
  external __wrap: string => wrapped = "%identity";

  let unwrap = wrapped =>
    switch (wrapped |> __unwrap) {
    | "GAME" => `GAME
    | "MOVIE" => `MOVIE
    | "TV" => `TV
    | _ => `FUTURE_ADDED_VALUE__
    };

  let wrap = t =>
    (
      switch (t) {
      | `GAME => "GAME"
      | `MOVIE => "MOVIE"
      | `TV => "TV"
      | `FUTURE_ADDED_VALUE__ => ""
      }
    )
    |> __wrap;

  let toString = t => t |> wrap |> __unwrap;
  let fromString = str => str |> __wrap |> unwrap;
};

module Enum_TracksOrderBy: {
  type t = [
    | `NATURAL
    | `ID_ASC
    | `ID_DESC
    | `TITLE_ASC
    | `TITLE_DESC
    | `DURATION_ASC
    | `DURATION_DESC
    | `SOUNDTRACK_ID_ASC
    | `SOUNDTRACK_ID_DESC
    | `TRACK_NUMBER_ASC
    | `TRACK_NUMBER_DESC
    | `CREATED_AT_ASC
    | `CREATED_AT_DESC
    | `UPDATED_AT_ASC
    | `UPDATED_AT_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC
    | `TRACK_COMPOSERS_BY_TRACK_ID__COUNT_ASC
    | `TRACK_COMPOSERS_BY_TRACK_ID__COUNT_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;
  let unwrap: wrapped => t;
  let wrap: t => wrapped;
  let toString: t => string;
  let fromString: string => t;
} = {
  type t = [
    | `NATURAL
    | `ID_ASC
    | `ID_DESC
    | `TITLE_ASC
    | `TITLE_DESC
    | `DURATION_ASC
    | `DURATION_DESC
    | `SOUNDTRACK_ID_ASC
    | `SOUNDTRACK_ID_DESC
    | `TRACK_NUMBER_ASC
    | `TRACK_NUMBER_DESC
    | `CREATED_AT_ASC
    | `CREATED_AT_DESC
    | `UPDATED_AT_ASC
    | `UPDATED_AT_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC
    | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC
    | `TRACK_COMPOSERS_BY_TRACK_ID__COUNT_ASC
    | `TRACK_COMPOSERS_BY_TRACK_ID__COUNT_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;

  external __unwrap: wrapped => string = "%identity";
  external __wrap: string => wrapped = "%identity";

  let unwrap = wrapped =>
    switch (wrapped |> __unwrap) {
    | "NATURAL" => `NATURAL
    | "ID_ASC" => `ID_ASC
    | "ID_DESC" => `ID_DESC
    | "TITLE_ASC" => `TITLE_ASC
    | "TITLE_DESC" => `TITLE_DESC
    | "DURATION_ASC" => `DURATION_ASC
    | "DURATION_DESC" => `DURATION_DESC
    | "SOUNDTRACK_ID_ASC" => `SOUNDTRACK_ID_ASC
    | "SOUNDTRACK_ID_DESC" => `SOUNDTRACK_ID_DESC
    | "TRACK_NUMBER_ASC" => `TRACK_NUMBER_ASC
    | "TRACK_NUMBER_DESC" => `TRACK_NUMBER_DESC
    | "CREATED_AT_ASC" => `CREATED_AT_ASC
    | "CREATED_AT_DESC" => `CREATED_AT_DESC
    | "UPDATED_AT_ASC" => `UPDATED_AT_ASC
    | "UPDATED_AT_DESC" => `UPDATED_AT_DESC
    | "PRIMARY_KEY_ASC" => `PRIMARY_KEY_ASC
    | "PRIMARY_KEY_DESC" => `PRIMARY_KEY_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC
    | "SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC" => `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC
    | "TRACK_COMPOSERS_BY_TRACK_ID__COUNT_ASC" => `TRACK_COMPOSERS_BY_TRACK_ID__COUNT_ASC
    | "TRACK_COMPOSERS_BY_TRACK_ID__COUNT_DESC" => `TRACK_COMPOSERS_BY_TRACK_ID__COUNT_DESC
    | _ => `FUTURE_ADDED_VALUE__
    };

  let wrap = t =>
    (
      switch (t) {
      | `NATURAL => "NATURAL"
      | `ID_ASC => "ID_ASC"
      | `ID_DESC => "ID_DESC"
      | `TITLE_ASC => "TITLE_ASC"
      | `TITLE_DESC => "TITLE_DESC"
      | `DURATION_ASC => "DURATION_ASC"
      | `DURATION_DESC => "DURATION_DESC"
      | `SOUNDTRACK_ID_ASC => "SOUNDTRACK_ID_ASC"
      | `SOUNDTRACK_ID_DESC => "SOUNDTRACK_ID_DESC"
      | `TRACK_NUMBER_ASC => "TRACK_NUMBER_ASC"
      | `TRACK_NUMBER_DESC => "TRACK_NUMBER_DESC"
      | `CREATED_AT_ASC => "CREATED_AT_ASC"
      | `CREATED_AT_DESC => "CREATED_AT_DESC"
      | `UPDATED_AT_ASC => "UPDATED_AT_ASC"
      | `UPDATED_AT_DESC => "UPDATED_AT_DESC"
      | `PRIMARY_KEY_ASC => "PRIMARY_KEY_ASC"
      | `PRIMARY_KEY_DESC => "PRIMARY_KEY_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__ID_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__ID_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__TITLE_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__IMDB_ID_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__SOUNDTRACK_TYPE_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__CREATED_AT_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__UPDATED_AT_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__SPOTIFY_ID_DESC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC => "SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_ASC"
      | `SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC => "SOUNDTRACK_BY_SOUNDTRACK_ID__YEAR_DESC"
      | `TRACK_COMPOSERS_BY_TRACK_ID__COUNT_ASC => "TRACK_COMPOSERS_BY_TRACK_ID__COUNT_ASC"
      | `TRACK_COMPOSERS_BY_TRACK_ID__COUNT_DESC => "TRACK_COMPOSERS_BY_TRACK_ID__COUNT_DESC"
      | `FUTURE_ADDED_VALUE__ => ""
      }
    )
    |> __wrap;

  let toString = t => t |> wrap |> __unwrap;
  let fromString = str => str |> __wrap |> unwrap;
};

module Enum_TrackComposersOrderBy: {
  type t = [
    | `NATURAL
    | `TRACK_ID_ASC
    | `TRACK_ID_DESC
    | `COMPOSER_ID_ASC
    | `COMPOSER_ID_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `TRACK_BY_TRACK_ID__ID_ASC
    | `TRACK_BY_TRACK_ID__ID_DESC
    | `TRACK_BY_TRACK_ID__TITLE_ASC
    | `TRACK_BY_TRACK_ID__TITLE_DESC
    | `TRACK_BY_TRACK_ID__DURATION_ASC
    | `TRACK_BY_TRACK_ID__DURATION_DESC
    | `TRACK_BY_TRACK_ID__SOUNDTRACK_ID_ASC
    | `TRACK_BY_TRACK_ID__SOUNDTRACK_ID_DESC
    | `TRACK_BY_TRACK_ID__TRACK_NUMBER_ASC
    | `TRACK_BY_TRACK_ID__TRACK_NUMBER_DESC
    | `TRACK_BY_TRACK_ID__CREATED_AT_ASC
    | `TRACK_BY_TRACK_ID__CREATED_AT_DESC
    | `TRACK_BY_TRACK_ID__UPDATED_AT_ASC
    | `TRACK_BY_TRACK_ID__UPDATED_AT_DESC
    | `COMPOSER_BY_COMPOSER_ID__ID_ASC
    | `COMPOSER_BY_COMPOSER_ID__ID_DESC
    | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC
    | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC
    | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC
    | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC
    | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC
    | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC
    | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC
    | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;
  let unwrap: wrapped => t;
  let wrap: t => wrapped;
  let toString: t => string;
  let fromString: string => t;
} = {
  type t = [
    | `NATURAL
    | `TRACK_ID_ASC
    | `TRACK_ID_DESC
    | `COMPOSER_ID_ASC
    | `COMPOSER_ID_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `TRACK_BY_TRACK_ID__ID_ASC
    | `TRACK_BY_TRACK_ID__ID_DESC
    | `TRACK_BY_TRACK_ID__TITLE_ASC
    | `TRACK_BY_TRACK_ID__TITLE_DESC
    | `TRACK_BY_TRACK_ID__DURATION_ASC
    | `TRACK_BY_TRACK_ID__DURATION_DESC
    | `TRACK_BY_TRACK_ID__SOUNDTRACK_ID_ASC
    | `TRACK_BY_TRACK_ID__SOUNDTRACK_ID_DESC
    | `TRACK_BY_TRACK_ID__TRACK_NUMBER_ASC
    | `TRACK_BY_TRACK_ID__TRACK_NUMBER_DESC
    | `TRACK_BY_TRACK_ID__CREATED_AT_ASC
    | `TRACK_BY_TRACK_ID__CREATED_AT_DESC
    | `TRACK_BY_TRACK_ID__UPDATED_AT_ASC
    | `TRACK_BY_TRACK_ID__UPDATED_AT_DESC
    | `COMPOSER_BY_COMPOSER_ID__ID_ASC
    | `COMPOSER_BY_COMPOSER_ID__ID_DESC
    | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC
    | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC
    | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC
    | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC
    | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC
    | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC
    | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC
    | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;

  external __unwrap: wrapped => string = "%identity";
  external __wrap: string => wrapped = "%identity";

  let unwrap = wrapped =>
    switch (wrapped |> __unwrap) {
    | "NATURAL" => `NATURAL
    | "TRACK_ID_ASC" => `TRACK_ID_ASC
    | "TRACK_ID_DESC" => `TRACK_ID_DESC
    | "COMPOSER_ID_ASC" => `COMPOSER_ID_ASC
    | "COMPOSER_ID_DESC" => `COMPOSER_ID_DESC
    | "PRIMARY_KEY_ASC" => `PRIMARY_KEY_ASC
    | "PRIMARY_KEY_DESC" => `PRIMARY_KEY_DESC
    | "TRACK_BY_TRACK_ID__ID_ASC" => `TRACK_BY_TRACK_ID__ID_ASC
    | "TRACK_BY_TRACK_ID__ID_DESC" => `TRACK_BY_TRACK_ID__ID_DESC
    | "TRACK_BY_TRACK_ID__TITLE_ASC" => `TRACK_BY_TRACK_ID__TITLE_ASC
    | "TRACK_BY_TRACK_ID__TITLE_DESC" => `TRACK_BY_TRACK_ID__TITLE_DESC
    | "TRACK_BY_TRACK_ID__DURATION_ASC" => `TRACK_BY_TRACK_ID__DURATION_ASC
    | "TRACK_BY_TRACK_ID__DURATION_DESC" => `TRACK_BY_TRACK_ID__DURATION_DESC
    | "TRACK_BY_TRACK_ID__SOUNDTRACK_ID_ASC" => `TRACK_BY_TRACK_ID__SOUNDTRACK_ID_ASC
    | "TRACK_BY_TRACK_ID__SOUNDTRACK_ID_DESC" => `TRACK_BY_TRACK_ID__SOUNDTRACK_ID_DESC
    | "TRACK_BY_TRACK_ID__TRACK_NUMBER_ASC" => `TRACK_BY_TRACK_ID__TRACK_NUMBER_ASC
    | "TRACK_BY_TRACK_ID__TRACK_NUMBER_DESC" => `TRACK_BY_TRACK_ID__TRACK_NUMBER_DESC
    | "TRACK_BY_TRACK_ID__CREATED_AT_ASC" => `TRACK_BY_TRACK_ID__CREATED_AT_ASC
    | "TRACK_BY_TRACK_ID__CREATED_AT_DESC" => `TRACK_BY_TRACK_ID__CREATED_AT_DESC
    | "TRACK_BY_TRACK_ID__UPDATED_AT_ASC" => `TRACK_BY_TRACK_ID__UPDATED_AT_ASC
    | "TRACK_BY_TRACK_ID__UPDATED_AT_DESC" => `TRACK_BY_TRACK_ID__UPDATED_AT_DESC
    | "COMPOSER_BY_COMPOSER_ID__ID_ASC" => `COMPOSER_BY_COMPOSER_ID__ID_ASC
    | "COMPOSER_BY_COMPOSER_ID__ID_DESC" => `COMPOSER_BY_COMPOSER_ID__ID_DESC
    | "COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC" => `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC
    | "COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC" => `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC
    | "COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC" => `COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC
    | "COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC" => `COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC
    | "COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC" => `COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC
    | "COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC" => `COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC
    | "COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC" => `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC
    | "COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC" => `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC
    | _ => `FUTURE_ADDED_VALUE__
    };

  let wrap = t =>
    (
      switch (t) {
      | `NATURAL => "NATURAL"
      | `TRACK_ID_ASC => "TRACK_ID_ASC"
      | `TRACK_ID_DESC => "TRACK_ID_DESC"
      | `COMPOSER_ID_ASC => "COMPOSER_ID_ASC"
      | `COMPOSER_ID_DESC => "COMPOSER_ID_DESC"
      | `PRIMARY_KEY_ASC => "PRIMARY_KEY_ASC"
      | `PRIMARY_KEY_DESC => "PRIMARY_KEY_DESC"
      | `TRACK_BY_TRACK_ID__ID_ASC => "TRACK_BY_TRACK_ID__ID_ASC"
      | `TRACK_BY_TRACK_ID__ID_DESC => "TRACK_BY_TRACK_ID__ID_DESC"
      | `TRACK_BY_TRACK_ID__TITLE_ASC => "TRACK_BY_TRACK_ID__TITLE_ASC"
      | `TRACK_BY_TRACK_ID__TITLE_DESC => "TRACK_BY_TRACK_ID__TITLE_DESC"
      | `TRACK_BY_TRACK_ID__DURATION_ASC => "TRACK_BY_TRACK_ID__DURATION_ASC"
      | `TRACK_BY_TRACK_ID__DURATION_DESC => "TRACK_BY_TRACK_ID__DURATION_DESC"
      | `TRACK_BY_TRACK_ID__SOUNDTRACK_ID_ASC => "TRACK_BY_TRACK_ID__SOUNDTRACK_ID_ASC"
      | `TRACK_BY_TRACK_ID__SOUNDTRACK_ID_DESC => "TRACK_BY_TRACK_ID__SOUNDTRACK_ID_DESC"
      | `TRACK_BY_TRACK_ID__TRACK_NUMBER_ASC => "TRACK_BY_TRACK_ID__TRACK_NUMBER_ASC"
      | `TRACK_BY_TRACK_ID__TRACK_NUMBER_DESC => "TRACK_BY_TRACK_ID__TRACK_NUMBER_DESC"
      | `TRACK_BY_TRACK_ID__CREATED_AT_ASC => "TRACK_BY_TRACK_ID__CREATED_AT_ASC"
      | `TRACK_BY_TRACK_ID__CREATED_AT_DESC => "TRACK_BY_TRACK_ID__CREATED_AT_DESC"
      | `TRACK_BY_TRACK_ID__UPDATED_AT_ASC => "TRACK_BY_TRACK_ID__UPDATED_AT_ASC"
      | `TRACK_BY_TRACK_ID__UPDATED_AT_DESC => "TRACK_BY_TRACK_ID__UPDATED_AT_DESC"
      | `COMPOSER_BY_COMPOSER_ID__ID_ASC => "COMPOSER_BY_COMPOSER_ID__ID_ASC"
      | `COMPOSER_BY_COMPOSER_ID__ID_DESC => "COMPOSER_BY_COMPOSER_ID__ID_DESC"
      | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC => "COMPOSER_BY_COMPOSER_ID__FIRST_NAME_ASC"
      | `COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC => "COMPOSER_BY_COMPOSER_ID__FIRST_NAME_DESC"
      | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC => "COMPOSER_BY_COMPOSER_ID__LAST_NAME_ASC"
      | `COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC => "COMPOSER_BY_COMPOSER_ID__LAST_NAME_DESC"
      | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC => "COMPOSER_BY_COMPOSER_ID__CREATED_AT_ASC"
      | `COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC => "COMPOSER_BY_COMPOSER_ID__CREATED_AT_DESC"
      | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC => "COMPOSER_BY_COMPOSER_ID__UPDATED_AT_ASC"
      | `COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC => "COMPOSER_BY_COMPOSER_ID__UPDATED_AT_DESC"
      | `FUTURE_ADDED_VALUE__ => ""
      }
    )
    |> __wrap;

  let toString = t => t |> wrap |> __unwrap;
  let fromString = str => str |> __wrap |> unwrap;
};

module Enum_SoundtracksOrderBy: {
  type t = [
    | `NATURAL
    | `ID_ASC
    | `ID_DESC
    | `TITLE_ASC
    | `TITLE_DESC
    | `IMDB_ID_ASC
    | `IMDB_ID_DESC
    | `SOUNDTRACK_TYPE_ASC
    | `SOUNDTRACK_TYPE_DESC
    | `RELEASE_DATE_ASC
    | `RELEASE_DATE_DESC
    | `CREATED_AT_ASC
    | `CREATED_AT_DESC
    | `UPDATED_AT_ASC
    | `UPDATED_AT_DESC
    | `SPOTIFY_ID_ASC
    | `SPOTIFY_ID_DESC
    | `YEAR_ASC
    | `YEAR_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_ASC
    | `SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_DESC
    | `TRACKS_BY_SOUNDTRACK_ID__COUNT_ASC
    | `TRACKS_BY_SOUNDTRACK_ID__COUNT_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;
  let unwrap: wrapped => t;
  let wrap: t => wrapped;
  let toString: t => string;
  let fromString: string => t;
} = {
  type t = [
    | `NATURAL
    | `ID_ASC
    | `ID_DESC
    | `TITLE_ASC
    | `TITLE_DESC
    | `IMDB_ID_ASC
    | `IMDB_ID_DESC
    | `SOUNDTRACK_TYPE_ASC
    | `SOUNDTRACK_TYPE_DESC
    | `RELEASE_DATE_ASC
    | `RELEASE_DATE_DESC
    | `CREATED_AT_ASC
    | `CREATED_AT_DESC
    | `UPDATED_AT_ASC
    | `UPDATED_AT_DESC
    | `SPOTIFY_ID_ASC
    | `SPOTIFY_ID_DESC
    | `YEAR_ASC
    | `YEAR_DESC
    | `PRIMARY_KEY_ASC
    | `PRIMARY_KEY_DESC
    | `SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_ASC
    | `SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_DESC
    | `TRACKS_BY_SOUNDTRACK_ID__COUNT_ASC
    | `TRACKS_BY_SOUNDTRACK_ID__COUNT_DESC
    | `FUTURE_ADDED_VALUE__
  ];
  type wrapped;

  external __unwrap: wrapped => string = "%identity";
  external __wrap: string => wrapped = "%identity";

  let unwrap = wrapped =>
    switch (wrapped |> __unwrap) {
    | "NATURAL" => `NATURAL
    | "ID_ASC" => `ID_ASC
    | "ID_DESC" => `ID_DESC
    | "TITLE_ASC" => `TITLE_ASC
    | "TITLE_DESC" => `TITLE_DESC
    | "IMDB_ID_ASC" => `IMDB_ID_ASC
    | "IMDB_ID_DESC" => `IMDB_ID_DESC
    | "SOUNDTRACK_TYPE_ASC" => `SOUNDTRACK_TYPE_ASC
    | "SOUNDTRACK_TYPE_DESC" => `SOUNDTRACK_TYPE_DESC
    | "RELEASE_DATE_ASC" => `RELEASE_DATE_ASC
    | "RELEASE_DATE_DESC" => `RELEASE_DATE_DESC
    | "CREATED_AT_ASC" => `CREATED_AT_ASC
    | "CREATED_AT_DESC" => `CREATED_AT_DESC
    | "UPDATED_AT_ASC" => `UPDATED_AT_ASC
    | "UPDATED_AT_DESC" => `UPDATED_AT_DESC
    | "SPOTIFY_ID_ASC" => `SPOTIFY_ID_ASC
    | "SPOTIFY_ID_DESC" => `SPOTIFY_ID_DESC
    | "YEAR_ASC" => `YEAR_ASC
    | "YEAR_DESC" => `YEAR_DESC
    | "PRIMARY_KEY_ASC" => `PRIMARY_KEY_ASC
    | "PRIMARY_KEY_DESC" => `PRIMARY_KEY_DESC
    | "SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_ASC" => `SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_ASC
    | "SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_DESC" => `SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_DESC
    | "TRACKS_BY_SOUNDTRACK_ID__COUNT_ASC" => `TRACKS_BY_SOUNDTRACK_ID__COUNT_ASC
    | "TRACKS_BY_SOUNDTRACK_ID__COUNT_DESC" => `TRACKS_BY_SOUNDTRACK_ID__COUNT_DESC
    | _ => `FUTURE_ADDED_VALUE__
    };

  let wrap = t =>
    (
      switch (t) {
      | `NATURAL => "NATURAL"
      | `ID_ASC => "ID_ASC"
      | `ID_DESC => "ID_DESC"
      | `TITLE_ASC => "TITLE_ASC"
      | `TITLE_DESC => "TITLE_DESC"
      | `IMDB_ID_ASC => "IMDB_ID_ASC"
      | `IMDB_ID_DESC => "IMDB_ID_DESC"
      | `SOUNDTRACK_TYPE_ASC => "SOUNDTRACK_TYPE_ASC"
      | `SOUNDTRACK_TYPE_DESC => "SOUNDTRACK_TYPE_DESC"
      | `RELEASE_DATE_ASC => "RELEASE_DATE_ASC"
      | `RELEASE_DATE_DESC => "RELEASE_DATE_DESC"
      | `CREATED_AT_ASC => "CREATED_AT_ASC"
      | `CREATED_AT_DESC => "CREATED_AT_DESC"
      | `UPDATED_AT_ASC => "UPDATED_AT_ASC"
      | `UPDATED_AT_DESC => "UPDATED_AT_DESC"
      | `SPOTIFY_ID_ASC => "SPOTIFY_ID_ASC"
      | `SPOTIFY_ID_DESC => "SPOTIFY_ID_DESC"
      | `YEAR_ASC => "YEAR_ASC"
      | `YEAR_DESC => "YEAR_DESC"
      | `PRIMARY_KEY_ASC => "PRIMARY_KEY_ASC"
      | `PRIMARY_KEY_DESC => "PRIMARY_KEY_DESC"
      | `SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_ASC => "SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_ASC"
      | `SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_DESC => "SOUNDTRACK_COMPOSERS_BY_SOUNDTRACK_ID__COUNT_DESC"
      | `TRACKS_BY_SOUNDTRACK_ID__COUNT_ASC => "TRACKS_BY_SOUNDTRACK_ID__COUNT_ASC"
      | `TRACKS_BY_SOUNDTRACK_ID__COUNT_DESC => "TRACKS_BY_SOUNDTRACK_ID__COUNT_DESC"
      | `FUTURE_ADDED_VALUE__ => ""
      }
    )
    |> __wrap;

  let toString = t => t |> wrap |> __unwrap;
  let fromString = str => str |> __wrap |> unwrap;
};
