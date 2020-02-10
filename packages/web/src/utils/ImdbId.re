open Js.String2;

module Patterns = {
  let imdbUrl = [%re "/https:\\/\\/www.imdb.com\\/title\\//ig"];
  let queryParams = [%re "/\\/?\\?\\w+=([^&]*)/"];
};

let make = id => {
  Some(
    id
    ->replaceByRe(Patterns.queryParams, "")
    ->replaceByRe(Patterns.imdbUrl, ""),
  );
};
