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
