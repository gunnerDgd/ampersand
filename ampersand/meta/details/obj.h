#ifndef AMPERSAND_META_DETAILS_OBJ_H
#define AMPERSAND_META_DETAILS_OBJ_H

#include "ops.h"

#define __ap_obj_attr_pub  (1 << 0)
#define __ap_obj_attr_priv (1 << 1)
#define __ap_obj_attr_prot (1 << 2)

extern obj_trait __ap_obj_trait;
typedef struct	 __ap_obj	   {
	obj			  	  head;
	str				  name;
	u64_t			  attr;
	struct __ap_type* type;
}	__ap_obj;

bool_t __ap_obj_init		 (__ap_obj*, u32_t, va_list);
bool_t __ap_obj_init_as_clone(__ap_obj*, __ap_obj*)	    ;
bool_t __ap_obj_init_as_ref  (__ap_obj*)				;
void   __ap_obj_deinit		 (__ap_obj*)			    ;
str*   __ap_obj_name		 (__ap_obj*)				;
u64_t  __ap_obj_size		 ()							;

#endif