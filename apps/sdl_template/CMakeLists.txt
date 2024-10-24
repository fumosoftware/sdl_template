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
