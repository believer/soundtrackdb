/* @generated */

module Unions = {};

module Types = {};

type response = {
  getFragmentRefs:
    unit =>
    {. "__$fragment_ref__Soundtracks_query": Soundtracks_query_graphql.t},
};
type variables = unit;

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"":{"f":""}}} |}
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
var v0 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "id",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "HomeQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": [],
    "selections": [
      {
        "kind": "FragmentSpread",
        "name": "Soundtracks_query",
        "args": null
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "HomeQuery",
    "argumentDefinitions": [],
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "soundtracks",
        "storageKey": "soundtracks(orderBy:\"TITLE_ASC\")",
        "args": [
          {
            "kind": "Literal",
            "name": "orderBy",
            "value": "TITLE_ASC"
          }
        ],
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
                  (v0/*: any*/),
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
                  },
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
                                  (v0/*: any*/)
                                ]
                              },
                              (v0/*: any*/)
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
    "name": "HomeQuery",
    "id": null,
    "text": "query HomeQuery {\n  ...Soundtracks_query\n}\n\nfragment Composer_soundtrack on Soundtrack {\n  soundtrackComposers {\n    edges {\n      node {\n        composer {\n          fullName\n          id\n        }\n        id\n      }\n    }\n  }\n}\n\nfragment Soundtracks_query on Query {\n  soundtracks(orderBy: TITLE_ASC) {\n    edges {\n      node {\n        id\n        title\n        releaseYear\n        ...Composer_soundtrack\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
