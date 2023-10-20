#include "val.h"
#include "details/val.h"

#include "details/type.h"

obj_trait* ap_val_t = &__ap_val_trait;

obj*
	ap_val_type
		(obj* par) {
			if(trait_of(par) != ap_val_t)
				return 0;

			return ((__ap_val*)par)->type;
}

u64_t
	ap_val_as_int
		(obj* par) {
			if(trait_of(par) != ap_val_t)
				return 0;

			return ((__ap_val*)par)->value.u64;
}

float
	ap_val_as_f32
		(obj* par) {
			if(trait_of(par) != ap_val_t)
				return 0;

			return ((__ap_val*)par)->value.f32;
}

double
	ap_val_as_f64
		(obj* par) {
			if(trait_of(par) != ap_val_t)
				return 0;

			return ((__ap_val*)par)->value.f64;
}