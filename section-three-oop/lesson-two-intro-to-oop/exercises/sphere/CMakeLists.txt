cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)

project(sphere)

include_directories(include)
add_executable(Sphere.exe src/main.cpp src/sphere.cpp)