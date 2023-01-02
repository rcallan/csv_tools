cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
set(VCPKG_TARGET_TRIPLET x64-linux CACHE STRING "Vcpkg target triplet")

project(csvtools LANGUAGES CXX C VERSION 0.2.0)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-std=c++2a -pthread -Wall -Wno-sign-compare")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/71140c3ca7a87bb1b5b9c9f1500fea8858cce344.zip
)

FetchContent_MakeAvailable(googletest)

include(CTest)

# vcpkg dependencies
# set(CMAKE_FIND_DEBUG_MODE 1)
find_package(Boost 1.81.0 REQUIRED)
find_package(OpenCL 2.2 REQUIRED)

add_subdirectory(lib)

add_subdirectory(tools/columnselector)
add_subdirectory(tools/arith)
add_subdirectory(tools/joiner)
add_subdirectory(tools/statistics)
add_subdirectory(tools/show)
add_subdirectory(tools/ml)

add_subdirectory(tools/backtester)

add_subdirectory(tests)

install(DIRECTORY DESTINATION "${PROJECT_SOURCE_DIR}/bin/")
