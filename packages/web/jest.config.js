module.exports = {
  watchPlugins: [
    'jest-watch-typeahead/filename',
    'jest-watch-typeahead/testname',
  ],
  setupFiles: ['<rootDir>/src/setupTests.js'],
  testMatch: ['<rootDir>/__tests__/*_test.bs.js'],
  transformIgnorePatterns: [],
  transform: {
    '^.+\\.jsx?$': 'babel-jest',
  },
}

