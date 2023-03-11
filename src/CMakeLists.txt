add_executable(sleep_sort main.cpp sleep_sort.cpp sleep_sort_test.cpp)

target_compile_features(sleep_sort PRIVATE cxx_std_20)

target_compile_options(sleep_sort PRIVATE
  "-Wall;-Wextra;-Wpedantic"
)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(ClangFormat)
target_clangformat_setup(sleep_sort)

enable_testing()
add_test(NAME Check COMMAND sleep_sort)