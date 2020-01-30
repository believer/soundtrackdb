/* @generated */

type enum_SoundtrackType = [ | `GAME | `MOVIE | `FUTURE_ADDED_VALUE__];

module Unions = {};

module Types = {
  type composerByComposerId = {fullName: option(string)};
  type node = {composerByComposerId: option(composerByComposerId)};
  type edges = {node: option(node)};
  type trackComposersByTrackId = {
    totalCount: int,
    edges: array(edges),
  };
  type edges_node = {
    id: string,
    title: string,
    duration: int,
    trackNumber: int,
    trackComposersByTrackId,
  };
  type tracksBySoundtrackId_edges = {node: option(edges_node)};
  type tracksBySoundtrackId = {
    totalCount: int,
    edges: array(tracksBySoundtrackId_edges),
  };
};

open Types;

type fragment = {
  imdbId: option(string),
  releaseYear: string,
  soundtrackType: enum_SoundtrackType,
  tracksBySoundtrackId,
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"imdbId":{"n":""},"soundtrackType":{"e":"enum_SoundtrackType"},"tracksBySoundtrackId_edges_node":{"n":""},"tracksBySoundtrackId_edges_node_trackComposersByTrackId_edges_node":{"n":""},"tracksBySoundtrackId_edges_node_trackComposersByTrackId_edges_node_composerByComposerId":{"n":""},"tracksBySoundtrackId_edges_node_trackComposersByTrackId_edges_node_composerByComposerId_fullName":{"n":""}}} |}
  ];
  let fragmentConverterMap = {
    "enum_SoundtrackType": SchemaAssets.Enum_SoundtrackType.unwrap,
  };
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
type fragmentRefSelector('a) =
  {.. "__$fragment_ref__TrackList_soundtrack": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%bs.raw
  {| (function(){
var v0 = {
  "kind": "ScalarField",
  "alias": null,
  "name": "totalCount",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Fragment",
  "name": "TrackList_soundtrack",
  "type": "Soundtrack",
  "metadata": null,
  "argumentDefinitions": [],
  "selections": [
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
        (v0/*: any*/),
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
                  "name": "title",
                  "args": null,
                  "storageKey": null
                },
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
                    (v0/*: any*/),
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
                          "selections": [
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
        }
      ]
    }
  ]
};
})() |}
];
