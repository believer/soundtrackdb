/* @generated */

type enum_SoundtrackType = [ | `GAME | `MOVIE | `TV | `FUTURE_ADDED_VALUE__];

module Unions = {};

module Types = {
  type soundtrackPlaylist = {
    composers: array(string),
    imdbId: option(string),
    playlist: string,
    releaseDate: string,
    soundtrackType: option(enum_SoundtrackType),
    spotifyId: option(string),
    title: string,
  };
};

open Types;

type response = {soundtrackPlaylist};
type variables = {url: string};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"soundtrackPlaylist_imdbId":{"n":""},"soundtrackPlaylist_soundtrackType":{"n":"","e":"enum_SoundtrackType"},"soundtrackPlaylist_spotifyId":{"n":""}}} |}
  ];
  let wrapResponseConverterMap = {
    "enum_SoundtrackType": SchemaAssets.Enum_SoundtrackType.wrap,
  };
  let convertWrapResponse = v =>
    v
    ->ReasonRelay._convertObj(
        wrapResponseConverter,
        wrapResponseConverterMap,
        Js.null,
      );

  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"soundtrackPlaylist_imdbId":{"n":""},"soundtrackPlaylist_soundtrackType":{"n":"","e":"enum_SoundtrackType"},"soundtrackPlaylist_spotifyId":{"n":""}}} |}
  ];
  let responseConverterMap = {
    "enum_SoundtrackType": SchemaAssets.Enum_SoundtrackType.unwrap,
  };
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {} |}
  ];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

module Utils = {};

type operationType = ReasonRelay.mutationNode;

let node: operationType = [%bs.raw
  {| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "url",
    "type": "String!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "soundtrackPlaylist",
    "storageKey": null,
    "args": [
      {
        "kind": "Variable",
        "name": "url",
        "variableName": "url"
      }
    ],
    "concreteType": "SoundtrackPlaylist",
    "plural": false,
    "selections": [
      {
        "kind": "ScalarField",
        "alias": null,
        "name": "composers",
        "args": null,
        "storageKey": null
      },
      {
        "kind": "ScalarField",
        "alias": null,
        "name": "imdbId",
        "args": null,
        "storageKey": null
      },
      {
        "kind": "ScalarField",
        "alias": null,
        "name": "playlist",
        "args": null,
        "storageKey": null
      },
      {
        "kind": "ScalarField",
        "alias": null,
        "name": "releaseDate",
        "args": null,
        "storageKey": null
      },
      {
        "kind": "ScalarField",
        "alias": null,
        "name": "soundtrackType",
        "args": null,
        "storageKey": null
      },
      {
        "kind": "ScalarField",
        "alias": null,
        "name": "spotifyId",
        "args": null,
        "storageKey": null
      },
      {
        "kind": "ScalarField",
        "alias": null,
        "name": "title",
        "args": null,
        "storageKey": null
      }
    ]
  }
];
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "AddFromURLMutation",
    "type": "Mutation",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "AddFromURLMutation",
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "params": {
    "operationKind": "mutation",
    "name": "AddFromURLMutation",
    "id": null,
    "text": "mutation AddFromURLMutation(\n  $url: String!\n) {\n  soundtrackPlaylist(url: $url) {\n    composers\n    imdbId\n    playlist\n    releaseDate\n    soundtrackType\n    spotifyId\n    title\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
