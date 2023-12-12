#include "val.h"
#include "../util.h"

obj_trait val_t         = {
    .on_new   = &val_new  ,
    .on_clone = &val_clone,
    .on_ref   = 0         ,
    .on_del   = &val_del  ,
    .size     = sizeof(val)
};

bool_t  
    val_new
        (val* par_val, u32_t par_count, va_list par) {
            ap_type type = va_arg(par, ap_type);
            if (!type)                       return false_t;
            if (trait_of(type) != ap_type_t) return false_t;

            switch(ap_type_id(type))                                              {
                case ap_type_id_i8 : par_val->val.i8  = va_arg(par, i8_t)  ; break;
                case ap_type_id_i16: par_val->val.i16 = va_arg(par, i16_t) ; break;
                case ap_type_id_i32: par_val->val.i32 = va_arg(par, i32_t) ; break;
                case ap_type_id_i64: par_val->val.i64 = va_arg(par, i64_t) ; break;

                case ap_type_id_u8 : par_val->val.u8  = va_arg(par, u8_t)  ; break;
                case ap_type_id_u16: par_val->val.u16 = va_arg(par, u16_t) ; break;
                case ap_type_id_u32: par_val->val.u32 = va_arg(par, u32_t) ; break;
                case ap_type_id_u64: par_val->val.u64 = va_arg(par, u64_t) ; break;

                case ap_type_id_f32: par_val->val.f32 = va_arg(par, float) ; break;
                case ap_type_id_f64: par_val->val.f64 = va_arg(par, double); break;
                default            : return false_t;
            }

            par_val->type = ref(type);
            return true_t;
}
bool_t  
    val_clone
        (val* par, val* par_clone)            {
            par->type = clone(par_clone->type);
            par->val  = par_clone->val        ;

            return true_t;
}

void    
    val_del
        (val* par)        {
            del(par->type);
}

val* 
    val_as
        (val* par, ap_type par_type)                                                         {
            switch(ap_type_id(par_type))                                                     {
                case ap_type_id_i8  : return make(&val_t) from (2, par_type, val_as_i8 (par));
                case ap_type_id_i16 : return make(&val_t) from (2, par_type, val_as_i16(par));
                case ap_type_id_i32 : return make(&val_t) from (2, par_type, val_as_i32(par));
                case ap_type_id_i64 : return make(&val_t) from (2, par_type, val_as_i64(par));

                case ap_type_id_u8  : return make(&val_t) from (2, par_type, val_as_u8 (par));
                case ap_type_id_u16 : return make(&val_t) from (2, par_type, val_as_u16(par));
                case ap_type_id_u32 : return make(&val_t) from (2, par_type, val_as_u32(par));
                case ap_type_id_u64 : return make(&val_t) from (2, par_type, val_as_u64(par));

                case ap_type_id_f32 : return make(&val_t) from (2, par_type, val_as_f32(par));
                case ap_type_id_f64 : return make(&val_t) from (2, par_type, val_as_f64(par));
            }

            if (ap_is_bool(par_type) && ap_is_bool(par->type))
                return make(&val_t) from(2, par_type, val_as_f64(par));

            return 0;
}

bool_t
    val_as_bool
        (val* par)                                                                {
            if (ap_type_id(par->type) == ap_type_id_bool) return par->val.boolean ;
            if (ap_type_id(par->type) == ap_type_id_f32)  return par->val.f32 != 0;
            if (ap_type_id(par->type) == ap_type_id_f64)  return par->val.f64 != 0;

            return par->val.i64 != 0;
}

i8_t    
    val_as_i8 
        (val* par)                                                       {
            if (ap_type_id(par->type) == ap_type_id_f32) return par->val.f32;
            if (ap_type_id(par->type) == ap_type_id_f64) return par->val.f64;

            return par->val.i8;
}

