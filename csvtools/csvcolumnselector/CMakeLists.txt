cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS csvcolumnselector.cpp)
add_executable(csvcolumnselector ${SRCS})
target_link_libraries(csvcolumnselector lib)

install (TARGETS csvcolumnselector DESTINATION "${PROJECT_SOURCE_DIR}/bin/")