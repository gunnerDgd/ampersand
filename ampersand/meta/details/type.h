#ifndef AMPERSAND_DETAILS_META_TYPE_H
#define AMPERSAND_DETAILS_META_TYPE_H

#include <ampersand/base/obj.h>
#include <ampersand/base/str.h>
#include <ampersand/base/list.h>

#define __ap_type_none		  0

#define __ap_type_u8		  1
#define __ap_type_u16		  2
#define __ap_type_u32		  3
#define __ap_type_u64		  4

#define __ap_type_i8		  5 
#define __ap_type_i16		  6
#define __ap_type_i32		  7
#define __ap_type_i64		  8

#define __ap_type_f32		  9
#define __ap_type_f64		 10

#define __ap_type_strt		 11
#define __ap_type_self		 12
#define __ap_type_ext		 13

extern obj_trait __ap_type_trait;
typedef struct   __ap_type      {
	obj			   head;
	str			   name;
	u64_t		   idx ;
	list		   elem;
}	__ap_type;

bool_t
	__ap_type_init
		(__ap_type*, u32_t, va_list);

bool_t
	__ap_type_init_as_clone
		(__ap_type*, __ap_type*);

bool_t
	__ap_type_init_as_ref
		(__ap_type*);

void
	__ap_type_deinit
		(__ap_type*);

str*
	__ap_type_name
		(__ap_type*);

u64_t
	__ap_type_size
		();

#endif