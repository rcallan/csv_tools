cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS statistics.cpp)
add_executable(statistics ${SRCS})
target_link_libraries(statistics lib)

install (TARGETS statistics DESTINATION "${PROJECT_SOURCE_DIR}/bin/")