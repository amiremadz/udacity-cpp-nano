cmake_minimum_required(VERSION 3.15)
project(animal)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
add_executable(Animal src/main.cpp src/animal.cpp src/cat.cpp src/snake.cpp)