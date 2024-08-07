add_library                             (
    ampersand-trans
    STATIC

    ../../include/ap/trans/ops/ari.hpp
    ../../include/ap/trans/ops/boolean.hpp
    ../../include/ap/trans/ops/func.hpp
    ../../include/ap/trans/ops/cmp.hpp
    ../../include/ap/trans/ops/mem.hpp
    ../../include/ap/trans/ops/bit.hpp
    ../../include/ap/trans/ops/ord.hpp
    ../../include/ap/trans/ops.hpp

    ../../include/ap/trans/pack.hpp
    ../../include/ap/trans/ops.hpp
    ../../include/ap/trans/var.hpp
    ../../include/ap/trans/fn.hpp

    ../../include/ap/trans/trans.hpp
    ../../include/ap/trans.hpp
)

set_target_properties(ampersand-trans PROPERTIES LINKER_LANGUAGE CXX)