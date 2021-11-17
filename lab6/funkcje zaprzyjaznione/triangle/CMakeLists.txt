cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(Triangle)

file(GLOB CPPFILES src/*.cpp)

add_executable(Triangle ${CPPFILES})

include_directories(include)