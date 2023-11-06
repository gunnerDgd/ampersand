project                   (ampersand-examples-strt)
add_executable            (ampersand-examples-strt strt.cpp)
set_target_properties     (ampersand-examples-strt PROPERTIES CXX_STANDARD 20)
target_compile_definitions(ampersand-examples-strt PRIVATE PRESET_WIN32)
target_link_libraries     (ampersand-examples-strt PRIVATE
    ampersand 
    
    ampersand-meta 
    ampersand-meta-cpp
    
    build 
    build-arch
    build-preset
    
    ampersand-desc-c99
    ampersand-desc-c99-cpp
    ampersand-desc-c99-details

    ampersand-desc
    ampersand-desc-cpp
    ampersand-desc-details
)