i16_t
    val_as_i16
        (val* par)                                                       {
            if (ap_type_id(par->type) == ap_type_id_f32) return par->val.f32;
            if (ap_type_id(par->type) == ap_type_id_f64) return par->val.f64;

            return par->val.i16;
}

i32_t    
    val_as_i32
        (val* par)                                                       {
            if (ap_type_id(par->type) == ap_type_id_f32) return par->val.f32;
            if (ap_type_id(par->type) == ap_type_id_f64) return par->val.f64;

            return par->val.i32;
}

i64_t
    val_as_i64
        (val* par)                                                       {
            if (ap_type_id(par->type) == ap_type_id_f32) return par->val.f32;
            if (ap_type_id(par->type) == ap_type_id_f64) return par->val.f64;

            return par->val.i64;
}

u8_t    
    val_as_u8 
        (val* par)                                                       {
            if (ap_type_id(par->type) == ap_type_id_f32) return par->val.f32;
            if (ap_type_id(par->type) == ap_type_id_f64) return par->val.f64;

            return par->val.u8;
}

u16_t
    val_as_u16
        (val* par)                                                       {
            if (ap_type_id(par->type) == ap_type_id_f32) return par->val.f32;
            if (ap_type_id(par->type) == ap_type_id_f64) return par->val.f64;

            return par->val.u16;
}

u32_t    
    val_as_u32
        (val* par)                                                       {
            if (ap_type_id(par->type) == ap_type_id_f32) return par->val.f32;
            if (ap_type_id(par->type) == ap_type_id_f64) return par->val.f64;

            return par->val.u32;
}

u64_t
    val_as_u64
        (val* par)                                                       {
            if (ap_type_id(par->type) == ap_type_id_f32) return par->val.f32;
            if (ap_type_id(par->type) == ap_type_id_f64) return par->val.f64;

            return par->val.u64;
}

float
    val_as_f32
        (val* par)                                      {
            switch(ap_type_id(par->type))               {
                case ap_type_id_i8 : return par->val.i8 ;
                case ap_type_id_i16: return par->val.i16;
                case ap_type_id_i32: return par->val.i32;
                case ap_type_id_i64: return par->val.i64;

                case ap_type_id_u8 : return par->val.u8 ;
                case ap_type_id_u16: return par->val.u16;
                case ap_type_id_u32: return par->val.u32;
                case ap_type_id_u64: return par->val.u64;
                case ap_type_id_f64: return par->val.f64;
            }

            return par->val.f32;
}

double
    val_as_f64
        (val* par)                                      {
            switch(ap_type_id(par->type))               {
                case ap_type_id_i8 : return par->val.i8 ;
                case ap_type_id_i16: return par->val.i16;
                case ap_type_id_i32: return par->val.i32;
                case ap_type_id_i64: return par->val.i64;

                case ap_type_id_u8 : return par->val.u8 ;
                case ap_type_id_u16: return par->val.u16;
                case ap_type_id_u32: return par->val.u32;
                case ap_type_id_u64: return par->val.u64;
                case ap_type_id_f32: return par->val.f32;
            }

            return par->val.f64;
}

val* 
    val_add
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                          {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) + val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) + val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) + val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) + val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) + val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) + val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) + val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) + val_as_u64(par_op));

                case ap_type_id_f32: return make (&val_t) from (2, type, val_as_f32(par) + val_as_f32(par_op));
                case ap_type_id_f64: return make (&val_t) from (2, type, val_as_f64(par) + val_as_f64(par_op));
            }

            return 0;
}

val* 
    val_sub
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) - val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) - val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) - val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) - val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) - val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) - val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) - val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) - val_as_u64(par_op));

                case ap_type_id_f32: return make (&val_t) from (2, type, val_as_f32(par) - val_as_f32(par_op));
                case ap_type_id_f64: return make (&val_t) from (2, type, val_as_f64(par) - val_as_f64(par_op));
            }

            return 0;
}

