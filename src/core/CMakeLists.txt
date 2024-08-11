include_directories(../../include)

add_library                 (
    ampersand-core-operator
    STATIC

    ../../include/ap/core/operator/ari.hpp
    ../../include/ap/core/operator/bit.hpp
    ../../include/ap/core/operator/boolean.hpp
    ../../include/ap/core/operator/ord.hpp
    ../../include/ap/core/operator/cmp.hpp
    ../../include/ap/core/operator/move.hpp
    ../../include/ap/core/operator/call.hpp
    ../../include/ap/core/operator/idx.hpp

    ../../include/ap/core/operator.hpp
)

add_library                         (
    ampersand-core
    STATIC

    ../../include/ap/core/boolean.hpp
    ../../include/ap/core/call.hpp
    ../../include/ap/core/ari.hpp
    ../../include/ap/core/bit.hpp
    ../../include/ap/core/move.hpp
    ../../include/ap/core/ord.hpp
    ../../include/ap/core/cmp.hpp
    ../../include/ap/core/idx.hpp

    ../../include/ap/core/loop.hpp
    ../../include/ap/core/cond.hpp

    ../../include/ap/core/bool.hpp
    ../../include/ap/core/float.hpp
    ../../include/ap/core/int.hpp
    ../../include/ap/core/pack.hpp
    ../../include/ap/core/var.hpp
    ../../include/ap/core/fn.hpp

    ../../include/ap/core/core.hpp
    ../../include/ap/core.hpp

    ops/call.cpp
    boolean.cpp
    float.cpp
    int.cpp
    fn.cpp
)

set_target_properties (ampersand-core-operator PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries (ampersand INTERFACE ampersand-core)