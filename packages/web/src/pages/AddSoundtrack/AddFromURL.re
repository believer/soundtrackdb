module AddFromURLMutation = [%relay.mutation
  {|
  mutation AddFromURLMutation($url: String!) {
    soundtrackPlaylist(url: $url) {
      composers
      imdbId
      playlist
      releaseDate
      soundtrackType
      spotifyId
      title
    }
  }
|}
];

module AddFromURLResponse = {
  [@decco.decode]
  type soundtrackPlaylist = {
    composers: array(string),
    imdbId: option(string),
    spotifyId: option(string),
    playlist: string,
    releaseDate: string,
    soundtrackType: option(string),
    title: string,
  };

  [@decco.decode]
  type t = {soundtrackPlaylist};

  let make = json =>
    switch (t_decode(json)) {
    | Ok(data) => data
    | Error(err) => failwith(err.message)
    };
};

[@react.component]
let make = (~updateData) => {
  let (url, setUrl) = React.useState(() => "");

  <div className="flex items-center rounded-full border-2 border-gray-200">
    <input
      className="w-full py-2 rounded-full px-6 outline-none"
      type_="text"
      placeholder="Soundtrack.net URL"
      onChange={event => {
        let value = event->ReactEvent.Form.target##value;
        setUrl(_ => value);
      }}
      value=url
    />
    <button
      className="p-3 px-4 text-sm bg-blue-500 text-white rounded-full
      focus:outline-none"
      type_="button"
      onClick={_ => {
        Js.Promise.(
          AddFromURLMutation.commitMutation(
            ~environment=RelayEnv.environment,
            ~variables={url: url},
            (),
          )
          |> then_(res => {
               let data = AddFromURLResponse.make(res);
               updateData(data.soundtrackPlaylist);
               setUrl(_ => "");

               resolve();
             })
          |> ignore
        )
      }}>
      {React.string("Send")}
    </button>
  </div>;
};
