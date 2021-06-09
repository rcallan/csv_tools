cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_COMPILER "g++-10")

set(CMAKE_CXX_FLAGS "-std=c++20 -pthread")

add_subdirectory(lib)

add_subdirectory(csvtools/csvcolumnselector)
add_subdirectory(csvtools/csvarith)
add_subdirectory(csvtools/csvjointool)
add_subdirectory(csvtools/csvstatistics)
add_subdirectory(csvtools/showcsv)
add_subdirectory(csvtools/csvml)

install(DIRECTORY DESTINATION "${PROJECT_SOURCE_DIR}/bin/")