project    (ampersand-desc-c99-details)
add_library(ampersand-desc-c99-details STATIC
    c99.h
    c99.c

    type.h
    type.c

    obj.h
    obj.c

    val.h
    val.c

    ops.h
    ops.c
)

target_compile_definitions(ampersand-desc-c99-details PRIVATE PRESET_WIN32)