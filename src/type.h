#ifndef __AP_TYPE_H__
#define __AP_TYPE_H__

#include <obj.h>

#define ap_type_id_i8   0
#define ap_type_id_u8   1
#define ap_type_id_i16  2
#define ap_type_id_u16  3
#define ap_type_id_i32  4
#define ap_type_id_u32  5
#define ap_type_id_i64  6
#define ap_type_id_u64  7

#define ap_type_id_f32  8
#define ap_type_id_f64  9

#define ap_type_id_bool 10
#define ap_type_id_none 11
#define ap_type_id_any  12

extern  obj_trait *ap_type_t;
typedef obj       *ap_type  ;

extern ap_type ap_i8  , ap_i16, ap_i32, ap_i64,
               ap_u8  , ap_u16, ap_u32, ap_u64,
               ap_f32 ,
               ap_f64 ,
               ap_bool,
               ap_none,
               ap_any ;

u64_t ap_type_id(ap_type);

#endif