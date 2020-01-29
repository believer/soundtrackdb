/* @generated */

module Unions = {};

module Types = {
  type soundtrackComposerInput = {
    composerId: int,
    soundtrackId: int,
  };
  type createSoundtrackComposerInput = {
    clientMutationId: option(string),
    soundtrackComposer: soundtrackComposerInput,
  };
  type soundtrackComposer = {composerId: int};
  type createSoundtrackComposer = {
    soundtrackComposer: option(soundtrackComposer),
  };
};

open Types;

type response = {createSoundtrackComposer: option(createSoundtrackComposer)};
type variables = {input: createSoundtrackComposerInput};

module Internal = {
  type wrapResponseRaw;
  let wrapResponseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"createSoundtrackComposer":{"n":""},"createSoundtrackComposer_soundtrackComposer":{"n":""}}} |}
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
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"createSoundtrackComposer":{"n":""},"createSoundtrackComposer_soundtrackComposer":{"n":""}}} |}
  ];
  let responseConverterMap = ();
  let convertResponse = v =>
    v
    ->ReasonRelay._convertObj(
        responseConverter,
        responseConverterMap,
        Js.undefined,
      );

  let variablesConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"input":{"r":"CreateSoundtrackComposerInput"}},"SoundtrackComposerInput":{},"CreateSoundtrackComposerInput":{"clientMutationId":{"n":""},"soundtrackComposer":{"r":"SoundtrackComposerInput"}}} |}
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
    "name": "input",
    "type": "CreateSoundtrackComposerInput!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "createSoundtrackComposer",
    "storageKey": null,
    "args": [
      {
        "kind": "Variable",
        "name": "input",
        "variableName": "input"
      }
    ],
    "concreteType": "CreateSoundtrackComposerPayload",
    "plural": false,
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "soundtrackComposer",
        "storageKey": null,
        "args": null,
        "concreteType": "SoundtrackComposer",
        "plural": false,
        "selections": [
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "composerId",
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
    "name": "AddSoundtrackComposerMutation",
    "type": "Mutation",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "AddSoundtrackComposerMutation",
    "argumentDefinitions": (v0/*: any*/),
    "selections": (v1/*: any*/)
  },
  "params": {
    "operationKind": "mutation",
    "name": "AddSoundtrackComposerMutation",
    "id": null,
    "text": "mutation AddSoundtrackComposerMutation(\n  $input: CreateSoundtrackComposerInput!\n) {\n  createSoundtrackComposer(input: $input) {\n    soundtrackComposer {\n      composerId\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
