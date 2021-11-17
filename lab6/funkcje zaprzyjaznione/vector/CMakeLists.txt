cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(Vector)

add_executable(Vector src/main.cpp src/Vector.cpp)

include_directories(include)