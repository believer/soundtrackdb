/* @generated */

module Unions = {};

module Types = {
  type soundtrack = {
    releaseYear: string,
    title: string,
    getFragmentRefs:
      unit =>
      {
        .
        "__$fragment_ref__Composer_soundtrack": Composer_soundtrack_graphql.t,
        "__$fragment_ref__TrackList_soundtrack": TrackList_soundtrack_graphql.t,
      },
  };
};

open Types;

type response = {soundtrack: option(soundtrack)};
type refetchVariables = {id: option(string)};
let makeRefetchVariables = (~id=?, ()): refetchVariables => {id: id};
type variables = {id: string};

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"soundtrack":{"n":"","f":""}}} |}
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
  "name": "releaseYear",
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
  "name": "id",
  "args": null,
  "storageKey": null
},
v5 = [
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
      (v4/*: any*/)
    ]
  },
  (v4/*: any*/)
],
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
    "name": "SoundtrackByIdQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "soundtrack",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "Soundtrack",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          (v3/*: any*/),
          {
            "kind": "FragmentSpread",
            "name": "Composer_soundtrack",
            "args": null
          },
          {
            "kind": "FragmentSpread",
            "name": "TrackList_soundtrack",
            "args": null
          }
        ]
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "SoundtrackByIdQuery",
    "argumentDefinitions": (v0/*: any*/),
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "soundtrack",
        "storageKey": null,
        "args": (v1/*: any*/),
        "concreteType": "Soundtrack",
        "plural": false,
        "selections": [
          (v2/*: any*/),
          (v3/*: any*/),
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
                    "selections": (v5/*: any*/)
                  }
                ]
              }
            ]
          },
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "imdbId",
            "args": null,
            "storageKey": null
          },
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "spotifyId",
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
              (v6/*: any*/),
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
                      (v4/*: any*/),
                      (v3/*: any*/),
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
                          (v6/*: any*/),
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
                                "selections": (v5/*: any*/)
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
          (v4/*: any*/)
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "SoundtrackByIdQuery",
    "id": null,
    "text": "query SoundtrackByIdQuery(\n  $id: ID!\n) {\n  soundtrack(id: $id) {\n    releaseYear\n    title\n    ...Composer_soundtrack\n    ...TrackList_soundtrack\n    id\n  }\n}\n\nfragment Composer_soundtrack on Soundtrack {\n  soundtrackComposersBySoundtrackId {\n    edges {\n      node {\n        composerByComposerId {\n          fullName\n          id\n        }\n        id\n      }\n    }\n  }\n}\n\nfragment TrackList_soundtrack on Soundtrack {\n  imdbId\n  spotifyId\n  releaseYear\n  tracksBySoundtrackId(orderBy: TRACK_NUMBER_ASC) {\n    totalCount\n    edges {\n      node {\n        id\n        title\n        duration\n        trackNumber\n        trackComposersByTrackId {\n          totalCount\n          edges {\n            node {\n              composerByComposerId {\n                fullName\n                id\n              }\n              id\n            }\n          }\n        }\n      }\n    }\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];