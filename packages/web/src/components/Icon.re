module Trash = {
  [@react.component]
  let make = (~className=?) => {
    <svg
      className={Cn.make(["h-4 w-4", className->Cn.unpack])}
      viewBox="0 0 64 64"
      fill="none"
      xmlns="http://www.w3.org/2000/svg">
      <path
        d="M52.5 10l-2.9 47.1a5 5 0 01-4.9 4.9H19.3a5 5 0 01-4.9-4.9L11.5 10M6 10h52H6zm16 0V5.9A3.9 3.9 0 0125.9 2h12.2A3.9 3.9 0 0142 5.9V10H22zM42 18l-2 36m-8-36v36-36zm-10 0l2 36-2-36z"
        stroke="#202020"
        strokeWidth="2"
        strokeMiterlimit="10"
        strokeLinecap="round"
        strokeLinejoin="round"
      />
    </svg>;
  };
};

module Add = {
  [@react.component]
  let make = (~className=?) => {
    <svg
      className={Cn.make(["h-4 w-4", className->Cn.unpack])}
      viewBox="0 0 27 27"
      fill="none"
      xmlns="http://www.w3.org/2000/svg">
      <g clipPath="url(#clip0)">
        <path
          d="M13.5 26.1562C20.4899 26.1562 26.1562 20.4899 26.1562 13.5C26.1562 6.51015 20.4899 0.84375 13.5 0.84375C6.51015 0.84375 0.84375 6.51015 0.84375 13.5C0.84375 20.4899 6.51015 26.1562 13.5 26.1562Z"
          stroke="currentColor"
          strokeWidth="2"
          strokeMiterlimit="10"
          strokeLinecap="round"
          strokeLinejoin="round"
        />
        <path
          d="M20.25 13.5H6.75M13.5 6.75V20.25V6.75Z"
          stroke="currentColor"
          strokeWidth="2"
          strokeMiterlimit="10"
          strokeLinecap="round"
          strokeLinejoin="round"
        />
      </g>
      <defs>
        <clipPath id="clip0">
          <rect width="27" height="27" fill="white" />
        </clipPath>
      </defs>
    </svg>;
  };
};

module Search = {
  [@react.component]
  let make = (~className=?) => {
    <svg
      className={Cn.make(["h-4 w-4", className->Cn.unpack])}
      viewBox="0 0 64 64"
      fill="none"
      xmlns="http://www.w3.org/2000/svg">
      <path
        d="M39.0491 39.049L56.0001 56"
        stroke="currentColor"
        strokeWidth="2"
        strokeMiterlimit="10"
        strokeLinecap="round"
        strokeLinejoin="round"
      />
      <path
        d="M27 44C36.3888 44 44 36.3888 44 27C44 17.6112 36.3888 10 27 10C17.6112 10 10 17.6112 10 27C10 36.3888 17.6112 44 27 44Z"
        stroke="currentColor"
        strokeWidth="2"
        strokeMiterlimit="10"
        strokeLinecap="round"
        strokeLinejoin="round"
      />
    </svg>;
  };
};
