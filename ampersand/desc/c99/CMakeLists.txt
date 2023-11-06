project    (ampersand-desc-c99)
add_library(ampersand-desc-c99 STATIC
    c99.h
    c99.c

    strt.h
    strt.c

    func.h
    func.c

    ops.h
    ops.c

    script.h
    script.c
)

project    (ampersand-desc-c99-cpp)
add_library(ampersand-desc-c99-cpp STATIC
    ../c99.hpp
    ../c99.cpp
)

target_compile_definitions(ampersand-desc-c99     PRIVATE    PRESET_WIN32)
target_compile_definitions(ampersand-desc-c99-cpp PRIVATE    PRESET_WIN32)
set_target_properties     (ampersand-desc-c99-cpp PROPERTIES CXX_STANDARD    20)
set_target_properties     (ampersand-desc-c99-cpp PROPERTIES LINKER_LANGUAGE CXX)
add_subdirectory          (details)