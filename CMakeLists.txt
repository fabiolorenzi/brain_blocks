cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(BrainBlocks)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/libs)

include(cmake/compilerchecks.cmake)
include(cmake/cpm.cmake)
include(cmake/glew.cmake)
include(cmake/sdl.cmake)
include(cmake/imgui.cmake)

find_package(OpenGL REQUIRED)

add_subdirectory(src)