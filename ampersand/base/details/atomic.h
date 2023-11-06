#ifndef __DETAILS_ATOMIC_H__
#define __DETAILS_ATOMIC_H__

#include "../type_atomic.h"

atomic_u8_t  __atomic_add8 (atomic_u8_t *, atomic_u8_t);
atomic_u16_t __atomic_add16(atomic_u16_t *, atomic_u16_t);
atomic_u32_t __atomic_add32(atomic_u32_t *, atomic_u32_t);
atomic_u64_t __atomic_add64(atomic_u64_t *, atomic_u64_t);

atomic_u8_t  __atomic_sub8 (atomic_u8_t  *, atomic_u8_t);
atomic_u16_t __atomic_sub16(atomic_u16_t *, atomic_u16_t);
atomic_u32_t __atomic_sub32(atomic_u32_t *, atomic_u32_t);
atomic_u64_t __atomic_sub64(atomic_u64_t *, atomic_u64_t);

atomic_u8_t  __atomic_inc8 (atomic_u8_t *);
atomic_u16_t __atomic_inc16(atomic_u16_t*);
atomic_u32_t __atomic_inc32(atomic_u32_t*);
atomic_u64_t __atomic_inc64(atomic_u64_t*);

atomic_u8_t  __atomic_dec8 (atomic_u8_t *);
atomic_u16_t __atomic_dec16(atomic_u16_t*);
atomic_u32_t __atomic_dec32(atomic_u32_t*);
atomic_u64_t __atomic_dec64(atomic_u64_t*);

atomic_u8_t  __atomic_cmpxchg8 (atomic_u8_t *, atomic_u8_t, atomic_u8_t);
atomic_u16_t __atomic_cmpxchg16(atomic_u16_t *, atomic_u16_t, atomic_u16_t);
atomic_u32_t __atomic_cmpxchg32(atomic_u32_t *, atomic_u32_t, atomic_u32_t);
atomic_u64_t __atomic_cmpxchg64(atomic_u64_t *, atomic_u64_t, atomic_u64_t);

#endif
