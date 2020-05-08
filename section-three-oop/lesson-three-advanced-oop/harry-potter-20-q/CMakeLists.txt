cmake_minimum_required(VERSION 3.15)
project(harry-potter-20-q)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(Quiz.exe src/main.cpp src/houses.cpp src/school.cpp)