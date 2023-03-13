# README.md
[![ci](https://github.com/youpong/cpp-sleep-sort/actions/workflows/ci.yml/badge.svg)](https://github.com/youpong/cpp-sleep-sort/actions/workflows/ci.yml)

The C++20 implementation of Sleep Sort using std::thread.

## Prerequisites

The following versions or newer required.

* CMake 3.22
* GNU Make-4.3
* C++20 compliant compiler: clang-15.0.6, g++-11.3.0 or MS Visual Studio 2022
* clang-format-15.0.6
* Doxygen-1.9.1
* Graphviz-2.43.0

## Usage

1. Generate the build system and navigate to the directory:

```bash
$ cmake -Bbuild
```
optoins(default):
* BUILD\_DOC(OFF): Build API Documents
* ENABLE\_FORMAT(OFF): Enable Format sources

Example:
```
$ cmake -DBUILD_DOC=ON -DENABLE_FORMAT=ON -Bbuild
```

2. build and test:

When `BUILD_DOC` is ON, API document is also generated.

```bash
$ cd build
$ cmake --build . -j
$ ctest -C Debug
```

3. Format sources anytime using `clangformat` target:

requires `ENABLE_FORMAT` is `ON`.

```bash
$ cmake --build . --target clangformat
```

## Docker

1. Build Docker image:
```bash
$ docker build -t sleep-sort .
```

2. Run Docker container:
```bash
$ docker run --rm -it -v $PWD:/sleep-sort -w /sleep-sort sleep-sort
```

## References

* [Go implementation](https://github.com/youpong/sleep-sort) of sleep sort.
* zemasoft, [ClangFormat.cmake module](https://github.com/zemasoft/clangformat-cmake)

## Lisence

MIT

