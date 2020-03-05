/* @generated */

module Unions = {};

module Types = {
  type node = {
    createdAt: string,
    id: string,
    title: string,
    getFragmentRefs:
      unit =>
      {
        .
        "__$fragment_ref__Composer_soundtrack": Composer_soundtrack_graphql.t,
      },
  };
  type edges = {node: option(node)};
  type latestSoundtracks = {edges: array(edges)};
};

open Types;

type fragment = {latestSoundtracks: option(latestSoundtracks)};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"latestSoundtracks":{"n":""},"latestSoundtracks_edges_node":{"n":"","f":""}}} |}
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
  {.. "__$fragment_ref__LatestSoundtracks_soundtracks": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

module Utils = {};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%bs.raw
  {| {
  "kind": "Fragment",
  "name": "LatestSoundtracks_soundtracks",
  "type": "Query",
  "metadata": null,
  "argumentDefinitions": [],
  "selections": [
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
} |}
];
