project    (ampersand-desc-c99)
add_library(ampersand-desc-c99 STATIC
    details/ctx.h
    details/ctx.c

    details/ops.h
    details/ops.c

    details/strt.h
    details/strt.c

    details/func.h
    details/func.c

    details/script.h
    details/script.c

    ctx.h
    ctx.c

    strt.h
    strt.c

    func.h
    func.c

    ops.h
    ops.c

    script.h
    script.c
)

target_compile_definitions(ampersand-desc-c99 PRIVATE PRESET_WIN32)