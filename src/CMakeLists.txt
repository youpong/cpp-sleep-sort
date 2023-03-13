add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_20)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wpedantic>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

add_executable(sleep_sort main.cpp sleep_sort.cpp sleep_sort_test.cpp)
target_link_libraries(sleep_sort PUBLIC compiler_flags)

option(ENABLE_FORMAT "Enable format" OFF)
if (ENABLE_FORMAT)
    list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
    include(ClangFormat)
    target_clangformat_setup(sleep_sort)
endif()

enable_testing()
add_test(NAME Check COMMAND sleep_sort)
