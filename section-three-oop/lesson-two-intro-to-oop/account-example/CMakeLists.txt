cmake_minimum_required(VERSION 3.15)
project(account-example)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(ACCOUNTS src/main.cpp src/account.cpp src/transfer.cpp)