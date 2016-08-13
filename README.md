Valor
=====

[![Build Status](https://travis-ci.org/binarybirchtree/valor.svg)](https://travis-ci.org/binarybirchtree/valor)

A C++ framework for [Vindinium](http://vindinium.org).

## Building the library

### Install Bazel

See the official installation instructions at https://bazel.io/docs/install.html.

### Install dependency libraries

```Shell
sudo apt install libcpprest-dev libgoogle-glog-dev
```

### Build the Valor library

```Shell
bazel build valor
```

## Running the unit tests

```Shell
bazel test --test_output=all tests
```

## Running the example client

### Customize the configuration

To use a local Vindinium server:

* Follow the official instructions from https://github.com/ornicar/vindinium to set up a local Vindinium server.

* Obtain an API key from http://localhost:9000/register.

* Update the `key` value in `example/config.json` accordingly.

To use the public Vindinium server:

* Obtain an API key from http://vindinium.org/register.

* Update the `key` and `server` values in `example/config.json` accordingly.

### Run the client

```Shell
bazel run example $(readlink -f example/config.json)
```

### View the simulation

Upon successfully starting a new simulation, the example client will output the corresponding URL in the following format:

```
View URL: http://localhost:9000/abcdefgh
```

## Author

Binary Birch Tree

## License

[GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.html)
