#ifndef __DETAILS_SRC_H__
#define __DETAILS_SRC_H__

#include <obj.h>
#include <list.h>

extern obj_trait src_t;
typedef struct   src  {
    obj  head;
    list src ;
}   src;

bool_t src_new  (src*, u32_t, va_list);
bool_t src_clone(src*, src*)          ;
void   src_del  (src*)                ;

#endif