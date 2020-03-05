const webpack = require('webpack')
const CleanTerminalPlugin = require('clean-terminal-webpack-plugin')
const CopyWebpackPlugin = require('copy-webpack-plugin')
const HtmlWebpackPlugin = require('html-webpack-plugin')
const path = require('path')

const outputDir = path.join(__dirname, 'assets')

module.exports = {
  mode: 'development',
  output: {
    path: outputDir,
    publicPath: '/',
    filename: 'index.[hash].js',
  },
  plugins: [
    new CleanTerminalPlugin(),
    new HtmlWebpackPlugin({
      template: 'public/index.html',
    }),
    new CopyWebpackPlugin([
      {
        from: path.join(__dirname, './public/assets/**/*'),
        to: '',
        transformPath(targetPath, absolutePath) {
          return targetPath
            .split('/')
            .slice(1)
            .join('/')
        },
      },
    ]),
    new webpack.DefinePlugin({
      __DEV__: JSON.stringify(process.env.NODE_ENV !== 'production'),
    }),
  ],
  devServer: {
    compress: true,
    contentBase: outputDir,
    port: process.env.PORT || 8000,
    historyApiFallback: true,
    stats: 'minimal',
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          'style-loader',
          { loader: 'css-loader', options: { importLoaders: 1 } },
          'postcss-loader',
        ],
      },
    ],
  },
}
