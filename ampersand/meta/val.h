#ifndef AMPERSAND_META_VAL_H
#define AMPERSAND_META_VAL_H

#include <ampersand/base/obj.h>

extern obj_trait* ap_val_t;

obj*
	ap_val_type
		(obj*);

u64_t
	ap_val_as_int
		(obj*);

float
	ap_val_as_f32
		(obj*);

double
	ap_val_as_f64
		(obj*);

#endif