cmake_minimum_required(VERSION 3.3)
project(round_331)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(pool pool.cpp)
add_executable(array array.cpp)
add_executable(points points.cpp)
