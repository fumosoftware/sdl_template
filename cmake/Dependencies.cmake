include(CPM)

CPMAddPackage("gh:fmtlib/fmt#10.2.1")
if(${sdl_template_USE_SDL3})
    CPMAddPackage("gh:libsdl-org/sdl#preview-3.1.3")
else ()
    CPMAddPackage("gh:libsdl-org/sdl#release-2.30.8")
    CPMAddPackage("gh:libsdl-org/sdl_image#release-2.8.2")
endif()