val* 
    val_mul
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) * val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) * val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) * val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) * val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) * val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) * val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) * val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) * val_as_u64(par_op));

                case ap_type_id_f32: return make (&val_t) from (2, type, val_as_f32(par) * val_as_f32(par_op));
                case ap_type_id_f64: return make (&val_t) from (2, type, val_as_f64(par) * val_as_f64(par_op));
            }

            return 0;
}

val* 
    val_div
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) / val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) / val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) / val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) / val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) / val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) / val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) / val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) / val_as_u64(par_op));

                case ap_type_id_f32: return make (&val_t) from (2, type, val_as_f32(par) / val_as_f32(par_op));
                case ap_type_id_f64: return make (&val_t) from (2, type, val_as_f64(par) / val_as_f64(par_op));
            }

            return 0;
}

val* 
    val_mod
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) % val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) % val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) % val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) % val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) % val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) % val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) % val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) % val_as_u64(par_op));
            }

            return 0;
}

val* 
    val_shl
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) << val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) << val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) << val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) << val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) << val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) << val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) << val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) << val_as_u64(par_op));
            }

            return 0;
}

val* 
    val_shr
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) >> val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) >> val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) >> val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) >> val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) >> val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) >> val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) >> val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) >> val_as_u64(par_op));
            }

            return 0;
}

val* 
    val_bit_and
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) & val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) & val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) & val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) & val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) & val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) & val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) & val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) & val_as_u64(par_op));
            }

            return 0;
}

val* 
    val_bit_or
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) | val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) | val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) | val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) | val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) | val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) | val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) | val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) | val_as_u64(par_op));
            }

            return 0;
}

val* 
    val_bit_xor
        (val* par, val* par_op)                                     {
            ap_type type   = ap_type_common(par->type, par_op->type); if (!type) return 0;
            switch(ap_type_id(type))                                                                       {
                case ap_type_id_i8 : return make (&val_t) from (2, type, val_as_i8 (par) ^ val_as_i8 (par_op));
                case ap_type_id_i16: return make (&val_t) from (2, type, val_as_i16(par) ^ val_as_i16(par_op));
                case ap_type_id_i32: return make (&val_t) from (2, type, val_as_i32(par) ^ val_as_i32(par_op));
                case ap_type_id_i64: return make (&val_t) from (2, type, val_as_i64(par) ^ val_as_i64(par_op));

                case ap_type_id_u8 : return make (&val_t) from (2, type, val_as_u8 (par) ^ val_as_u8 (par_op));
                case ap_type_id_u16: return make (&val_t) from (2, type, val_as_u16(par) ^ val_as_u16(par_op));
                case ap_type_id_u32: return make (&val_t) from (2, type, val_as_u32(par) ^ val_as_u32(par_op));
                case ap_type_id_u64: return make (&val_t) from (2, type, val_as_u64(par) ^ val_as_u64(par_op));
            }

            return 0;
}

val* 
    val_bit_not
        (val* par)                                                                          {
            switch(ap_type_id(par->type))                                                   {
                case ap_type_id_i8 : return make (&val_t) from (2, par->type, ~val_as_i8 (par));
                case ap_type_id_i16: return make (&val_t) from (2, par->type, ~val_as_i16(par));
                case ap_type_id_i32: return make (&val_t) from (2, par->type, ~val_as_i32(par));
                case ap_type_id_i64: return make (&val_t) from (2, par->type, ~val_as_i64(par));

                case ap_type_id_u8 : return make (&val_t) from (2, par->type, ~val_as_u8 (par));
                case ap_type_id_u16: return make (&val_t) from (2, par->type, ~val_as_u16(par));
                case ap_type_id_u32: return make (&val_t) from (2, par->type, ~val_as_u32(par));
                case ap_type_id_u64: return make (&val_t) from (2, par->type, ~val_as_u64(par));
            }

            return 0;
}


