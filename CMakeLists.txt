cmake_minimum_required(VERSION 3.0)
project(C_VOID)
include(CheckCCompilerFlag)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_C_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
	set (CMAKE_BUILD_TYPE "Debug")
endif (NOT CMAKE_BUILD_TYPE)

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall")
endif()

if (${CMAKE_BUILD_TYPE} STREQUAL Release)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -w")
endif()

check_c_compiler_flag ("-Wno-unused-function" IS_AVALABLE)
if (IS_AVALABLE)
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-function")
endif()

add_subdirectory(tests)

add_library(tucvoid STATIC all.c base/void.h all.h)

#include (CTest)
