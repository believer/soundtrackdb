exception Grapql_error(string);

let fetchQuery: ReasonRelay.Network.fetchFunctionPromise =
  (operation, variables, _cacheConfig) => {
    Fetch.(
      fetchWithInit(
        "http://localhost:5000/graphql",
        RequestInit.make(
          ~method_=Post,
          ~body=
            Js.Dict.fromList([
              ("query", Js.Json.string(operation.text)),
              ("variables", variables),
            ])
            |> Js.Json.object_
            |> Js.Json.stringify
            |> BodyInit.make,
          ~headers=
            HeadersInit.make({
              "content-type": "application/json",
              "accept": "application/json",
            }),
          (),
        ),
      )
      |> Js.Promise.then_(resp =>
           if (Response.ok(resp)) {
             Response.json(resp);
           } else {
             Js.Promise.reject(Grapql_error("Nope"));
           }
         )
    );
  };

let network =
  ReasonRelay.Network.makePromiseBased(~fetchFunction=fetchQuery, ());

let environment =
  ReasonRelay.Environment.make(
    ~network,
    ~store=
      ReasonRelay.Store.make(~source=ReasonRelay.RecordSource.make(), ()),
    (),
  );
