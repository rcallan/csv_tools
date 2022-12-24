cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS joiner.cpp)
add_executable(joiner ${SRCS})
target_link_libraries(joiner lib)

install (TARGETS joiner DESTINATION "${PROJECT_SOURCE_DIR}/bin/")