module AddFromURLMutation = [%relay.mutation
  {|
  mutation AddFromURLMutation($url: String!) {
    soundtrackPlaylist(url: $url) {
      composers
      imdbId
      playlist
      releaseDate
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

  <div className="flex items-center">
    <input
      className="border-b w-full mr-8 py-3"
      type_="text"
      placeholder="Soundtrack.net URL"
      onChange={event => {setUrl(_ => event->ReactEvent.Form.target##value)}}
      value=url
    />
    <button
      className="px-4 py-2 bg-blue-200"
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
