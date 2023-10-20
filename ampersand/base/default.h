#ifndef __DEFAULT_H__
#define __DEFAULT_H__

#include "alloc.h"

alloc*		 get_alloc		();
alloc_trait* get_alloc_trait();
alloc*		 set_alloc	    (alloc*);
alloc_trait* set_alloc_trait(alloc_trait*);

#endif