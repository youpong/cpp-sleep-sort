cmake_minimum_required(VERSION 3.22)

project(cpp-sleep-sort
    VERSION 0.0.1)

add_subdirectory(src)

enable_testing()


option(BUILD_DOC "Build documentation" OFF)
if (BUILD_DOC)
    find_package(Doxygen REQUIRED)
    if (DOXYGEN_FOUND AND DOXYGEN_DOT_FOUND)
        set(DOXYGEN_IN  ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
        set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
        configure_file( ${DOXYGEN_IN}
                        ${DOXYGEN_OUT} @ONLY)
        message("Doxygen build started")
        add_custom_target( doc_doxygen ALL
            COMMAND           ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT           "Generating API documentation with Doxygen"
            VERBATIM )
    else ()
        message("Doxygen need to be installed to generate the doxygen documentation")
    endif ()
endif()