val* 
    val_eq
        (val* par, val* par_op)                                    {
            ap_type type = ap_type_common(par->type, par_op->type); 
            if (!type)            return 0;
            if (ap_is_bool(type)) return make (&val_t) from (2, type, val_as_bool(par), val_as_bool(par_op));

            ap_type ret_type = ap_bool;
            val*    ret      = 0      ;
            switch(ap_type_id(type))                                                                                  {
                case ap_type_id_i8 : ret = make (&val_t) from (2, ret_type, val_as_i8 (par) == val_as_i8 (par_op)); break;
                case ap_type_id_i16: ret = make (&val_t) from (2, ret_type, val_as_i16(par) == val_as_i16(par_op)); break;
                case ap_type_id_i32: ret = make (&val_t) from (2, ret_type, val_as_i32(par) == val_as_i32(par_op)); break;
                case ap_type_id_i64: ret = make (&val_t) from (2, ret_type, val_as_i64(par) == val_as_i64(par_op)); break;

                case ap_type_id_u8 : ret = make (&val_t) from (2, ret_type, val_as_u8 (par) == val_as_u8 (par_op)); break;
                case ap_type_id_u16: ret = make (&val_t) from (2, ret_type, val_as_u16(par) == val_as_u16(par_op)); break;
                case ap_type_id_u32: ret = make (&val_t) from (2, ret_type, val_as_u32(par) == val_as_u32(par_op)); break;
                case ap_type_id_u64: ret = make (&val_t) from (2, ret_type, val_as_u64(par) == val_as_u64(par_op)); break;

                case ap_type_id_f32: ret = make (&val_t) from (2, ret_type, val_as_f32(par) == val_as_f32(par_op)); break;
                case ap_type_id_f64: ret = make (&val_t) from (2, ret_type, val_as_f64(par) == val_as_f64(par_op)); break;
            }

            del   (ret_type);
            return ret;
}

val* 
    val_neq
        (val* par, val* par_op)                                    {
            ap_type type = ap_type_common(par->type, par_op->type); 
            if (!type)            return 0;
            if (ap_is_bool(type)) return make (&val_t) from (2, type, val_as_bool(par), val_as_bool(par_op));

            ap_type ret_type = ap_bool;
            val*    ret      = 0      ;
            switch(ap_type_id(type))                                                                                  {
                case ap_type_id_i8 : ret = make (&val_t) from (2, ret_type, val_as_i8 (par) != val_as_i8 (par_op)); break;
                case ap_type_id_i16: ret = make (&val_t) from (2, ret_type, val_as_i16(par) != val_as_i16(par_op)); break;
                case ap_type_id_i32: ret = make (&val_t) from (2, ret_type, val_as_i32(par) != val_as_i32(par_op)); break;
                case ap_type_id_i64: ret = make (&val_t) from (2, ret_type, val_as_i64(par) != val_as_i64(par_op)); break;

                case ap_type_id_u8 : ret = make (&val_t) from (2, ret_type, val_as_u8 (par) != val_as_u8 (par_op)); break;
                case ap_type_id_u16: ret = make (&val_t) from (2, ret_type, val_as_u16(par) != val_as_u16(par_op)); break;
                case ap_type_id_u32: ret = make (&val_t) from (2, ret_type, val_as_u32(par) != val_as_u32(par_op)); break;
                case ap_type_id_u64: ret = make (&val_t) from (2, ret_type, val_as_u64(par) != val_as_u64(par_op)); break;

                case ap_type_id_f32: ret = make (&val_t) from (2, ret_type, val_as_f32(par) != val_as_f32(par_op)); break;
                case ap_type_id_f64: ret = make (&val_t) from (2, ret_type, val_as_f64(par) != val_as_f64(par_op)); break;
            }

            del   (ret_type);
            return ret;
}

