cmake_minimum_required(VERSION 3.16)

set(SHARED_LIB_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include ${OpenCL_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})

set(SHARED_LIB_INCLUDE_DIR ${SHARED_LIB_INCLUDE_DIR} PARENT_SCOPE)

# set(CMAKE_CXX_FLAGS "-std=c++2a")

if(TARGET lib)
    
    #message("lib is already defined")
    
else()
    
    include_directories(
        ${SHARED_LIB_INCLUDE_DIR}
    )

    file(GLOB LIB_SRC_FILES "./src/*.cpp")

    set(LIB_SRCS ${LIB_SRC_FILES})
    
    add_library(lib STATIC ${LIB_SRCS})
    
endif()
