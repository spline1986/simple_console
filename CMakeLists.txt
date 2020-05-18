cmake_minimum_required(VERSION 3.0)

project(console CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(demo sources/demo.cpp)
