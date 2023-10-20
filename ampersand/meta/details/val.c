#include "val.h"
#include "type.h"

obj_trait __ap_val_trait				  = {
	.init		   = &__ap_val_init		    ,
	.init_as_clone = &__ap_val_init_as_clone,
	.init_as_ref   = &__ap_val_init_as_ref  ,
	.deinit		   = &__ap_val_deinit	    ,
	.name		   = 0					    ,
	.size		   = &__ap_val_size
};

bool_t
	__ap_val_init
		(__ap_val* par_val, u32_t par_count, va_list par) {
			par_val->type	   = ref(va_arg(par, obj*));
			par_val->value.u64 = 0;

			switch(par_val->type->idx) {
				case __ap_type_i8 :
				case __ap_type_u8 : 
					par_val->value.i8  = va_arg(par, i8_t); 
					break;
				case __ap_type_i16:
				case __ap_type_u16: 
					par_val->value.i16 = va_arg(par, i16_t);
					break;
				case __ap_type_i32:
				case __ap_type_u32:
					par_val->value.i32 = va_arg(par, i32_t);
					break;
				case __ap_type_i64:
				case __ap_type_u64: 
					par_val->value.i64 = va_arg(par, i64_t);
					break;
				case __ap_type_f32: 
					par_val->value.f32 = va_arg(par, float);
					break;
				case __ap_type_f64: 
					par_val->value.f64 = va_arg(par, double);
					break;
				default:
					del(par_val->type);
					return false_t;
			}

			return true_t;
}

bool_t
	__ap_val_init_as_clone
		(__ap_val* par, __ap_val* par_clone) {
			par->type  = clone(par_clone->type);
			par->value = par_clone->value	   ;

			return true_t;
}

bool_t
	__ap_val_init_as_ref
		(__ap_val* par) {
			return true_t;
}

void
	__ap_val_deinit
		(__ap_val* par) {
			del(par->type);
}

u64_t
	__ap_val_size() {
		return sizeof(__ap_val);
}