cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_COMPILER "g++")

set(CMAKE_CXX_FLAGS "-std=c++11")

add_subdirectory(lib)

add_subdirectory(csvtools/csvcolumnselector)
add_subdirectory(csvtools/csvarith)
add_subdirectory(csvtools/csvjointool)
add_subdirectory(csvtools/csvstatistics)
add_subdirectory(csvtools/showcsv)

install(DIRECTORY DESTINATION "${PROJECT_SOURCE_DIR}/bin/")