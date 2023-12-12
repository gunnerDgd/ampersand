project    (ampersand-lang-c)
add_library(ampersand-lang-c STATIC
    details/var.h
    details/var.c

    details/type.h
    details/type.c

    details/cls.h
    details/cls.c

    details/op.h
    details/op.c

    details/val.h
    details/val.c

    details/op/arith.h
    details/op/arith.c

    details/op/bit.h
    details/op/bit.c

    details/op/cmp.h
    details/op/cmp.c

    details/op/logical.h
    details/op/logical.c

    details/op/push.h
    details/op/push.c

    details/op/pop.h
    details/op/pop.c

    details/op/mov.h
    details/op/mov.c

    type.h
    type.c

    cls.h
    cls.c

    var.h
    var.c

    val.h
    val.c

    op.h
    op.c
)