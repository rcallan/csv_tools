cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_COMPILER "g++-10")

set(CMAKE_CXX_FLAGS "-std=c++20 -pthread")

add_subdirectory(lib)

add_subdirectory(tradertools/csvcolumnselector)
add_subdirectory(tradertools/csvarith)
add_subdirectory(tradertools/csvjointool)
add_subdirectory(tradertools/csvstatistics)
add_subdirectory(tradertools/showcsv)
add_subdirectory(tradertools/csvml)

add_subdirectory(tradertools/backtester)

install(DIRECTORY DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
