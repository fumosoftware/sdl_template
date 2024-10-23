cmake_minimum_required(VERSION 3.29)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif()

project(sdl_template
        VERSION 0.0.1
        DESCRIPTION "My SDL project"
        HOMEPAGE_URL ""
        LANGUAGES CXX C)

add_subdirectory(apps)
