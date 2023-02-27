cmake_minimum_required(VERSION 3.22)

project(cpp-sleep-sort)

add_executable(sleep_sort main.cpp sleep_sort.cpp sleep_sort_test.cpp)

target_compile_features(sleep_sort PRIVATE cxx_std_20)

target_compile_options(sleep_sort PRIVATE
  "-Wall;-Wextra;-Wpedantic"
)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(ClangFormat)
set(CLANGFORMAT_EXECUTABLE "clang-format-15")
target_clangformat_setup(sleep_sort)

enable_testing()
add_test(NAME Check COMMAND sleep_sort)

