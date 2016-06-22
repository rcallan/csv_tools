cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS csvjointool.cpp)
add_executable(csvjointool ${SRCS})
target_link_libraries(csvjointool lib)

install (TARGETS csvjointool DESTINATION "${PROJECT_SOURCE_DIR}/bin/")