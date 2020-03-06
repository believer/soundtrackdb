/* @generated */

type enum_SoundtrackType = [ | `GAME | `MOVIE | `TV | `FUTURE_ADDED_VALUE__];

module Unions = {};

module Types = {
  type soundtrackCondition = {
    rowId: option(int),
    title: option(string),
    imdbId: option(string),
    soundtrackType: option(enum_SoundtrackType),
    releaseDate: option(string),
    createdAt: option(string),
    updatedAt: option(string),
    spotifyId: option(string),
    year: option(string),
  };
  type node = {
    id: string,
    title: string,
    releaseDate: string,
    getFragmentRefs:
      unit =>
      {
        .
        "__$fragment_ref__Composer_soundtrack": Composer_soundtrack_graphql.t,
      },
  };
  type edges = {node: option(node)};
  type soundtracks = {edges: array(edges)};
};

open Types;

type response = {soundtracks: option(soundtracks)};
type refetchVariables = {condition: option(soundtrackCondition)};
let makeRefetchVariables = (~condition=?, ()): refetchVariables => {
  condition: condition,
};
type variables = {condition: option(soundtrackCondition)};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"soundtracks":{"n":""},"soundtracks_edges_node":{"n":"","f":""}}} |}
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
    {| {"__root":{"condition":{"n":"","r":"SoundtrackCondition"}},"SoundtrackCondition":{"rowId":{"n":""},"title":{"n":""},"imdbId":{"n":""},"soundtrackType":{"n":"","e":"enum_SoundtrackType"},"releaseDate":{"n":""},"createdAt":{"n":""},"updatedAt":{"n":""},"spotifyId":{"n":""},"year":{"n":""}}} |}
  ];
  let variablesConverterMap = {
    "enum_SoundtrackType": SchemaAssets.Enum_SoundtrackType.wrap,
  };
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
    "name": "condition",
    "type": "SoundtrackCondition",
    "defaultValue": null
  }
],
v1 = [
  {
    "kind": "Variable",
    "name": "condition",
    "variableName": "condition"
  }
],
v2 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
},
v3 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "title",
  "args": null,
  "storageKey": null
},
v4 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "releaseDate",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "YearByYearQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "soundtracks",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "SoundtracksConnection",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "edges",
            "storageKey": null,
            "args": null,
            "concreteType": "SoundtracksEdge",
            "plural": true,
            "selections": [
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "node",
                "storageKey": null,
                "args": null,
                "concreteType": "Soundtrack",
                "plural": false,
                "selections": [
                  (v2/*: any*/),
                  (v3/*: any*/),
                  (v4/*: any*/),
                  {
                    "kind": "FragmentSpread",
                    "name": "Composer_soundtrack",
                    "args": null
                  }
                ]
              }
            ]
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "YearByYearQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "soundtracks",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "SoundtracksConnection",
        "plural": false,
        "selections": [
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "edges",
            "storageKey": null,
            "args": null,
            "concreteType": "SoundtracksEdge",
            "plural": true,
            "selections": [
              {
                "kind": "LinkedField",
                "alias": null,
                "name": "node",
                "storageKey": null,
                "args": null,
                "concreteType": "Soundtrack",
                "plural": false,
                "selections": [
                  (v2/*: any*/),
                  (v3/*: any*/),
                  (v4/*: any*/),
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "soundtrackComposers",
                    "storageKey": null,
                    "args": null,
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
                              {
                                "kind": "LinkedField",
                                "alias": null,
                                "name": "composer",
                                "storageKey": null,
                                "args": null,
                                "concreteType": "Composer",
                                "plural": false,
                                "selections": [
                                  {
                                    "kind": "ScalarField",
                                    "alias": null,
                                    "name": "fullName",
                                    "args": null,
                                    "storageKey": null
                                  },
                                  (v2/*: any*/)
                                ]
                              },
                              (v2/*: any*/)
                            ]
                          }
                        ]
                      }
                    ]
                  }
                ]
              }
            ]
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "YearByYearQuery",
    "id": null,
    "text": "query YearByYearQuery(\n  $condition: SoundtrackCondition\n) {\n  soundtracks(condition: $condition) {\n    edges {\n      node {\n        id\n        title\n        releaseDate\n        ...Composer_soundtrack\n      }\n    }\n  }\n}\n\nfragment Composer_soundtrack on Soundtrack {\n  soundtrackComposers {\n    edges {\n      node {\n        composer {\n          fullName\n          id\n        }\n        id\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
