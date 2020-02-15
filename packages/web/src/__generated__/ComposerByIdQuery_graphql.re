/* @generated */

module Unions = {};

module Types = {
  type soundtrackBySoundtrackId = {
    id: string,
    title: string,
    releaseYear: string,
  };
  type node = {soundtrackBySoundtrackId: option(soundtrackBySoundtrackId)};
  type edges = {node: option(node)};
  type soundtrackComposersByComposerId = {
    edges: array(edges),
    totalCount: int,
  };
  type composer = {
    fullName: option(string),
    soundtrackComposersByComposerId,
  };
};

open Types;

type response = {composer: option(composer)};
type refetchVariables = {id: option(string)};
let makeRefetchVariables = (~id=?, ()): refetchVariables => {id: id};
type variables = {id: string};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"composer":{"n":""},"composer_fullName":{"n":""},"composer_soundtrackComposersByComposerId_edges_node":{"n":""},"composer_soundtrackComposersByComposerId_edges_node_soundtrackBySoundtrackId":{"n":""}}} |}
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

type operationType = ReasonRelay.queryNode;

let node: operationType = [%bs.raw
  {| (function(){
var v0 = [
  {
    "kind": "LocalArgument",
    "name": "id",
    "type": "ID!",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "id",
    "variableName": "id"
  }
],
v2 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "fullName",
  "args": null,
  "storageKey": null
},
v3 = [
  {
    "kind": "Literal",
    "name": "orderBy",
    "value": "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_YEAR_DESC"
  }
],
v4 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
},
v5 = {
  "kind": "LinkedField",
  "alias": null,
  "name": "soundtrackBySoundtrackId",
  "storageKey": null,
  "args": null,
  "concreteType": "Soundtrack",
  "plural": false,
  "selections": [
    (v4/*: any*/),
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "title",
      "args": null,
      "storageKey": null
    },
    {
      "kind": "ScalarField",
      "alias": null,
      "name": "releaseYear",
      "args": null,
      "storageKey": null
    }
  ]
},
v6 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "totalCount",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "ComposerByIdQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "composer",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "Composer",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "soundtrackComposersByComposerId",
            "storageKey": "soundtrackComposersByComposerId(orderBy:\"SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_YEAR_DESC\")",
            "args": (v3/*: any*/),
            "concreteType": "SoundtrackComposersConnection",
            "plural": false,
            "selections": [
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "edges",
                "storageKey": null,
                "args": null,
                "concreteType": "SoundtrackComposersEdge",
                "plural": true,
                "selections": [
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "node",
                    "storageKey": null,
                    "args": null,
                    "concreteType": "SoundtrackComposer",
                    "plural": false,
                    "selections": [
                      (v5/*: any*/)
                    ]
                  }
                ]
              },
              (v6/*: any*/)
            ]
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "ComposerByIdQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "composer",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "Composer",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "soundtrackComposersByComposerId",
            "storageKey": "soundtrackComposersByComposerId(orderBy:\"SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_YEAR_DESC\")",
            "args": (v3/*: any*/),
            "concreteType": "SoundtrackComposersConnection",
            "plural": false,
            "selections": [
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "edges",
                "storageKey": null,
                "args": null,
                "concreteType": "SoundtrackComposersEdge",
                "plural": true,
                "selections": [
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "node",
                    "storageKey": null,
                    "args": null,
                    "concreteType": "SoundtrackComposer",
                    "plural": false,
                    "selections": [
                      (v5/*: any*/),
                      (v4/*: any*/)
                    ]
                  }
                ]
              },
              (v6/*: any*/)
            ]
          },
          (v4/*: any*/)
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "ComposerByIdQuery",
    "id": null,
    "text": "query ComposerByIdQuery(\n  $id: ID!\n) {\n  composer(id: $id) {\n    fullName\n    soundtrackComposersByComposerId(orderBy: SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_YEAR_DESC) {\n      edges {\n        node {\n          soundtrackBySoundtrackId {\n            id\n            title\n            releaseYear\n          }\n          id\n        }\n      }\n      totalCount\n    }\n    id\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
