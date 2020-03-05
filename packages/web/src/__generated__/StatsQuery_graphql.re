/* @generated */

module Unions = {};

module Types = {
  type stats = {
    getFragmentRefs:
      unit =>
      {
        .
        "__$fragment_ref__StatsComposers_composers": StatsComposers_composers_graphql.t,
        "__$fragment_ref__StatsYears_years": StatsYears_years_graphql.t,
        "__$fragment_ref__StatsCategories_categories": StatsCategories_categories_graphql.t,
      },
  };
};

open Types;

type response = {
  stats,
  getFragmentRefs:
    unit => {. "__$fragment_ref__StatsBigNumbers": StatsBigNumbers_graphql.t},
};
type variables = unit;

module Internal = {
  type responseRaw;
  let responseConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {| {"__root":{"stats":{"f":""},"":{"f":""}}} |}
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
  "name": "count",
  "args": null,
  "storageKey": null
};
return {
  "kind": "Request",
  "fragment": {
    "kind": "Fragment",
    "name": "StatsQuery",
    "type": "Query",
    "metadata": null,
    "argumentDefinitions": [],
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "stats",
        "storageKey": null,
        "args": null,
        "concreteType": "Stats",
        "plural": false,
        "selections": [
          {
            "kind": "FragmentSpread",
            "name": "StatsComposers_composers",
            "args": null
          },
          {
            "kind": "FragmentSpread",
            "name": "StatsYears_years",
            "args": null
          },
          {
            "kind": "FragmentSpread",
            "name": "StatsCategories_categories",
            "args": null
          }
        ]
      },
      {
        "kind": "FragmentSpread",
        "name": "StatsBigNumbers",
        "args": null
      }
    ]
  },
  "operation": {
    "kind": "Operation",
    "name": "StatsQuery",
    "argumentDefinitions": [],
    "selections": [
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "soundtracks",
        "storageKey": null,
        "args": null,
        "concreteType": "SoundtracksConnection",
        "plural": false,
        "selections": [
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "totalCount",
            "args": null,
            "storageKey": null
          }
        ]
      },
      {
        "kind": "LinkedField",
        "alias": null,
        "name": "stats",
        "storageKey": null,
        "args": null,
        "concreteType": "Stats",
        "plural": false,
        "selections": [
          {
            "kind": "ScalarField",
            "alias": null,
            "name": "totalDuration",
            "args": null,
            "storageKey": null
          },
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "composers",
            "storageKey": null,
            "args": null,
            "concreteType": "ComposerStat",
            "plural": true,
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
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "years",
            "storageKey": null,
            "args": null,
            "concreteType": "YearStat",
            "plural": true,
            "selections": [
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "year",
                "args": null,
                "storageKey": null
              },
              (v0/*: any*/)
            ]
          },
          {
            "kind": "LinkedField",
            "alias": null,
            "name": "categories",
            "storageKey": null,
            "args": null,
            "concreteType": "Categories",
            "plural": false,
            "selections": [
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "movie",
                "args": null,
                "storageKey": null
              },
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "game",
                "args": null,
                "storageKey": null
              },
              {
                "kind": "ScalarField",
                "alias": null,
                "name": "tv",
                "args": null,
                "storageKey": null
              }
            ]
          }
        ]
      }
    ]
  },
  "params": {
    "operationKind": "query",
    "name": "StatsQuery",
    "id": null,
    "text": "query StatsQuery {\n  ...StatsBigNumbers\n  stats {\n    ...StatsComposers_composers\n    ...StatsYears_years\n    ...StatsCategories_categories\n  }\n}\n\nfragment StatsBigNumbers on Query {\n  soundtracks {\n    totalCount\n  }\n  stats {\n    totalDuration\n  }\n}\n\nfragment StatsCategories_categories on Stats {\n  categories {\n    movie\n    game\n    tv\n  }\n}\n\nfragment StatsComposers_composers on Stats {\n  composers {\n    fullName\n    count\n  }\n}\n\nfragment StatsYears_years on Stats {\n  years {\n    year\n    count\n  }\n}\n",
    "metadata": {}
  }
};
})() |}
];
