cmake_minimum_required(VERSION 3.3)
project(round_327)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(wizard wizard.cpp)
add_executable(rebranding rebranding.cpp)
