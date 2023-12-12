#include "ap.h"
#include "lang/c/var.h"

#include <stdio.h>

ap_main()                                                          {
    ap_var   var_i8    = make (ap_var_t)   from (2, ap_i8 , "Test");
    ap_var   var_i16   = make (ap_var_t)   from (2, ap_i16, "Test");
    ap_var   var_i32   = make (ap_var_t)   from (2, ap_i32, "Test");
    ap_var   var_i64   = make (ap_var_t)   from (2, ap_i64, "Test");

    ap_c_var c_var_i8  = make (ap_c_var_t) from (1, var_i8)        ;
    ap_c_var c_var_i16 = make (ap_c_var_t) from (1, var_i16)       ;
    ap_c_var c_var_i32 = make (ap_c_var_t) from (1, var_i32)       ;
    ap_c_var c_var_i64 = make (ap_c_var_t) from (1, var_i64)       ;

    ap_cls   cls            = make (ap_cls_t)   from (1, "TestStruct")     ; ap_cls_elem cls_elem = ap_cls_add(cls, ap_u8, "U8");
    ap_var   cls_var        = make (ap_var_t)   from (2, cls, "Test")      ;
    ap_var   cls_var_elem   = make (ap_var_t)   from (2, cls_var, cls_elem);
    ap_c_var c_var_cls      = make (ap_c_var_t) from (1, cls_var)          ;
    ap_c_var c_var_cls_elem = make (ap_c_var_t) from (1, cls_var_elem)     ;
    
    printf ("%s\n", str_ptr(ap_c_var_as_str(c_var_i8)))      ;
    printf ("%s\n", str_ptr(ap_c_var_as_str(c_var_i16)))     ;
    printf ("%s\n", str_ptr(ap_c_var_as_str(c_var_i32)))     ;
    printf ("%s\n", str_ptr(ap_c_var_as_str(c_var_i64)))     ;
    printf ("%s\n", str_ptr(ap_c_var_as_str(c_var_cls)))     ;
    printf ("%s\n", str_ptr(ap_c_var_as_str(c_var_cls_elem)));    
}