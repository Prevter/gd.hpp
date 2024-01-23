cmake_minimum_required(VERSION 3.15)
project(
    gd.hpp
    VERSION 0.1.0
    DESCRIPTION "Version-agnostic library for Geometry Dash"
    HOMEPAGE_URL "https://github.com/prevter/gd.hpp"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_library(gd.hpp SHARED ${SOURCES})
target_include_directories(gd.hpp PUBLIC "include")

add_library(gd.hpp::gd.hpp ALIAS gd.hpp)

add_subdirectory("external/minhook")
target_link_libraries(gd.hpp PRIVATE minhook)

set_target_properties(
    gd.hpp PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
    PUBLIC_HEADER "include/gd.hpp"
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

# If target is Android, set the output name to gd (it automatically adds "lib" prefix)
if(ANDROID)
    set_target_properties(
        gd.hpp PROPERTIES
        OUTPUT_NAME "gd"
    )
else()
    set_target_properties(
        gd.hpp PROPERTIES
        OUTPUT_NAME "libgd"
    )
endif()