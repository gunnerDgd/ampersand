add_subdirectory   (base)
add_subdirectory   (meta)
add_subdirectory   (desc)

add_library        (ampersand STATIC
    strt.hpp

    elem.hpp
    elem.cpp
    
    var.hpp
    details/var.hpp

    fn.hpp
)

set_target_properties     (ampersand PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties     (ampersand PROPERTIES CXX_STANDARD    20)
target_compile_definitions(ampersand PRIVATE PRESET_WIN32)