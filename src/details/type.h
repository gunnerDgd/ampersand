#ifndef __DETAILS_TYPE_H__
#define __DETAILS_TYPE_H__

#include <obj.h>

#define type_i8   0
#define type_u8   1
#define type_i16  2
#define type_u16  3
#define type_i32  4
#define type_u32  5
#define type_i64  6
#define type_u64  7

#define type_f32  8
#define type_f64  9

#define type_bool 10
#define type_none 11
#define type_any  12

extern obj_trait type_t;
typedef struct   type  {
    obj   head;
    u64_t type;
}   type;

bool_t type_new   (type*, u32_t, va_list);
bool_t type_clone (type*, type*)         ;
void   type_del   (type*)                ;


#endif