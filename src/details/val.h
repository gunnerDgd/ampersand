#ifndef __DETAILS_VAL_H__
#define __DETAILS_VAL_H__

#include <obj.h>
#include "../type.h"

extern obj_trait val_t;
typedef struct   val  {
    obj          head ;
    ap_type      type ;
    union             {
        bool_t boolean;
        i8_t   i8     ; i16_t i16; i32_t i32; i64_t i64;
        u8_t   u8     ; u16_t u16; u32_t u32; u64_t u64;
        float  f32    ;
        double f64    ;
    }   val;
}   val;

bool_t  val_new    (val*, u32_t, va_list);
bool_t  val_clone  (val*, val*)          ;
void    val_del    (val*)                ;

val*    val_as     (val*, ap_type);
bool_t  val_as_bool(val*)         ;
i8_t    val_as_i8  (val*)         ;
i16_t   val_as_i16 (val*)         ;
i32_t   val_as_i32 (val*)         ;
i64_t   val_as_i64 (val*)         ;

u8_t    val_as_u8  (val*)         ;
u16_t   val_as_u16 (val*)         ;
u32_t   val_as_u32 (val*)         ;
u64_t   val_as_u64 (val*)         ;

float   val_as_f32 (val*)         ;
double  val_as_f64 (val*)         ;

val*    val_add   (val*, val*)   ;
val*    val_sub   (val*, val*)   ;
val*    val_mul   (val*, val*)   ;
val*    val_div   (val*, val*)   ;
val*    val_mod   (val*, val*)   ;

val*    val_shl    (val*, val*)   ;
val*    val_shr    (val*, val*)   ;

val*    val_bit_and(val*, val*)   ;
val*    val_bit_or (val*, val*)   ;
val*    val_bit_xor(val*, val*)   ;
val*    val_bit_not(val*)         ;

val*    val_eq     (val*, val*);
val*    val_neq    (val*, val*);

val*    val_gt     (val*, val*);
val*    val_gt_eq  (val*, val*);

val*    val_lt     (val*, val*);
val*    val_lt_eq  (val*, val*);

val*    val_and    (val*, val*);
val*    val_or     (val*, val*);
val*    val_not    (val*)      ;

#endif