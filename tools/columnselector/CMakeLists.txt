cmake_minimum_required(VERSION 3.16)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS columnselector.cpp)
add_executable(columnselector ${SRCS})
target_link_libraries(columnselector lib ${OpenCL_LIBRARIES})

install (TARGETS columnselector DESTINATION "${PROJECT_SOURCE_DIR}/bin/")