val* 
    val_gt
        (val* par, val* par_op)                                       {
            ap_type type     = ap_type_common(par->type, par_op->type); if (!type) return 0;
            ap_type ret_type = ap_bool;
            val    *ret      = 0      ;
            switch(ap_type_id(type))                                                                                  {
                case ap_type_id_i8 : ret = make (&val_t) from (2, ret_type, val_as_i8 (par) > val_as_i8 (par_op)); break;
                case ap_type_id_i16: ret = make (&val_t) from (2, ret_type, val_as_i16(par) > val_as_i16(par_op)); break;
                case ap_type_id_i32: ret = make (&val_t) from (2, ret_type, val_as_i32(par) > val_as_i32(par_op)); break;
                case ap_type_id_i64: ret = make (&val_t) from (2, ret_type, val_as_i64(par) > val_as_i64(par_op)); break;

                case ap_type_id_u8 : ret = make (&val_t) from (2, ret_type, val_as_u8 (par) > val_as_u8 (par_op)); break;
                case ap_type_id_u16: ret = make (&val_t) from (2, ret_type, val_as_u16(par) > val_as_u16(par_op)); break;
                case ap_type_id_u32: ret = make (&val_t) from (2, ret_type, val_as_u32(par) > val_as_u32(par_op)); break;
                case ap_type_id_u64: ret = make (&val_t) from (2, ret_type, val_as_u64(par) > val_as_u64(par_op)); break;

                case ap_type_id_f32: ret = make (&val_t) from (2, ret_type, val_as_f32(par) > val_as_f32(par_op)); break;
                case ap_type_id_f64: ret = make (&val_t) from (2, ret_type, val_as_f64(par) > val_as_f64(par_op)); break;
            }

            del   (ret_type);
            return ret;
}

val* 
    val_gt_eq
        (val* par, val* par_op)                                       {
            ap_type type     = ap_type_common(par->type, par_op->type); if (!type) return 0;
            ap_type ret_type = ap_bool;
            val    *ret      = 0      ;
            switch(ap_type_id(type))                                                                                  {
                case ap_type_id_i8 : ret = make (&val_t) from (2, ret_type, val_as_i8 (par) >= val_as_i8 (par_op)); break;
                case ap_type_id_i16: ret = make (&val_t) from (2, ret_type, val_as_i16(par) >= val_as_i16(par_op)); break;
                case ap_type_id_i32: ret = make (&val_t) from (2, ret_type, val_as_i32(par) >= val_as_i32(par_op)); break;
                case ap_type_id_i64: ret = make (&val_t) from (2, ret_type, val_as_i64(par) >= val_as_i64(par_op)); break;

                case ap_type_id_u8 : ret = make (&val_t) from (2, ret_type, val_as_u8 (par) >= val_as_u8 (par_op)); break;
                case ap_type_id_u16: ret = make (&val_t) from (2, ret_type, val_as_u16(par) >= val_as_u16(par_op)); break;
                case ap_type_id_u32: ret = make (&val_t) from (2, ret_type, val_as_u32(par) >= val_as_u32(par_op)); break;
                case ap_type_id_u64: ret = make (&val_t) from (2, ret_type, val_as_u64(par) >= val_as_u64(par_op)); break;

                case ap_type_id_f32: ret = make (&val_t) from (2, ret_type, val_as_f32(par) >= val_as_f32(par_op)); break;
                case ap_type_id_f64: ret = make (&val_t) from (2, ret_type, val_as_f64(par) >= val_as_f64(par_op)); break;
            }

            del   (ret_type);
            return ret;
}

