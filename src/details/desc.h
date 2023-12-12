#ifndef __DETAILS_DESC_H__
#define __DETAILS_DESC_H__

#include <obj.h>
#include "../op.h"

typedef struct desc_run_op           {
    bool_t (*none)      (obj*, ap_op);
    
    bool_t (*add)       (obj*, ap_op);
    bool_t (*add_eq)    (obj*, ap_op);

    bool_t (*sub)       (obj*, ap_op);
    bool_t (*sub_eq)    (obj*, ap_op);

    bool_t (*mul)       (obj*, ap_op);
    bool_t (*mul_eq)    (obj*, ap_op);

    bool_t (*div)       (obj*, ap_op);
    bool_t (*div_eq)    (obj*, ap_op);

    bool_t (*mod)       (obj*, ap_op);
    bool_t (*mod_eq)    (obj*, ap_op);

    bool_t (*shl)       (obj*, ap_op);
    bool_t (*shl_eq)    (obj*, ap_op);

    bool_t (*shr)       (obj*, ap_op);
    bool_t (*shr_eq)    (obj*, ap_op);

    bool_t (*bit_and)   (obj*, ap_op);
    bool_t (*bit_and_eq)(obj*, ap_op);

    bool_t (*bit_or)    (obj*, ap_op);
    bool_t (*bit_or_eq) (obj*, ap_op);

    bool_t (*bit_xor)   (obj*, ap_op);
    bool_t (*bit_xor_eq)(obj*, ap_op);

    bool_t (*bit_not)   (obj*, ap_op);

    bool_t (*eq)        (obj*, ap_op);
    bool_t (*neq)       (obj*, ap_op);

    bool_t (*gt)        (obj*, ap_op);
    bool_t (*gt_eq)     (obj*, ap_op);
    bool_t (*lt)        (obj*, ap_op);
    bool_t (*lt_eq)     (obj*, ap_op);

    bool_t (*and)       (obj*, ap_op);
    bool_t (*or)        (obj*, ap_op);
    bool_t (*not)       (obj*, ap_op);

    bool_t (*push)      (obj*, ap_op);
    bool_t (*pop)       (obj*, ap_op);
    bool_t (*mov)       (obj*, ap_op);

    bool_t (*call)      (obj*, ap_op);
    bool_t (*ret)       (obj*, ap_op);
}   desc_run_op;

typedef struct desc_run                        {
    union                                      {
        desc_run_op op;
        bool_t    (*op_func[36])(obj*, ap_op)  ;
    };
    bool_t        (*var)        (obj*, ap_var) ;
    bool_t        (*type)       (obj*, ap_type);
    bool_t        (*cls)        (obj*, ap_cls) ;
    bool_t        (*val)        (obj*, ap_val) ;
}   desc_run;

extern obj_trait desc_t  ;
typedef struct   desc    {
    obj        head      ;
    obj_trait *desc_trait;
    obj       *desc      ;
    desc_run  *run       ;
}   desc;

bool_t desc_new  (desc*, u32_t, va_list);
bool_t desc_clone(desc*, desc*)         ;
bool_t desc_ref  (desc*)                ;
void   desc_del  (desc*)                ;

#endif