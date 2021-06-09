cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS csvml.cpp)
add_executable(csvml ${SRCS})
target_link_libraries(csvml lib)

install (TARGETS csvml DESTINATION "${PROJECT_SOURCE_DIR}/bin/")