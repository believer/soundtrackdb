/* @generated */

module Unions = {};

module Types = {
  type soundtrack = {
    id: string,
    title: string,
    releaseDate: string,
  };
  type node = {soundtrack: option(soundtrack)};
  type edges = {node: option(node)};
  type soundtrackComposers = {
    edges: array(edges),
    totalCount: int,
  };
  type composerById = {
    fullName: option(string),
    soundtrackComposers,
  };
};

open Types;

type response = {composerById: option(composerById)};
type refetchVariables = {id: option(string)};
let makeRefetchVariables = (~id=?, ()): refetchVariables => {id: id};
type variables = {id: string};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"composerById":{"n":""},"composerById_fullName":{"n":""},"composerById_soundtrackComposers_edges_node":{"n":""},"composerById_soundtrackComposers_edges_node_soundtrack":{"n":""}}} |}
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
    "value": "SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC"
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
  "name": "soundtrack",
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
      "name": "releaseDate",
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
        "name": "composerById",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "Composer",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "soundtrackComposers",
            "storageKey": "soundtrackComposers(orderBy:\"SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC\")",
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
        "name": "composerById",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "Composer",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "soundtrackComposers",
            "storageKey": "soundtrackComposers(orderBy:\"SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC\")",
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
    "text": "query ComposerByIdQuery(\n  $id: ID!\n) {\n  composerById(id: $id) {\n    fullName\n    soundtrackComposers(orderBy: SOUNDTRACK_BY_SOUNDTRACK_ID__RELEASE_DATE_DESC) {\n      edges {\n        node {\n          soundtrack {\n            id\n            title\n            releaseDate\n          }\n          id\n        }\n      }\n      totalCount\n    }\n    id\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
