cmake_minimum_required(VERSION 3.15)
project(gd.hpp CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE GD_HPP_HEADERS "include/*.hpp" "include/*.h")
file(GLOB_RECURSE GD_HPP_SOURCES "src/*.cpp")

add_library(gd.hpp INTERFACE ${GD_HPP_HEADERS} ${GD_HPP_SOURCES})
target_include_directories(gd.hpp INTERFACE "include")
target_compile_features(gd.hpp INTERFACE cxx_std_17)