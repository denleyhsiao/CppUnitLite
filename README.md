# CppUnitLite
[![Build Status][travis_image]][travis_url]
[![Code Climate][codeclimate_image]][codeclimate_url]
[![Test Coverage][testcoverage_image]][testcoverage_url]
[![MIT License][license-image]][license-url]

[中文](README_cn.md)

Lightweight C++ unit test framework, is based on the original by Michael Feathers.
See [more](http://c2.com/cgi/wiki?CppUnitLite).

## Install
Require installed cmake
### By brew
```bash
brew tap denleyhsiao/tap && brew install CppUnitLite
```

### By source
1. Download source: `git clone https://github.com/denleyhsiao/CppUnitLite`
2. Modify configure: `ccmake .`
    - BUILD_STATIC_LIBRARY： Build static or shared library, default static
    - ENABLE_MEMORYLEAKWARN：Open or close memory leak warn check，default open
3. Build & install

```bash
cmake .
make
make install
```
4. Uninstall：`cat install_manifest.txt | sudo xargs rm`

## Run
This is a unit test application based deque ：`DequeTest`，and use CppUnitLite as unit test framework. 
It include follow files:

| filename |description |
|---|---|
|main.cpp|main file|
|DequeLiteTest.cpp|unit test file with self-define SetUp/TearDown|
|DequeTest.cpp|unit test file with default SetUp/TearDown|
|Deque.h/Deque.cpp|deque define & implement file|
    
[travis_image]: https://travis-ci.org/denleyhsiao/CppUnitLite.svg
[travis_url]: https://travis-ci.org/denleyhsiao/CppUnitLite

[codeclimate_image]: https://codeclimate.com/github/denleyhsiao/CppUnitLite/badges/issue_count.svg
[codeclimate_url]: https://codeclimate.com/github/denleyhsiao/CppUnitLite

[testcoverage_image]: https://codeclimate.com/github/denleyhsiao/CppUnitLite/badges/coverage.svg
[testcoverage_url]: https://codeclimate.com/github/denleyhsiao/CppUnitLite

[license-image]: http://img.shields.io/badge/license-MIT-blue.svg?style=flat
[license-url]: LICENSE
