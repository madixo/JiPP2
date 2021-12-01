cmake_minimum_required(VERSION 3.16)

set(CMAKE_CSS_STANDARD 17)

project(Notes)

file(GLOB CPPFILES src/*.cpp)

add_executable(Notes ${CPPFILES})

include_directories(include)
