#include "obj.h"
#include "details/obj.h"

#include "default.h"

obj*
    obj_init
		(alloc* par_alloc, obj_trait* par_trait, u32_t par_arg_count, ...) {
    		va_list  ret_args;
			va_start(ret_args, par_arg_count);

			obj* ret = obj_init_from_varg (
				par_alloc	 ,
				par_trait	 ,
				par_arg_count, 
				ret_args
			);

			va_end(ret_args);
			return ret;
}

obj*
    obj_init_from_varg
		(alloc* par_alloc, obj_trait* par_trait, u32_t par_arg_count, va_list par_arg) {
			if(!par_alloc)
				par_alloc = get_alloc();

			if (!par_alloc)
				return 0;

			obj* ret = __obj_init (
				par_alloc	 , 
				par_trait	 , 
				par_arg_count, 
				par_arg
			);

			return ret;
}

obj*
    obj_init_as_clone
		(obj* par_object) {
			return __obj_init_as_clone(par_object);
}

obj*
    obj_init_as_ref
		(obj* par_object) {
			return __obj_init_as_ref(par_object);
}

void
    obj_deinit
		(obj* par_object) {
			__obj_deinit(par_object);
}

obj_trait*
	obj_get_trait
		(obj* par_object) {
			return ((__obj*)par_object)->trait;
}

str*
	obj_name
		(obj* par_object) {
			if(((__obj*)par_object)->trait->name)
				return ((__obj*)par_object)->trait->name(par_object);
			else
				return 0;
}

u64_t
	obj_use_count
		(obj* par_object) {
			return ((__obj*)par_object)->ref;
}