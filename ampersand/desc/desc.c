#include "desc.h"
#include "details/desc.h"

extern obj_trait* ap_desc_t = &__ap_desc_trait;

obj*
	ap_desc_context
		(obj* par) {
			if(trait_of(par) != ap_desc_t)
				return 0;

			return ((__ap_desc*)par)->ctx;
}