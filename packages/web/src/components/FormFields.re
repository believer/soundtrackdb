module Text = {
  [@react.component]
  let make =
      (
        ~error: option(Belt.Result.t(Formality.ok, string)),
        ~label as _,
        ~name,
        ~onChange,
        ~placeholder=?,
        ~helper=?,
        ~className=?,
        ~type_="text",
        ~value,
      ) => {
    <div>
      <input
        className={Cn.make([
          "w-full py-2 text-base bg-transparent border-0 border-b
       transition-border transition text-sm focus:outline-none",
          className->Cn.unpack,
        ])}
        name
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
      {switch (helper) {
       | Some(helper) =>
         <div className="text-xs text-gray-500 mt-2"> helper </div>
       | None => React.null
       }}
    </div>;
  };
};
