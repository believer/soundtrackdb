type t =
  | Display
  | Hidden;

let useToggle = () => {
  let (state, setState) = React.useState(() => Hidden);

  let toggle = () => setState(_ => state === Display ? Hidden : Display);

  (state, toggle);
};
