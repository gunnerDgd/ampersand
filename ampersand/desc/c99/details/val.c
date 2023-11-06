#include "val.h"

#include <ampersand/meta/val.h>
#include <ampersand/meta/type.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool_t
	__c99_desc_val
		(str* par_str, obj* par) {
			if(trait_of(par) != ap_val_t) return false_t;

			obj* val_t = ap_val_type(par);
			str_rsv_back			(par_str, 255);
			switch(ap_type_idx(val_t)) {
				case ap_type_i8 :
				case ap_type_i16:
				case ap_type_i32:
				case ap_type_i64:
				case ap_type_u8 :
				case ap_type_u16:
				case ap_type_u32:
				case ap_type_u64: sprintf(ptr_raw(str_ptr(par_str)), "%lld ", ap_val_as_int(par)); break;
				case ap_type_f32: sprintf(ptr_raw(str_ptr(par_str)), "%f "  , ap_val_as_f32(par));
				case ap_type_f64: sprintf(ptr_raw(str_ptr(par_str)), "%lf " , ap_val_as_f64(par)); break;
				default			: return false_t;
			}

			return true_t;
}