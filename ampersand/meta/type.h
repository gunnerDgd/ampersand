#ifndef AMPERSAND_META_TYPE_H
#define AMPERSAND_META_TYPE_H

#include <ampersand/base/obj.h>
#include <ampersand/base/it.h>

extern obj_trait* ap_type_t;

#define ap_type_none 0

#define ap_type_u8   1
#define ap_type_u16  2
#define ap_type_u32  3
#define ap_type_u64  4

#define ap_type_i8   5
#define ap_type_i16  6
#define ap_type_i32  7
#define ap_type_i64  8

#define ap_type_f32  9
#define ap_type_f64  10

#define ap_type_strt 11
#define ap_type_self 12
#define ap_type_ext  13

u64_t
	ap_type_idx
		(obj*);

it
	ap_type_elem_begin
		(obj*);

it
	ap_type_elem_end
		(obj*);

#endif