Valor
=====

[![Build Status](https://travis-ci.org/binarybirchtree/valor.svg)](https://travis-ci.org/binarybirchtree/valor)

A C++ framework for [Vindinium](http://vindinium.org).

## Instructions

* Install Bazel.

  See the official installation instructions at https://bazel.io/docs/install.html.

* Install dependency libraries.

  ```Shell
  sudo apt-get install libcpprest-dev libgoogle-glog-dev
  ```

* Build the Valor library.

  ```Shell
  bazel build valor
  ```

* Run the unit tests.

  ```Shell
  bazel test --test_output=all tests
  ```

## Author

Binary Birch Tree

## License

[GNU General Public License v3.0](https://www.gnu.org/licenses/gpl-3.0.html)
