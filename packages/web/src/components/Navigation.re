[@react.component]
let make = () => {
  <div className="bg-gray-800">
    <div className="grid grid-template-1140">
      <div
        className="grid-column-center flex items-center justify-between h-16">
        <div className="flex items-center">
          <div className="hidden md:block">
            <div className="flex items-baseline">
              <Link.NavLink
                path=Route.Index
                className="px-3 py-2 rounded-md text-sm font-medium
              text-white focus:outline-none focus:text-white
              focus:bg-gray-700">
                {React.string("Home")}
              </Link.NavLink>
              <Link.NavLink
                path=Route.Stats
                className="ml-4 px-3 py-2 rounded-md text-sm
              font-medium text-gray-300 hover:text-white hover:bg-gray-700
              focus:outline-none focus:text-white focus:bg-gray-700">
                {React.string("Stats")}
              </Link.NavLink>
            </div>
          </div>
        </div>
        <div>
          <Link.Internal className="text-white" path=Route.AddSoundtrack>
            <svg
              xmlns="http://www.w3.org/2000/svg"
              viewBox="0 0 20 20"
              className="fill-current w-5 h-5">
              <path
                d="M11 9h4v2h-4v4H9v-4H5V9h4V5h2v4zm-1 11a10 10 0 1 1 0-20 10 10 0 0 1 0 20zm0-2a8 8 0 1 0 0-16 8 8 0 0 0 0 16z"
              />
            </svg>
          </Link.Internal>
        </div>
      </div>
    </div>
  </div>;
};
