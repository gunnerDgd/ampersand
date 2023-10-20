#include "obj.h"
#include "atomic.h"

__obj*
    __obj_init(__alloc* par_alloc, __obj_trait* par_trait, u32_t par_arg_count, va_list par_arg) {
		__mem* ret_mem    = __mem_init(par_alloc, par_trait->size());
        __obj *ret 	      = ret_mem->ptr			   		        ; if(ret_mem->alloc_size <= sizeof(__obj)) return 0;
               ret->mem   = ret_mem  ;
               ret->ref   =         1;
               ret->trait = par_trait;

		if(ret->trait->init) {
			if(!ret->trait->init(ret, par_arg_count, par_arg)) {
				__mem_deinit(ret_mem);
				return 0;
			}
		}

		return ret;
}

__obj*
    __obj_init_as_clone(__obj* par_object_clone) {
		__mem *ret_mem    = __mem_init_as_clone(par_object_clone->mem); if(!ret_mem) return 0;
		__obj *ret	      = ret_mem->ptr		   ;
			   ret->mem   = ret_mem				   ;
               ret->ref   =         	          1;
			   ret->trait = par_object_clone->trait;

		if(ret->trait->init_as_clone) {
			bool_t res = ret->trait->init_as_clone (ret, par_object_clone);

			if (!res) {
				__mem_deinit(ret_mem);
				return 0;
			}
		}

		return ret;
}

__obj*
    __obj_init_as_ref(__obj* par_object) {
        u64_t ref;
        do  { ref = par_object->ref; } while(__atomic_cmpxchg64(&par_object->ref, ref, ref + 1) != ref);

        if (par_object->trait->init_as_ref)
			par_object->trait->init_as_ref(par_object);
        return par_object;
}

void
    __obj_deinit(__obj* par_object) {
        u64_t ref;
        do  { ref = par_object->ref; } while(__atomic_cmpxchg64(&par_object->ref, ref, ref - 1) != ref);

		if (par_object->ref == 0) {
			par_object->trait->deinit(par_object);
			__mem_deinit(par_object->mem);
		}
}