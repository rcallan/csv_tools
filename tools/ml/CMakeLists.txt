cmake_minimum_required(VERSION 3.16)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS ml.cpp)
add_executable(ml ${SRCS})
target_link_libraries(ml lib)

install (TARGETS ml DESTINATION "${PROJECT_SOURCE_DIR}/bin/")