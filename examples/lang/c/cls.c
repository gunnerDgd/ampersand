#include "ap.h"
#include <stdio.h>

#include "lang/c/cls.h"
#include "lang/c/type.h"
#include "lang/c/var.h"
#include "lang/c/op.h"

ap_main()                                                  {
    ap_cls     cls = make (ap_cls_t) from (1, "TestStruct");
    ap_cls_add(cls, ap_u8 , "U8") ;
    ap_cls_add(cls, ap_u16, "U16");
    ap_cls_add(cls, ap_u32, "U32");
    ap_cls_add(cls, ap_u64, "U64");
    
    ap_var var      = make (ap_var_t) from (2, cls, "Test");
    ap_val val_u8   = make (ap_val_t) from (2, ap_u8 , 1);
    ap_val val_u16  = make (ap_val_t) from (2, ap_u16, 2);
    ap_val val_u32  = make (ap_val_t) from (2, ap_u32, 3);
    ap_val val_u64  = make (ap_val_t) from (2, ap_u64, 4llu);
    ap_op  var_push = ap_op_push(var, 4, val_u8, val_u16, val_u32, val_u64);

    ap_c_cls c_cls = make(ap_c_cls_t) from(1, cls)     ;
    ap_c_op  c_op  = make(ap_c_op_t)  from(1, var_push);

    printf("%s\n", str_ptr(ap_c_cls_as_str(c_cls)));
    printf("%s\n", str_ptr(ap_c_op_as_str (c_op))) ;
    
}