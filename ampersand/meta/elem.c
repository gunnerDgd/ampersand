#include "elem.h"
#include "details/elem.h"

obj_trait* ap_elem_t = &__ap_elem_trait;

u64_t
	ap_elem_category
		(obj* par) {
			if(trait_of(par) != ap_elem_t)
				return -1;

			return ((__ap_elem*)par)->category;
}

obj*
	ap_elem_type
		(obj* par) {
			if(trait_of(par) != ap_elem_t)
				return 0;

			return ((__ap_elem*)par)->type.all;
}

u64_t
	ap_elem_attr
		(obj* par) {
			if(trait_of(par) != ap_elem_t)
				return -1;

			return ((__ap_elem*)par)->attr.all;
}

u64_t
	ap_elem_attr_stor
		(obj* par) {
			if(trait_of(par) != ap_elem_t)
				return -1;

			return ((__ap_elem*)par)->attr.stor;
}

u64_t
	ap_elem_attr_acc
		(obj* par) {
			if(trait_of(par) != ap_elem_t)
				return -1;

			return ((__ap_elem*)par)->attr.acc;
}