/* @generated */

module Unions = {};

module Types = {
  type soundtrack = {id: string};
  type createSoundtrack = {soundtrack: option(soundtrack)};
};

open Types;

type response = {createSoundtrack: option(createSoundtrack)};
type variables = unit;

module FragmentConverters: {} = {};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(array((int, string))) = [%raw
    {| {"createSoundtrack":[[0,""]],"createSoundtrack_soundtrack":[[0,""]]} |}
  ];
  let wrapResponseConverterMap = ();
  let convertWrapResponse = v =>
    v
    ->ReasonRelay._convertObj(
        wrapResponseConverter,
        wrapResponseConverterMap,
        Js.null,
      );

  type responseRaw;
  let responseConverter: Js.Dict.t(array((int, string))) = [%raw
    {| {"createSoundtrack":[[0,""]],"createSoundtrack_soundtrack":[[0,""]]} |}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(array((int, string))) = [%raw {| {} |}];
  let variablesConverterMap = ();
  let convertVariables = v =>
    v
    ->ReasonRelay._convertObj(
        variablesConverter,
        variablesConverterMap,
        Js.undefined,
      );
};

type operationType = ReasonRelay.mutationNode;

let node: operationType = [%bs.raw
  {| (function(){
var v0 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "createSoundtrack",
    "storageKey": "createSoundtrack(input:{\"soundtrack\":{\"imdbId\":\"tt12\",\"releaseYear\":\"2011-05-12\",\"soundtrackType\":\"MOVIE\",\"title\":\"Test\"}})",
    "args": [
      {
        "kind": "Literal",
        "name": "input",
        "value": {
          "soundtrack": {
            "imdbId": "tt12",
            "releaseYear": "2011-05-12",
            "soundtrackType": "MOVIE",
            "title": "Test"
          }
        }
      }
    ],
    "concreteType": "CreateSoundtrackPayload",
    "plural": false,
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "soundtrack",
        "storageKey": null,
        "args": null,
        "concreteType": "Soundtrack",
        "plural": false,
        "selections": [
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "id",
            "args": null,
            "storageKey": null
          }
        ]
      }
    ]
  }
];
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "AddSoundtrackMutation",
    "type": "Mutation",
    "metadata": null,
    "argumentDefinitions": [],
    "selections": (v0/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "AddSoundtrackMutation",
    "argumentDefinitions": [],
    "selections": (v0/*: any*/)
  },
  "params": {
    "operationKind": "mutation",
    "name": "AddSoundtrackMutation",
    "id": null,
    "text": "mutation AddSoundtrackMutation {\n  createSoundtrack(input: {soundtrack: {title: \"Test\", soundtrackType: MOVIE, releaseYear: \"2011-05-12\", imdbId: \"tt12\"}}) {\n    soundtrack {\n      id\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
