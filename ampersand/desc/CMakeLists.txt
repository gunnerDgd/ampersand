project    (ampersand-desc)
add_library(ampersand-desc STATIC
    ../desc.hpp
)

target_compile_definitions(ampersand-desc PRIVATE    PRESET_WIN32)
set_target_properties     (ampersand-desc PROPERTIES CXX_STANDARD    20)
set_target_properties     (ampersand-desc PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(c99)