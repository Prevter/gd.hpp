cmake_minimum_required(VERSION 3.15)
project(
    gd.hpp
    VERSION 1.0.0
    DESCRIPTION "Version-agnostic library for Geometry Dash"
    HOMEPAGE_URL "https://github.com/prevter/gd.hpp"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE GD_HPP_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE GD_HPP_SOURCES "src/*.cpp")

add_library(gd.hpp INTERFACE ${GD_HPP_HEADERS} ${GD_HPP_SOURCES})
target_include_directories(gd.hpp INTERFACE "include")
target_link_libraries(
    gd.hpp INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/libs/fmod.lib
)