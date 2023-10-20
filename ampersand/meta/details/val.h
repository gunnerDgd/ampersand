#ifndef AMPERSAND_META_DETAILS_VAL_H
#define AMPERSAND_META_DETAILS_VAL_H

#include <ampersand/base/obj.h>

extern obj_trait __ap_val_trait;
typedef struct   __ap_val	   {
	obj				  head;
	struct __ap_type* type;
	union				  {
		i8_t  i8 ; i16_t  i16; i32_t i32; i64_t i64;
		u8_t  u8 ; u16_t  u16; u32_t u32; u64_t u64;
		float f32; double f64;
	}	value;
}	__ap_val;

bool_t
	__ap_val_init
		(__ap_val*, u32_t, va_list);

bool_t
	__ap_val_init_as_clone
		(__ap_val*, __ap_val*);

bool_t
	__ap_val_init_as_ref
		(__ap_val*);

void
	__ap_val_deinit
		(__ap_val*);

u64_t
	__ap_val_size
		();

#endif