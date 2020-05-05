cmake_minimum_required(VERSION 3.15)
project(pyramid)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(Pyramid src/main.cpp src/pyramid.cpp)