cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

include_directories(../firstLib/include)

add_executable(firstLibCall main.cpp)

target_link_libraries(firstLibCall firstLib)
