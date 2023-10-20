project    (ampersand-desc-c99-c)
add_library(ampersand-desc-c99-c STATIC
    details/desc.h
    details/desc.c

    desc.h
    desc.c

    strt.h
    strt.c
)

add_library(ampersand-desc-c99 STATIC
    desc.hpp
    desc.cpp
)

target_compile_definitions(ampersand-desc-c99-c PRIVATE    PRESET_WIN32)
target_compile_definitions(ampersand-desc-c99   PRIVATE    PRESET_WIN32)
set_target_properties     (ampersand-desc-c99   PROPERTIES CXX_STANDARD 20)