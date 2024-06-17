cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

if(COMMAND cmake_policy)
    cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

project(BrainBlocks)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/libs)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/libs)

IF(DEFINED EMSCRIPTEN)
    message(STATUS "emscripten build")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Oz -s WASM=2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s ASYNCIFY -s FULL_ES2=1 -s USE_GLFW=3")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Oz -s WASM=2 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s ASYNCIFY -s FULL_ES2=1 -s USE_GLFW=3")

    file(GLOB HTML "${CMAKE_CURRENT_SOURCE_DIR}/html/*")
    file(COPY ${HTML} DESTINATION ${CMAKE_BINARY_DIR}/bin/)
ENDIF()

include(cmake/compilerchecks.cmake)
include(cmake/cpm.cmake)
include(cmake/glew.cmake)
include(cmake/sdl.cmake)
include(cmake/imgui.cmake)

find_package(OpenGL REQUIRED)

add_subdirectory(src)