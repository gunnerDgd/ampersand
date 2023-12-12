#include "ap.h"

#include "op.h"
#include "lang/c/cls.h"
#include "lang/c/type.h"
#include "lang/c/var.h"
#include "lang/c/op.h"

#include <stdio.h>

ap_main() {
    ap_var var_i8  = make(ap_var_t) from(2, ap_i8 , "Test");
    ap_var var_i16 = make(ap_var_t) from(2, ap_i16, "Test2");
    ap_val val     = make(ap_val_t) from(2, ap_i32, 5);
    ap_val val2    = make(ap_val_t) from(2, ap_i32, 2);

    ap_op     op     = ap_op_mod(ap_op_shl(val2, val), ap_op_add(var_i8, var_i16));
    ap_type   op_ret = ap_op_ret(op);
    ap_c_op   c_op   = make (ap_c_op_t)   from (1, op);
    ap_c_type c_type = make (ap_c_type_t) from (1, op_ret);
    
    printf("%s\n", str_ptr(ap_c_op_as_str(c_op)));
    printf("%s\n", str_ptr(ap_c_type_name(c_type)));
}