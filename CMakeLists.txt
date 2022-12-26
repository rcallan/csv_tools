cmake_minimum_required(VERSION 3.16)

project(csvtools LANGUAGES CXX C VERSION 0.2.0)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "-std=c++2a -pthread -Wall -Wno-sign-compare")

add_subdirectory(lib)

add_subdirectory(tools/columnselector)
add_subdirectory(tools/arith)
add_subdirectory(tools/joiner)
add_subdirectory(tools/statistics)
add_subdirectory(tools/show)
add_subdirectory(tools/ml)

add_subdirectory(tools/backtester)

install(DIRECTORY DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
