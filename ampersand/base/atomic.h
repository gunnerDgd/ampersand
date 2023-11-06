#ifndef __ATOMIC_H__
#define __ATOMIC_H__

#include "type_atomic.h"

atomic_u8_t  atomic_add8 (atomic_u8_t  *, atomic_u8_t) ;
atomic_u16_t atomic_add16(atomic_u16_t *, atomic_u16_t);
atomic_u32_t atomic_add32(atomic_u32_t *, atomic_u32_t);
atomic_u64_t atomic_add64(atomic_u64_t *, atomic_u64_t);

atomic_u8_t  atomic_sub8 (atomic_u8_t *, atomic_u8_t);
atomic_u16_t atomic_sub16(atomic_u16_t *, atomic_u16_t);
atomic_u32_t atomic_sub32(atomic_u32_t *, atomic_u32_t);
atomic_u64_t atomic_sub64(atomic_u64_t *, atomic_u64_t);

atomic_u8_t  atomic_inc8 (atomic_u8_t  *);
atomic_u16_t atomic_inc16(atomic_u16_t *);
atomic_u32_t atomic_inc32(atomic_u32_t *);
atomic_u64_t atomic_inc64(atomic_u64_t *);

atomic_u8_t  atomic_dec8 (atomic_u8_t *);
atomic_u16_t atomic_dec16(atomic_u16_t*);
atomic_u32_t atomic_dec32(atomic_u32_t*);
atomic_u64_t atomic_dec64(atomic_u64_t*);

atomic_u8_t  atomic_cmpxchg8 (atomic_u8_t  *, atomic_u8_t, atomic_u8_t);
atomic_u16_t atomic_cmpxchg16(atomic_u16_t *, atomic_u16_t, atomic_u16_t);
atomic_u32_t atomic_cmpxchg32(atomic_u32_t *, atomic_u32_t, atomic_u32_t);
atomic_u64_t atomic_cmpxchg64(atomic_u64_t *, atomic_u64_t, atomic_u64_t);

#endif
