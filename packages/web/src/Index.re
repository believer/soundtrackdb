ReactExperimental.renderConcurrentRootAtElementWithId(
  <ReasonRelay.Context.Provider environment=RelayEnv.environment>
    <ReactExperimental.Suspense
      fallback={<div> {React.string("Loading")} </div>}>
      <App />
    </ReactExperimental.Suspense>
  </ReasonRelay.Context.Provider>,
  "root",
);
