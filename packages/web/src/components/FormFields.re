module Text = {
  [@react.component]
  let make =
      (
        ~error: option(Belt.Result.t(Formality.ok, string)),
        ~label as _,
        ~name,
        ~onChange,
        ~placeholder=?,
        ~type_="text",
        ~value,
      ) => {
    <div>
      <input
        className="w-full py-3 text-base bg-transparent border-0 border-b
        border-silver focus:border-eminence transition-border transition"
        id=name
        onChange
        ?placeholder
        type_
        value
      />
      {switch (error) {
       | Some(Error(message)) =>
         <div className="text-guardsman-red mt-2"> message->React.string </div>
       | Some(Ok(Valid))
       | Some(Ok(NoValue))
       | None => React.null
       }}
    </div>;
  };
};
