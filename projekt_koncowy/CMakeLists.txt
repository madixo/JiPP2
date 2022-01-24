cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(projektKoncowy)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-4.0)

link_directories(${GTKMM_LIBRARY_DIRS})

include_directories(${GTKMM_INCLUDE_DIRS})

file(GLOB CPPFILES src/*.cpp)

add_executable(projektKoncowy ${CPPFILES})

include_directories(include)

target_link_libraries(projektKoncowy ${GTKMM_LIBRARIES})