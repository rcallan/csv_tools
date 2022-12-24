cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "-std=c++2a -pthread")

add_subdirectory(lib)

add_subdirectory(tools/columnselector)
add_subdirectory(tools/arith)
add_subdirectory(tools/joiner)
add_subdirectory(tools/statistics)
add_subdirectory(tools/show)
add_subdirectory(tools/ml)

add_subdirectory(tools/backtester)

install(DIRECTORY DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
