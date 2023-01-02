cmake_minimum_required(VERSION 3.16)

add_subdirectory(../lib lib)

include_directories(${SHARED_LIB_INCLUDE_DIR})

set(SRCS arith_test.cpp)
add_executable(arith_test ${SRCS})
target_link_libraries(
    arith_test
    lib
    ${OpenCL_LIBRARIES}
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(arith_test)

