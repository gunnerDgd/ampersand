project    (ampersand-desc)
add_library(ampersand-desc-details STATIC
    details/desc.h
    details/desc.c
)

add_library(ampersand-desc STATIC
    desc.h
    desc.c

    func.h
    func.c

    ops.h
    ops.c

    strt.h
    strt.c
    
    script.h
    script.c
)

add_library(ampersand-desc-cpp STATIC
    ../desc.hpp
    declare.hpp
    desc.hpp
    desc_friend.hpp
    desc.cpp
)

target_compile_definitions(ampersand-desc         PRIVATE    PRESET_WIN32)
target_compile_definitions(ampersand-desc-details PRIVATE    PRESET_WIN32)
target_compile_definitions(ampersand-desc-cpp     PRIVATE    PRESET_WIN32)
set_target_properties     (ampersand-desc-cpp     PROPERTIES CXX_STANDARD    20)
set_target_properties     (ampersand-desc-cpp     PROPERTIES LINKER_LANGUAGE CXX)
add_subdirectory          (c99)