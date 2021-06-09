cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS showcsv.cpp)
add_executable(showcsv ${SRCS})
target_link_libraries(showcsv lib)

install (TARGETS showcsv DESTINATION "${PROJECT_SOURCE_DIR}/bin/")