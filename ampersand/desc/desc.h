#ifndef AMPERSAND_DESC_DESC_H
#define AMPERSAND_DESC_DESC_H

#include <ampersand/base/obj.h>

typedef struct ap_desc_run {
		struct			   {
			bool_t (*all)			 (obj*, obj*)		       ;
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
}		ap_desc_run;

extern obj_trait* ap_desc_t;

obj* ap_desc_context(obj*);

#endif