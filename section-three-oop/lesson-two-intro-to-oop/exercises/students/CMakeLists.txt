cmake_minimum_required(VERSION 3.15)
set(CMAKE_CXX_STANDARD 17)
project(students)

include_directories(include)
add_executable(Students.exe src/main.cpp src/student.cpp)