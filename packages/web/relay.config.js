module.exports = {
  src: './src',
  schema: './schema.graphql',
  artifactDirectory: './src/__generated__',
  customScalars: {
    Cursor: 'string',
    Datetime: 'string',
  },
}
