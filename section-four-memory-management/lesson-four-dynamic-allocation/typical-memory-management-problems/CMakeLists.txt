cmake_minimum_required(VERSION 3.15 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)

project(memoryLeaks)

add_executable(memoryLeaks memory_leaks_debugging.cpp)