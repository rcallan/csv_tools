cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS columnselector.cpp)
add_executable(columnselector ${SRCS})
target_link_libraries(columnselector lib)

install (TARGETS columnselector DESTINATION "${PROJECT_SOURCE_DIR}/bin/")