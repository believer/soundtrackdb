/* @generated */

module Unions = {};

module Types = {};

type response = {
  __wrappedFragment__Soundtracks_query: ReasonRelay.wrappedFragmentRef,
};
type variables = unit;

module FragmentConverters: {
  let unwrapFragment_response:
    response =>
    {. "__$fragment_ref__Soundtracks_query": Soundtracks_query_graphql.t};
} = {
  external unwrapFragment_response:
    response =>
    {. "__$fragment_ref__Soundtracks_query": Soundtracks_query_graphql.t} =
    "%identity";
};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(array((int, string))) = [%raw {| {} |}];
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
  "kind": "ScalarField",
  "alias": null,
  "name": "totalCount",
  "args": null,
  "storageKey": null
},
v3 = [
  {
    "kind": "LinkedField",
    "alias": null,
    "name": "composerByComposerId",
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
  }
];
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
        "name": "allSoundtracks",
        "storageKey": "allSoundtracks(orderBy:\"TITLE_ASC\")",
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
                    "name": "releaseYear",
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
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "tracksBySoundtrackId",
                    "storageKey": "tracksBySoundtrackId(orderBy:\"TRACK_NUMBER_ASC\")",
                    "args": [
                      {
                        "kind": "Literal",
                        "name": "orderBy",
                        "value": "TRACK_NUMBER_ASC"
                      }
                    ],
                    "concreteType": "TracksConnection",
                    "plural": false,
                    "selections": [
                      (v2/*: any*/),
                      {
                        "kind": "LinkedField",
                        "alias": null,
                        "name": "edges",
                        "storageKey": null,
                        "args": null,
                        "concreteType": "TracksEdge",
                        "plural": true,
                        "selections": [
                          {
                            "kind": "LinkedField",
                            "alias": null,
                            "name": "node",
                            "storageKey": null,
                            "args": null,
                            "concreteType": "Track",
                            "plural": false,
                            "selections": [
                              (v0/*: any*/),
                              (v1/*: any*/),
                              {
                                "kind": "ScalarField",
                                "alias": null,
                                "name": "duration",
                                "args": null,
                                "storageKey": null
                              },
                              {
                                "kind": "ScalarField",
                                "alias": null,
                                "name": "trackNumber",
                                "args": null,
                                "storageKey": null
                              },
                              {
                                "kind": "LinkedField",
                                "alias": null,
                                "name": "trackComposersByTrackId",
                                "storageKey": null,
                                "args": null,
                                "concreteType": "TrackComposersConnection",
                                "plural": false,
                                "selections": [
                                  (v2/*: any*/),
                                  {
                                    "kind": "LinkedField",
                                    "alias": null,
                                    "name": "edges",
                                    "storageKey": null,
                                    "args": null,
                                    "concreteType": "TrackComposersEdge",
                                    "plural": true,
                                    "selections": [
                                      {
                                        "kind": "LinkedField",
                                        "alias": null,
                                        "name": "node",
                                        "storageKey": null,
                                        "args": null,
                                        "concreteType": "TrackComposer",
                                        "plural": false,
                                        "selections": (v3/*: any*/)
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
                  {
                    "kind": "LinkedField",
                    "alias": null,
                    "name": "soundtrackComposersBySoundtrackId",
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
                            "selections": (v3/*: any*/)
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
    "text": "query HomeQuery {\n  ...Soundtracks_query\n}\n\nfragment Composer_soundtrack on Soundtrack {\n  soundtrackComposersBySoundtrackId {\n    edges {\n      node {\n        composerByComposerId {\n          fullName\n          id\n        }\n      }\n    }\n  }\n}\n\nfragment Soundtracks_query on Query {\n  allSoundtracks(orderBy: TITLE_ASC) {\n    edges {\n      node {\n        id\n        title\n        ...TrackList_soundtrack\n        ...Composer_soundtrack\n      }\n    }\n  }\n}\n\nfragment TrackList_soundtrack on Soundtrack {\n  releaseYear\n  soundtrackType\n  tracksBySoundtrackId(orderBy: TRACK_NUMBER_ASC) {\n    totalCount\n    edges {\n      node {\n        id\n        title\n        duration\n        trackNumber\n        trackComposersByTrackId {\n          totalCount\n          edges {\n            node {\n              composerByComposerId {\n                fullName\n                id\n              }\n            }\n          }\n        }\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
