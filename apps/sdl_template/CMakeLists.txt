cmake_minimum_required(VERSION 3.29)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif()

project(sdl_template_app
        VERSION 0.0.1
        DESCRIPTION "My SDL project"
        HOMEPAGE_URL "%%url%%"
        LANGUAGES CXX C)

add_executable(sdl_template_app src/main.cpp)
target_link_libraries(sdl_template_app PRIVATE SDL3::SDL3)

set_project_warnings(sdl_template_app)

if(WIN32)
    add_custom_command(
            TARGET sdl_template_app POST_BUILD
            COMMAND "${CMAKE_COMMAND}" -E copy $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE_DIR:sdl_template_app>
            VERBATIM
    )
endif()