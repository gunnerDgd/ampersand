add_library(ampersand STATIC
    details/type.h
    details/type.c

    details/cls.h
    details/cls.c

    details/var.h
    details/var.c

    details/op.h
    details/op.c

    details/val.h
    details/val.c

    details/desc.h
    details/desc.c

    details/src.h
    details/src.c

    details/func.h
    details/func.c

    op/arith.h
    op/arith.c

    op/bit.h
    op/bit.c

    op/cmp.h
    op/cmp.c

    op/logical.h
    op/logical.c

    op/push.h
    op/push.c

    op/pop.h
    op/pop.c

    op/mov.h
    op/mov.c

    util/cls.h
    util/cls.c

    util/type.h
    util/type.c

    util/var.h
    util/var.c

    util/op.h
    util/op.c

    util/op/arith.h
    util/op/arith.c

    util/op/bit.h
    util/op/bit.c

    util/op/cmp.h
    util/op/cmp.c

    util/op/logical.h
    util/op/logical.c

    util/op/mov.h
    util/op/mov.c

    util/op/push.h
    util/op/push.c

    util/op/pop.h
    util/op/pop.c

    util.h
    util.c

    ap.h
    ap.c

    type.h
    type.c

    var.h
    var.c

    cls.h
    cls.c

    val.h
    val.c

    op.h
    op.c

    desc.h
    desc.c

    src.h
    src.c

    func.h
    func.c
)

add_subdirectory(lang)