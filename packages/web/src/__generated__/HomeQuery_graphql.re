/* @generated */

module Unions = {};

module Types = {};

type response = {
  getFragmentRefs:
    unit =>
    {
      .
      "__$fragment_ref__Soundtracks_query": Soundtracks_query_graphql.t,
      "__$fragment_ref__LatestSoundtracks_soundtracks": LatestSoundtracks_soundtracks_graphql.t,
    },
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
},
v1 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "title",
  "args": null,
  "storageKey": null
},
v2 = {
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
      },
      {
        "kind": "FragmentSpread",
        "name": "LatestSoundtracks_soundtracks",
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
                  (v1/*: any*/),
                  {
                    "kind": "ScalarField",
                    "alias": null,
                    "name": "releaseDate",
                    "args": null,
                    "storageKey": null
                  },
                  (v2/*: any*/)
                ]
              }
            ]
          }
        ]
      },
      {
        "kind": "LinkedField",
        "alias": "latestSoundtracks",
        "name": "soundtracks",
        "storageKey": "soundtracks(first:10,orderBy:\"CREATED_AT_DESC\")",
        "args": [
          {
            "kind": "Literal",
            "name": "first",
            "value": 10
          },
          {
            "kind": "Literal",
            "name": "orderBy",
            "value": "CREATED_AT_DESC"
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
                  {
                    "kind": "ScalarField",
                    "alias": null,
                    "name": "createdAt",
                    "args": null,
                    "storageKey": null
                  },
                  (v0/*: any*/),
                  (v1/*: any*/),
                  (v2/*: any*/)
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
    "text": "query HomeQuery {\n  ...Soundtracks_query\n  ...LatestSoundtracks_soundtracks\n}\n\nfragment Composer_soundtrack on Soundtrack {\n  soundtrackComposers {\n    edges {\n      node {\n        composer {\n          fullName\n          id\n        }\n        id\n      }\n    }\n  }\n}\n\nfragment LatestSoundtracks_soundtracks on Query {\n  latestSoundtracks: soundtracks(orderBy: CREATED_AT_DESC, first: 10) {\n    edges {\n      node {\n        createdAt\n        id\n        title\n        ...Composer_soundtrack\n      }\n    }\n  }\n}\n\nfragment Soundtracks_query on Query {\n  soundtracks(orderBy: TITLE_ASC) {\n    edges {\n      node {\n        id\n        title\n        releaseDate\n        ...Composer_soundtrack\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
