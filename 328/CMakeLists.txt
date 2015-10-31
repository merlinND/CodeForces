cmake_minimum_required(VERSION 3.3)
project(round_328)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(chess chess.cpp)
add_executable(monster monster.cpp)
add_executable(race race.cpp)