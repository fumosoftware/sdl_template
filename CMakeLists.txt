cmake_minimum_required(VERSION 3.29)

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 23)
endif()

project(sdl_template
        VERSION 0.0.1
        DESCRIPTION "My SDL project"
        HOMEPAGE_URL "%%url%%"
        LANGUAGES CXX C)

include(cmake/CPM.cmake)

CPMAddPackage("gh:fmtlib/fmt#10.2.1")
CPMAddPackage("gh:libsdl-org/sdl#preview-3.1.3")

add_subdirectory(apps)
