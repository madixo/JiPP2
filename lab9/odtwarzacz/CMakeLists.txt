cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(odtwarzacz)

file(GLOB CPPFILES src/*.cpp)

add_executable(odtwarzacz ${CPPFILES})

include_directories(include)