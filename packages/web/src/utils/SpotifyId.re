open Js.String2;

module Patterns = {
  let spotifyAlbumUrl = [%re "/https:\\/\\/open.spotify.com\\/album\\//ig"];
  let spotifyAlbumUri = [%re "/spotify:album:/ig"];
  let queryParams = [%re "/\\?si=([^&]*)/"];
};

let make = id => {
  Some(
    id
    ->replaceByRe(Patterns.queryParams, "")
    ->replaceByRe(Patterns.spotifyAlbumUri, "")
    ->replaceByRe(Patterns.spotifyAlbumUrl, ""),
  );
};
