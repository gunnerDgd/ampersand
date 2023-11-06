project    (ampersand-meta)
add_library(ampersand-meta STATIC
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

add_library(ampersand-meta-cpp STATIC
    declare.hpp

    traits/elem.hpp
    traits/func.hpp
    traits/obj.hpp
    traits/ops.hpp
    traits/res.hpp
    traits/script.hpp
    traits/type.hpp
    traits/val.hpp
    traits/common.hpp
    traits.hpp

    ../meta.hpp
    ../meta.cpp

    ops/arith.hpp
    ops/arith_ops.hpp

    ops/cmp.hpp
    ops/cmp_ops.hpp

    ops/bit.hpp
    ops/bit_ops.hpp

    ops/logical.hpp
    ops/logical_ops.hpp

    ops/obj.hpp
    #ops/func.hpp

    type.hpp
    type.cpp

    obj.hpp
    val.hpp
    elem.hpp

    #ops.hpp
    #ops.cpp

    func.hpp
    func.cpp

    script.hpp
    script.cpp
)

target_compile_definitions(ampersand-meta     PRIVATE PRESET_WIN32)
target_compile_definitions(ampersand-meta-cpp PRIVATE PRESET_WIN32)
set_target_properties     (ampersand-meta-cpp PROPERTIES CXX_STANDARD 20)