/* @generated */

module Unions = {};

module Types = {
  type composer = {fullName: option(string)};
  type node = {composer: option(composer)};
  type edges = {node: option(node)};
  type trackComposers = {
    totalCount: int,
    edges: array(edges),
  };
  type edges_node = {
    id: string,
    title: string,
    duration: int,
    trackNumber: int,
    trackComposers,
  };
  type tracks_edges = {node: option(edges_node)};
  type tracks = {
    totalCount: int,
    edges: array(tracks_edges),
  };
};

open Types;

type fragment = {
  tracks,
  getFragmentRefs:
    unit =>
    {. "__$fragment_ref__SoundtrackMeta_data": SoundtrackMeta_data_graphql.t},
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"tracks_edges_node":{"n":""},"tracks_edges_node_trackComposers_edges_node":{"n":""},"tracks_edges_node_trackComposers_edges_node_composer":{"n":""},"tracks_edges_node_trackComposers_edges_node_composer_fullName":{"n":""},"":{"f":""}}} |}
  ];
  let fragmentConverterMap = ();
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
      "kind": "LinkedField",
      "alias": null,
      "name": "tracks",
      "storageKey": "tracks(orderBy:\"TRACK_NUMBER_ASC\")",
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
                  "name": "trackComposers",
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
    },
    {
      "kind": "FragmentSpread",
      "name": "SoundtrackMeta_data",
      "args": null
    }
  ]
};
})() |}
];
