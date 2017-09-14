# CppUnitLite
[![Build Status][travis_image]][travis_url]
[![Code Climate][codeclimate_image]][codeclimate_url]
[![Test Coverage][testcoverage_image]][testcoverage_url]
[![MIT License][license-image]][license-url]

Lightweight C++ unit test framework, is based on the original by Michael Feathers.
See http://c2.com/cgi/wiki?CppUnitLite for information.

Follow steps are use command line and under CppUnitLite root directory.

## Build
Required installed cmake.

```
mkdir build
cd build
cmake ..
make
```

## Usage & Sample
After build success, run:  

```shell
./bin/DequeTest
./bin/StackTest
./bin/TemplateDequeTest
```

[travis_image]: https://travis-ci.org/denleyhsiao/CppUnitLite.svg
[travis_url]: https://travis-ci.org/denleyhsiao/CppUnitLite

[codeclimate_image]: https://codeclimate.com/github/denleyhsiao/CppUnitLite/badges/issue_count.svg
[codeclimate_url]: https://codeclimate.com/github/denleyhsiao/CppUnitLite

[testcoverage_image]: https://codeclimate.com/github/denleyhsiao/CppUnitLite/badges/coverage.svg
[testcoverage_url]: https://codeclimate.com/github/denleyhsiao/CppUnitLite

[license-image]: http://img.shields.io/badge/license-MIT-blue.svg?style=flat
[license-url]: LICENSE
