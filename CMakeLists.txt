cmake_minimum_required(VERSION 3.28)
project(Breakout__)

set(CMAKE_CXX_STANDARD 20)

add_library(Breakout__ STATIC game.cpp)

add_executable(breakoutexe game.cpp)