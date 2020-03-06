module Internal = {
  [@react.component]
  let make = (~children, ~className=?, ~path) => {
    let className = className->Cn.unpack;

    <a
      className
      href="#"
      onClick={e => {
        ReactEvent.Mouse.stopPropagation(e);
        ReactEvent.Mouse.preventDefault(e);
        Route.go(path);
      }}>
      children
    </a>;
  };
};

module External = {
  [@react.component]
  let make = (~children, ~className=?, ~href) => {
    let className =
      Css.(merge(["underline text-sm text-gray-700", className->Cn.unpack]));

    <a className href target="_blank"> children </a>;
  };
};

module NavLink = {
  let isActiveLink = (path, href) => {
    switch (path, href) {
    | ([], "/") => true
    | (p, _) =>
      p
      |> List.exists(pathPart =>
           href |> Js.String.split("/") |> Js.Array.includes(pathPart)
         )
    };
  };

  [@react.component]
  let make = (~className, ~path, ~children) => {
    let url = ReasonReactRouter.useUrl();
    let href = Route.toString(path);
    let isActive = isActiveLink(url.path, href);
    let className =
      Cn.make([className, "bg-gray-200 text-gray-800"->Cn.ifTrue(isActive)]);

    <a
      ariaSelected=isActive
      className
      href
      onClick={e => {
        ReactEvent.Mouse.stopPropagation(e);
        ReactEvent.Mouse.preventDefault(e);
        Route.go(path);
      }}>
      children
    </a>;
  };
};
