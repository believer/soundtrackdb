open Js.String2;

module Patterns = {
  let imdbUrl = [%re "/https:\\/\\/www.imdb.com\\/title\\//ig"];
  let queryParams = [%re "/\\/?\\?\\w+=([^&]*)/"];
};

module Id = {
  let make = id => {
    Some(
      id
      ->replaceByRe(Patterns.queryParams, "")
      ->replaceByRe(Patterns.imdbUrl, ""),
    );
  };
};

module Link = {
  let make = id => {j|https://www.imdb.com/title/$id|j};
};
