# CppUnitLite
[![Build Status][travis_image]][travis_url]
[![Code Climate][codeclimate_image]][codeclimate_url]
[![Test Coverage][testcoverage_image]][testcoverage_url]
[![MIT License][license-image]][license-url]

[中文](README_cn.md)

Lightweight C++ unit test framework, is based on the original by Michael Feathers.
See [more](http://c2.com/cgi/wiki?CppUnitLite).

## build & install
Require installed cmake

```bash
mkdir -p build
cd build
cmake ..
make
make install
```
NOTE：uninstall：`cat install_manifest.txt | sudo xargs rm`

### configure
Before `cmake ..`, run `ccmake ..` to modify configure
* ENABLE_MEMORYLEAKWARN：ENABLE or DISABLE memory leak warn check，default ENABLE

## run
This is a unit test application based deque ：`DequeTest`，and use CppUnitLite as unit test framework. 
It include follow files:
- Main.cpp: main file 
- DequeLiteTest.cpp:  unit test file with self-define SetUp/TearDown
- DequeTest.cpp: unit test file with default SetUp/TearDown
- Deque.h/Deque.cpp: deque define & implement file
    
[travis_image]: https://travis-ci.org/denleyhsiao/CppUnitLite.svg
[travis_url]: https://travis-ci.org/denleyhsiao/CppUnitLite

[codeclimate_image]: https://codeclimate.com/github/denleyhsiao/CppUnitLite/badges/issue_count.svg
[codeclimate_url]: https://codeclimate.com/github/denleyhsiao/CppUnitLite

[testcoverage_image]: https://codeclimate.com/github/denleyhsiao/CppUnitLite/badges/coverage.svg
[testcoverage_url]: https://codeclimate.com/github/denleyhsiao/CppUnitLite

[license-image]: http://img.shields.io/badge/license-MIT-blue.svg?style=flat
[license-url]: LICENSE
