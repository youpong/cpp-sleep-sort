# README.md

The C++20 implementation of Sleep Sort.

## Prerequisites

The following versions or newer required.

* CMake 3.22
* GNU Make-4.3
* g++-11.3.0 or clang++-15.0.6
* clang-format-15.0.6

## Usage

1. Generate the build system:
```bash
$ mkdir build
$ cd build
$ cmake ..
```

2. test:
```bash
$ cmake --build . -j
$ ctest
```

3. Format sources anytime using `clangformat` target:
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

3. Set environment variables:
```bash
$ export CC=clang-15
$ export CXX=clang++-15
```

## References

* [Go implementation](https://github.com/youpong/sleep-sort)
* zemasoft, [ClangFormat.cmake module](https://github.com/zemasoft/clangformat-cmake)

## Lisence

MIT

