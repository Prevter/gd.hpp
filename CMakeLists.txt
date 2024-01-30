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

add_library(gd.hpp INTERFACE)
target_include_directories(gd.hpp INTERFACE "include")

add_library(gd.hpp::gd.hpp ALIAS gd.hpp)