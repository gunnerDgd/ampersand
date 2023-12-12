#ifndef __AP_DESC_H__
#define __AP_DESC_H__

#include <obj.h>

#include "op.h"
#include "var.h"
#include "val.h"
#include "cls.h"
#include "type.h"

typedef struct ap_desc_run_op        {
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
}   ap_desc_run_op;

typedef struct ap_desc_run             {
    ap_desc_run_op op                  ;
    bool_t       (*var) (obj*, ap_var) ;
    bool_t       (*type)(obj*, ap_type);
    bool_t       (*cls) (obj*, ap_cls) ;
    bool_t       (*val) (obj*, ap_val) ;
}   ap_desc_run;

extern  obj_trait *ap_desc_t;
typedef obj       *ap_desc  ;

bool_t ap_desc_op  (ap_desc, ap_op)  ;
bool_t ap_desc_var (ap_desc, ap_var) ;
bool_t ap_desc_type(ap_desc, ap_type);
bool_t ap_desc_cls (ap_desc, ap_cls) ;
bool_t ap_desc_val (ap_desc, ap_val) ;

#endif