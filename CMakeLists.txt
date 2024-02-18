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

file(GLOB_RECURSE GD_HPP_SOURCES "src/*.cpp" "include/*.hpp" "include/*.h")

add_library(gd.hpp STATIC ${GD_HPP_SOURCES})

target_include_directories(gd.hpp PUBLIC include)
target_link_libraries(
    gd.hpp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/libs/fmod.lib
)

add_library(gd.hpp::gd.hpp ALIAS gd.hpp)