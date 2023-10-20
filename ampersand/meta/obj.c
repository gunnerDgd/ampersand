#include "obj.h"
#include "details/obj.h"

obj_trait* ap_obj_t = &__ap_obj_trait;

obj*
	ap_obj_type
		(obj* par) {
			if(trait_of(par) != ap_obj_t)
				return 0;

			return ((__ap_obj*)par)->type;
}