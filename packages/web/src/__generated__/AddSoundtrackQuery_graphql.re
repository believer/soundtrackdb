/* @generated */

module Unions = {};

module Types = {
  type node = {
    id: string,
    fullName: option(string),
    rowId: int,
  };
  type edges = {node: option(node)};
  type allComposers = {edges: array(edges)};
};

open Types;

type response = {allComposers: option(allComposers)};
type variables = unit;

module FragmentConverters: {} = {};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(array((int, string))) = [%raw
    {| {"allComposers":[[0,""]],"allComposers_edges_node":[[0,""]],"allComposers_edges_node_fullName":[[0,""]]} |}
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

type operationType = ReasonRelay.queryNode;

let node: operationType = [%bs.raw
  {| (function(){
var v0 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "allComposers",
    "storageKey": "allComposers(orderBy:\"FIRST_NAME_ASC\")",
    "args": [
      {
        "kind": "Literal",
        "name": "orderBy",
        "value": "FIRST_NAME_ASC"
      }
    ],
    "concreteType": "ComposersConnection",
    "plural": false,
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "edges",
        "storageKey": null,
        "args": null,
        "concreteType": "ComposersEdge",
        "plural": true,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "node",
            "storageKey": null,
            "args": null,
            "concreteType": "Composer",
            "plural": false,
            "selections": [
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "id",
                "args": null,
                "storageKey": null
              },
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "fullName",
                "args": null,
                "storageKey": null
              },
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "rowId",
                "args": null,
                "storageKey": null
              }
            ]
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
    "name": "AddSoundtrackQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": [],
    "selections": (v0/*: any*/)
  },
  "operation": {
    "kind": "Operation",
    "name": "AddSoundtrackQuery",
    "argumentDefinitions": [],
    "selections": (v0/*: any*/)
  },
  "params": {
    "operationKind": "query",
    "name": "AddSoundtrackQuery",
    "id": null,
    "text": "query AddSoundtrackQuery {\n  allComposers(orderBy: FIRST_NAME_ASC) {\n    edges {\n      node {\n        id\n        fullName\n        rowId\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
