cmake_minimum_required(VERSION 2.6)

add_subdirectory(../../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "-std=c++11 -lpthread")

set(SRCS csvarith.cpp)
add_executable(csvarith ${SRCS})
target_link_libraries(csvarith lib)

install (TARGETS csvarith DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
