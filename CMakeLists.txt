cmake_minimum_required(VERSION 3.22)
project(ggs VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()
message(STATUS "Build type set to ${CMAKE_BUILD_TYPE}")

set(include_dir ${PROJECT_SOURCE_DIR}/include)
set(src_dir ${PROJECT_SOURCE_DIR}/src)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(test)
