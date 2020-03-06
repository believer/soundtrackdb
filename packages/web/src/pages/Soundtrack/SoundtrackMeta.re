module SoundtrackMetaFragment = [%relay.fragment
  {|
  fragment SoundtrackMeta_data on Soundtrack {
    imdbId
    spotifyId
    releaseDate
  }
|}
];

[@react.component]
let make = (~query as queryRef, ~totalTracks, ~totalDuration) => {
  let meta = SoundtrackMetaFragment.use(queryRef);

  <div>
    <MetaBlock title="Release date">
      <DateTime date={meta.releaseDate} format=DateTime.Format.FullDate />
    </MetaBlock>
    <MetaBlock title="Number of tracks">
      {totalTracks->Belt.Int.toString->React.string}
    </MetaBlock>
    <div className="mb-12">
      <MetaBlock title="Playtime"> {React.string(totalDuration)} </MetaBlock>
    </div>
    {switch (meta.imdbId) {
     | Some(id) =>
       <Link.External className="mr-2" href={IMDb.Link.make(id)}>
         {React.string("IMDb")}
       </Link.External>
     | None => React.null
     }}
    {switch (meta.spotifyId) {
     | Some(id) =>
       <Link.External href={Spotify.Link.make(id)}>
         {React.string("Spotify")}
       </Link.External>
     | None => React.null
     }}
  </div>;
};
