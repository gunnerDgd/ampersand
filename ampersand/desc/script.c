#include "script.h"
#include "details/desc.h"

#include <ampersand/meta/script.h>

bool_t
	ap_desc_script
		(obj* par_desc, obj* par) {
			if (trait_of(par_desc) != ap_desc_t)   return false_t;
			if (trait_of(par)	   != ap_script_t) return false_t;

			__ap_desc* desc = par_desc;
			return	   desc->run->script(desc->ctx, par);
}