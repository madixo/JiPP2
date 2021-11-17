cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(Pojazd)

add_executable(Pojazd src/main.cpp src/Pojazd.cpp)

include_directories(include)