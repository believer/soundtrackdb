type t = {
  title: string,
  duration: string,
};

let makeEmpty = () => {title: "", duration: ""};
let make = (~title, ~duration) => {title, duration};
