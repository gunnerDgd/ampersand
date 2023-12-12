#ifndef __AP_VAL_H__
#define __AP_VAL_H__

#include <obj.h>
#include "type.h"

extern obj_trait *ap_val_t;
typedef void     *ap_val  ;

ap_type ap_val_type     (ap_val);

ap_val  ap_val_as       (ap_val, ap_type);
i8_t    ap_val_as_i8    (ap_val);
i16_t   ap_val_as_i16   (ap_val);
i32_t   ap_val_as_i32   (ap_val);
i64_t   ap_val_as_i64   (ap_val);

u8_t    ap_val_as_u8    (ap_val);
u16_t   ap_val_as_u16   (ap_val);
u32_t   ap_val_as_u32   (ap_val);
u64_t   ap_val_as_u64   (ap_val);

float   ap_val_as_f32   (ap_val);
double  ap_val_as_f64   (ap_val);

ap_val  ap_val_add      (ap_val, ap_val);
ap_val  ap_val_sub      (ap_val, ap_val);
ap_val  ap_val_mul      (ap_val, ap_val);
ap_val  ap_val_div      (ap_val, ap_val);
ap_val  ap_val_mod      (ap_val, ap_val);

ap_val  ap_val_shl      (ap_val, ap_val);
ap_val  ap_val_shr      (ap_val, ap_val);

ap_val  ap_val_bit_and  (ap_val, ap_val);
ap_val  ap_val_bit_or   (ap_val, ap_val);
ap_val  ap_val_bit_xor  (ap_val, ap_val);
ap_val  ap_val_bit_not  (ap_val)        ;

ap_val  ap_val_eq       (ap_val, ap_val);
ap_val  ap_val_neq      (ap_val, ap_val);

ap_val  ap_val_gt       (ap_val, ap_val);
ap_val  ap_val_gt_eq    (ap_val, ap_val);

ap_val  ap_val_lt       (ap_val, ap_val);
ap_val  ap_val_lt_eq    (ap_val, ap_val);

ap_val  ap_val_and      (ap_val, ap_val);
ap_val  ap_val_or       (ap_val, ap_val);
ap_val  ap_val_not      (ap_val)        ;

#endif