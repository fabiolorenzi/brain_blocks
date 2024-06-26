cmake_minimum_required(VERSION 3.22)

project(BrainBlocks VERSION 0.1.0)
add_executable(BrainBlocks)

target_sources(${PROJECT_NAME}
    PRIVATE
        main.cpp
        classes/Player.cpp
        classes/Renderer.cpp
        classes/Timer.cpp
        classes/Wall.cpp
        classes/Window.cpp
        functions/KeysManager.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        classes
        functions
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        SDL2-static
        ${OPENGL_gl_LIBRARY}
        ${CMAKE_DL_LIBS}
        SDL2_image
        IMGUI
        glew
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "brain_blocks")

if(MSVC)
target_compile_definitions(${PROJECT_NAME}
    PRIVATE
        _SILENCE_CXX23_ALIGNED_STORAGE_DEPRECATION_WARNING
)
endif()