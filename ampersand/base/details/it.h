#ifndef __DETAILS_IT_H__
#define __DETAILS_IT_H__

#include "../type.h"
#include "../type_atomic.h"

typedef struct __it_trait				 {
	bool_t (*next)(struct __it*)		 ;
	void*  (*get) (struct __it*)		 ;
	void*  (*set) (struct __it*, void*);

	bool_t (*eq)  (struct __it*, struct __it*);
	bool_t (*lt)  (struct __it*, struct __it*);
	bool_t (*gt)  (struct __it*, struct __it*);
}	__it_trait;

typedef struct  __it	 {
	void	   *it	     ,
			   *it_parent;
	__it_trait *trait	 ;
}	__it;


bool_t
	__it_next
		(__it*);

void*
	__it_get
		(__it*);

void*
	__it_set
		(__it*, void*);

bool_t
	__it_eq
		(__it*, __it*);

bool_t
	__it_lt
		(__it*, __it*);

bool_t
	__it_gt
		(__it*, __it*);

#endif