project    (ampersand-desc)
add_library(ampersand-desc-c STATIC
    details/desc.h
    details/desc.c

    desc.h
    desc.c

    c99.h
    c99.c
)

add_library(ampersand-desc STATIC
    ../desc.hpp

    c99.hpp
    c99.cpp
)

target_compile_definitions(ampersand-desc-c PRIVATE    PRESET_WIN32)
target_compile_definitions(ampersand-desc   PRIVATE    PRESET_WIN32)
set_target_properties     (ampersand-desc   PROPERTIES CXX_STANDARD    20)
set_target_properties     (ampersand-desc   PROPERTIES LINKER_LANGUAGE CXX)
add_subdirectory          (c99)