val* 
    val_lt
        (val* par, val* par_op)                                       {
            ap_type type     = ap_type_common(par->type, par_op->type); if (!type) return 0;
            ap_type ret_type = ap_bool;
            val    *ret      = 0      ;
            switch(ap_type_id(type))                                                                                  {
                case ap_type_id_i8 : ret = make (&val_t) from (2, ret_type, val_as_i8 (par) < val_as_i8 (par_op)); break;
                case ap_type_id_i16: ret = make (&val_t) from (2, ret_type, val_as_i16(par) < val_as_i16(par_op)); break;
                case ap_type_id_i32: ret = make (&val_t) from (2, ret_type, val_as_i32(par) < val_as_i32(par_op)); break;
                case ap_type_id_i64: ret = make (&val_t) from (2, ret_type, val_as_i64(par) < val_as_i64(par_op)); break;

                case ap_type_id_u8 : ret = make (&val_t) from (2, ret_type, val_as_u8 (par) < val_as_u8 (par_op)); break;
                case ap_type_id_u16: ret = make (&val_t) from (2, ret_type, val_as_u16(par) < val_as_u16(par_op)); break;
                case ap_type_id_u32: ret = make (&val_t) from (2, ret_type, val_as_u32(par) < val_as_u32(par_op)); break;
                case ap_type_id_u64: ret = make (&val_t) from (2, ret_type, val_as_u64(par) < val_as_u64(par_op)); break;

                case ap_type_id_f32: ret = make (&val_t) from (2, ret_type, val_as_f32(par) < val_as_f32(par_op)); break;
                case ap_type_id_f64: ret = make (&val_t) from (2, ret_type, val_as_f64(par) < val_as_f64(par_op)); break;
            }

            del   (ret_type);
            return ret;
}

val* 
    val_lt_eq
        (val* par, val* par_op)                                       {
            ap_type type     = ap_type_common(par->type, par_op->type); if (!type) return 0;
            ap_type ret_type = ap_bool;
            val    *ret      = 0      ;
            switch(ap_type_id(type))                                                                                  {
                case ap_type_id_i8 : ret = make (&val_t) from (2, ret_type, val_as_i8 (par) <= val_as_i8 (par_op)); break;
                case ap_type_id_i16: ret = make (&val_t) from (2, ret_type, val_as_i16(par) <= val_as_i16(par_op)); break;
                case ap_type_id_i32: ret = make (&val_t) from (2, ret_type, val_as_i32(par) <= val_as_i32(par_op)); break;
                case ap_type_id_i64: ret = make (&val_t) from (2, ret_type, val_as_i64(par) <= val_as_i64(par_op)); break;

                case ap_type_id_u8 : ret = make (&val_t) from (2, ret_type, val_as_u8 (par) <= val_as_u8 (par_op)); break;
                case ap_type_id_u16: ret = make (&val_t) from (2, ret_type, val_as_u16(par) <= val_as_u16(par_op)); break;
                case ap_type_id_u32: ret = make (&val_t) from (2, ret_type, val_as_u32(par) <= val_as_u32(par_op)); break;
                case ap_type_id_u64: ret = make (&val_t) from (2, ret_type, val_as_u64(par) <= val_as_u64(par_op)); break;

                case ap_type_id_f32: ret = make (&val_t) from (2, ret_type, val_as_f32(par) <= val_as_f32(par_op)); break;
                case ap_type_id_f64: ret = make (&val_t) from (2, ret_type, val_as_f64(par) <= val_as_f64(par_op)); break;
            }

            del   (ret_type);
            return ret;
}

val* 
    val_and
        (val* par, val* par_op)                   {
            if(!ap_is_bool(par   ->type)) return 0;
            if(!ap_is_bool(par_op->type)) return 0;

            return make (&val_t) from (2, par->type, val_as_bool(par) && val_as_bool(par_op));
}

val* 
    val_or
        (val* par, val* par_op)                   {
            if(!ap_is_bool(par   ->type)) return 0;
            if(!ap_is_bool(par_op->type)) return 0;

            return make (&val_t) from (2, par->type, val_as_bool(par) || val_as_bool(par_op));
}

val* 
    val_not
        (val* par)                             {
            if(!ap_is_bool(par->type)) return 0;
            return make (&val_t) from (2, par->type, !val_as_bool(par));
}