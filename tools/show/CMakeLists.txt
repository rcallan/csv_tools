cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS show.cpp)
add_executable(show ${SRCS})
target_link_libraries(show lib)

install (TARGETS show DESTINATION "${PROJECT_SOURCE_DIR}/bin/")