#ifndef AMPERSAND_DESC_DETAILS_DESC_H
#define AMPERSAND_DESC_DETAILS_DESC_H

#include <ampersand/base/obj.h>

typedef struct __ap_desc_run {
		struct				 {
			bool_t (*all)			 (obj*, obj*)			   ;
			bool_t (*begin)			 (obj*, str*)			   ;
			bool_t (*begin_from_cstr)(obj*, const char*, u64_t);
			bool_t (*elem)			 (obj*, obj*)			   ;
			bool_t (*end)			 (obj*)					   ;
		}	strt;
		struct						     {
			bool_t (*all)	 (obj*, obj*);
			bool_t (*arith)  (obj*, obj*);
			bool_t (*bit)    (obj*, obj*);
			bool_t (*cmp)    (obj*, obj*);
			bool_t (*logical)(obj*, obj*);
			bool_t (*func)	 (obj*, obj*);
			bool_t (*push)   (obj*, obj*);
			bool_t (*pop)	 (obj*, obj*);
			bool_t (*end)	 (obj*)		 ;
		}	ops;

		struct							   {
			bool_t (*all)	   (obj*, obj*);
			bool_t (*ret)	   (obj*, obj*);
			bool_t (*arg)	   (obj*, obj*);
			bool_t (*arg_begin)(obj*)	   ;
			bool_t (*arg_end)  (obj*)	   ;
		}	func;

		bool_t (*script)(obj*, obj*);
}		__ap_desc_run;

extern obj_trait __ap_desc_trait;
typedef struct   __ap_desc		{
	obj			   head		;
	__ap_desc_run *run		;
	obj			  *ctx		;
	obj_trait	  *ctx_trait;
}	__ap_desc;

bool_t
	__ap_desc_init
		(__ap_desc*, u32_t, va_list);

bool_t
	__ap_desc_init_as_clone
		(__ap_desc*, __ap_desc*);

bool_t
	__ap_desc_init_as_ref
		(__ap_desc*);

void
	__ap_desc_deinit
		(__ap_desc*);

u64_t
	__ap_desc_size
		();

#endif