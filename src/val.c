#include "val.h"
#include "details/val.h"

obj_trait* ap_val_t = &val_t;

ap_type 
    ap_val_type
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0; val* val = par;

            return val->type;
}

ap_val  
    ap_val_as
        (ap_val par, ap_type par_type)                   {
            if (!par)                            return 0;
            if (!par_type)                       return 0;

            if (trait_of(par)      != ap_val_t)  return 0;
            if (trait_of(par_type) != ap_type_t) return 0;

            return val_as(par, par_type);
}

i8_t    
    ap_val_as_i8    
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_i8(par);
}

i16_t    
    ap_val_as_i16
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_i16(par);
}

i32_t    
    ap_val_as_i32
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_i32(par);
}

i64_t    
    ap_val_as_i64
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_i64(par);
}

u8_t    
    ap_val_as_u8    
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_i8(par);
}

u16_t    
    ap_val_as_u16
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_i16(par);
}

u32_t    
    ap_val_as_u32
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_u32(par);
}

u64_t    
    ap_val_as_u64
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_u64(par);
}

float
    ap_val_as_f32
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_f32(par);
}

double    
    ap_val_as_f64
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_as_f64(par);
}

ap_val  
    ap_val_add
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_add(par, par_arg);
}

ap_val  
    ap_val_sub
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_sub(par, par_arg);
}

ap_val  
    ap_val_mul
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_mul(par, par_arg);
}

ap_val  
    ap_val_div
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_div(par, par_arg);
}

ap_val  
    ap_val_mod
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_mod(par, par_arg);
}

ap_val  
    ap_val_shl
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_shl(par, par_arg);
}

ap_val  
    ap_val_shr
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_shr(par, par_arg);
}

ap_val  
    ap_val_bit_and
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_bit_and(par, par_arg);
}

ap_val  
    ap_val_bit_or
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_bit_or(par, par_arg);
}

ap_val  
    ap_val_bit_xor
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_bit_xor(par, par_arg);
}

ap_val  
    ap_val_bit_not
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_bit_not(par);
}

ap_val  
    ap_val_eq
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_eq(par, par_arg);
}

ap_val  
    ap_val_neq
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_neq(par, par_arg);
}

ap_val  
    ap_val_gt
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_gt(par, par_arg);
}

ap_val  
    ap_val_gt_eq
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_gt_eq(par, par_arg);
}

ap_val  
    ap_val_lt
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_lt(par, par_arg);
}

ap_val  
    ap_val_lt_eq
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_lt_eq(par, par_arg);
}

ap_val  
    ap_val_and
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_and(par, par_arg);
}

ap_val  
    ap_val_or
        (ap_val par, ap_val par_arg)                   {
            if (!par)                          return 0;
            if (!par_arg)                      return 0;

            if (trait_of(par)     != ap_val_t) return 0;
            if (trait_of(par_arg) != ap_val_t) return 0;

            return val_or(par, par_arg);
}

ap_val  
    ap_val_not
        (ap_val par)                               {
            if (!par)                      return 0;
            if (trait_of(par) != ap_val_t) return 0;

            return val_not(par);
}