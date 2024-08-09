add_library              (
    ampersand-meta STATIC

    ../../include/ap/meta/ope/func.hpp
    ../../include/ap/meta/ope/num.hpp
    ../../include/ap/meta/ope/var.hpp
    ../../include/ap/meta/ope/op.hpp
    ../../include/ap/meta/ope.hpp

    ../../include/ap/meta/meta.hpp
    ../../include/ap/meta/pack.hpp
    ../../include/ap/meta/src.hpp
    ../../include/ap/meta/fn.hpp
    ../../include/ap/meta.hpp

    ope/func.cpp
    ope/var.cpp
    ope/num.cpp
    ope/op.cpp

    pack.cpp
    ope.cpp
    src.cpp
    fn.cpp
)

target_link_libraries (ampersand INTERFACE ampersand-meta)