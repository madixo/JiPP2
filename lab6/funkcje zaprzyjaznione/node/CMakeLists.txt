cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(Node)

add_executable(Node src/main.cpp src/Node.cpp)

include_directories(include)