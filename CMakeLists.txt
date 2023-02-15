cmake_minimum_required(VERSION 3.22)

project(cpp-sleep-sort)

add_executable(sleep_sort main.cpp sleep_sort.cpp sleep_sort_test.cpp)

target_compile_features(sleep_sort PRIVATE cxx_std_20)

target_compile_options(sleep_sort PRIVATE
  "$<BUILD_INTERFACE:-Wall;-Wextra;-Wpedantic>"
)

enable_testing()

add_test(NAME Check COMMAND sleep_sort)

# DONE
# make all
# make clean
# make check

# NOT DONE
# make format
# clang
