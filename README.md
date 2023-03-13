# README.md

The C++20 implementation of Sleep Sort using std::thread.

## Prerequisites

The following versions or newer required.

* CMake 3.22
* GNU Make-4.3
* C++20 compliant compiler: clang-15.0.6 or g++-11.3.0
* clang-format-15.0.6
* Doxygen-1.9.1
* Graphviz-2.43.0

## Usage

1. Generate the build system and navigate to the directory:
```bash
$ cmake -Bbuild
$ cd build
```

2. build and test:
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

## References

* [Go implementation](https://github.com/youpong/sleep-sort) of sleep sort.
* zemasoft, [ClangFormat.cmake module](https://github.com/zemasoft/clangformat-cmake)

## Lisence

MIT

