[@react.component]
let make = () => {
  <div className="border-b-2 border-gray-200">
    <div className="grid grid-template-1140">
      <div
        className="grid-column-center flex items-center justify-between h-16">
        <div className="flex items-center">
          <div className="hidden md:block">
            <div className="flex items-baseline">
              <Link.NavLink
                path=Route.Index
                className="px-3 py-2 rounded-md text-sm font-medium
              text-gray-600 focus:outline-none focus:bg-gray-200">
                {React.string("Home")}
              </Link.NavLink>
              <Link.NavLink
                path=Route.Stats
                className="ml-4 px-3 py-2 rounded-md text-sm
              font-medium text-gray-600
              focus:outline-none focus:bg-gray-200">
                {React.string("Stats")}
              </Link.NavLink>
            </div>
          </div>
        </div>
        <div>
          <Link.Internal className="text-gray-600" path=Route.AddSoundtrack>
            <Icon.Add className="h-5 w-5" />
          </Link.Internal>
        </div>
      </div>
    </div>
  </div>;
};
