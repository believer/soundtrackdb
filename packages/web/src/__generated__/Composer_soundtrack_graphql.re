/* @generated */

module Unions = {};

module Types = {
  type composerByComposerId = {
    fullName: option(string),
    id: string,
  };
  type node = {composerByComposerId: option(composerByComposerId)};
  type edges = {node: option(node)};
  type soundtrackComposersBySoundtrackId = {edges: array(edges)};
};

open Types;

type fragment = {soundtrackComposersBySoundtrackId};

module FragmentConverters: {} = {};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(array((int, string))) = [%raw
    {| {"soundtrackComposersBySoundtrackId_edges_node":[[0,""]],"soundtrackComposersBySoundtrackId_edges_node_composerByComposerId":[[0,""]],"soundtrackComposersBySoundtrackId_edges_node_composerByComposerId_fullName":[[0,""]]} |}
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
  {.. "__$fragment_ref__Composer_soundtrack": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%bs.raw
  {| {
  "kind": "Fragment",
  "name": "Composer_soundtrack",
  "type": "Soundtrack",
  "metadata": null,
  "argumentDefinitions": [],
  "selections": [
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
                    },
                    {
                      "kind": "ScalarField",
                      "alias": null,
                      "name": "id",
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
} |}
];
