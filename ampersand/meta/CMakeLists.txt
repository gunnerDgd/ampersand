project    (ampersand-meta)
add_library(ampersand-meta-c STATIC
    details/obj.h
    details/obj.c

    details/type.h
    details/type.c

    details/ops.h
    details/ops.c

    details/script.h
    details/script.c

    details/func.h
    details/func.c

    details/val.h
    details/val.c

    details/elem.h
    details/elem.c

    #details/mod.h
    #details/mod.c

    type.h
    type.c

    obj.h
    obj.c

    ops.h
    ops.c

    script.h
    script.c

    func.h
    func.c

    val.h
    val.c

    elem.h
    elem.c
)

add_library(ampersand-meta STATIC
    declare.hpp

    ../meta.hpp
    ../meta.cpp

    ops/arith.hpp
    ops/arith.cpp

    #ops/bit.hpp
    #ops/bit.cpp

    #ops/cmp.hpp
    #ops/cmp.cpp

    #ops/logical.hpp
    #ops/logical.cpp

    type.hpp
    type.cpp

    obj.hpp
    obj.cpp

    #ops.hpp
    #ops.cpp

    #val.hpp
    #val.cpp
    
    elem.hpp
    elem.cpp

    #func.hpp
    #func.cpp

    #script.hpp
    #script.cpp
)

target_compile_definitions(ampersand-meta   PRIVATE PRESET_WIN32)
target_compile_definitions(ampersand-meta-c PRIVATE PRESET_WIN32)
set_target_properties     (ampersand-meta PROPERTIES CXX_STANDARD 20)