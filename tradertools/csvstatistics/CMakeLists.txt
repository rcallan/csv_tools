cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS csvstatistics.cpp)
add_executable(csvstatistics ${SRCS})
target_link_libraries(csvstatistics lib)

install (TARGETS csvstatistics DESTINATION "${PROJECT_SOURCE_DIR}/bin/")