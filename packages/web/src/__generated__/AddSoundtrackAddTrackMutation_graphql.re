/* @generated */

module Unions = {};

module Types = {
  type track = {id: string};
  type createTrack = {track: option(track)};
  type trackInput = {
    rowId: option(int),
    title: string,
    duration: int,
    soundtrackId: int,
    trackNumber: int,
    createdAt: option(ReasonRelay.any),
    updatedAt: option(ReasonRelay.any),
  };
  type createTrackInput = {
    clientMutationId: option(string),
    track: trackInput,
  };
};

open Types;

type response = {createTrack: option(createTrack)};
type variables = {input: createTrackInput};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(string)) = [%raw
    {| {"createTrack":{"n":""},"createTrack_track":{"n":""}} |}
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
  let responseConverter: Js.Dict.t(Js.Dict.t(string)) = [%raw
    {| {"createTrack":{"n":""},"createTrack_track":{"n":""}} |}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(string)) = [%raw {| {} |}];
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
    "name": "input",
    "type": "CreateTrackInput!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "createTrack",
    "storageKey": null,
    "args": [
      {
        "kind": "Variable",
        "name": "input",
        "variableName": "input"
      }
    ],
    "concreteType": "CreateTrackPayload",
    "plural": false,
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "track",
        "storageKey": null,
        "args": null,
        "concreteType": "Track",
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
    "name": "AddSoundtrackAddTrackMutation",
    "type": "Mutation",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "AddSoundtrackAddTrackMutation",
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "params": {
    "operationKind": "mutation",
    "name": "AddSoundtrackAddTrackMutation",
    "id": null,
    "text": "mutation AddSoundtrackAddTrackMutation(\n  $input: CreateTrackInput!\n) {\n  createTrack(input: $input) {\n    track {\n      id\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
