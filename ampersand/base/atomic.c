#include "atomic.h"
#include "details/atomic.h"

atomic_u8_t
    atomic_add8
        (atomic_u8_t * par_dst, atomic_u8_t par_add) {
            return __atomic_add8(par_dst, par_add);
}

atomic_u16_t
    atomic_add16
        (atomic_u16_t * par_dst, atomic_u16_t par_add) {
            return __atomic_add16(par_dst, par_add);
}

atomic_u32_t
    atomic_add32
        (atomic_u32_t * par_dst, atomic_u32_t par_add) {
            return __atomic_add32(par_dst, par_add);
}

atomic_u64_t
    atomic_add64
        (atomic_u64_t * par_dst, atomic_u64_t par_add) {
            return __atomic_add64(par_dst, par_add);
}


atomic_u8_t
    atomic_sub8
        (atomic_u8_t * par_dst, atomic_u8_t par_add) {
            return __atomic_sub8(par_dst, par_add);
}

atomic_u16_t
    atomic_sub16
        (atomic_u16_t * par_dst, atomic_u16_t par_add) {
            return __atomic_sub16(par_dst, par_add);
}

atomic_u32_t
    atomic_sub32
        (atomic_u32_t * par_dst, atomic_u32_t par_add) {
            return __atomic_sub32(par_dst, par_add);
}

atomic_u64_t
    atomic_sub64
        (atomic_u64_t * par_dst, atomic_u64_t par_add) {
            return __atomic_sub64(par_dst, par_add);
}


atomic_u8_t
    atomic_inc8
        (atomic_u8_t * par_dst, atomic_u8_t par_add) {
            return __atomic_inc8(par_dst, par_add);
}

atomic_u16_t
    atomic_inc16
        (atomic_u16_t * par_dst, atomic_u16_t par_add) {
            return __atomic_inc16(par_dst, par_add);
}

atomic_u32_t
    atomic_inc32
        (atomic_u32_t * par_dst, atomic_u32_t par_add) {
            return __atomic_inc32(par_dst, par_add);
}

atomic_u64_t
    atomic_inc64
        (atomic_u64_t * par_dst, atomic_u64_t par_add) {
            return __atomic_inc64(par_dst, par_add);
}


atomic_u8_t
    atomic_dec8
        (atomic_u8_t * par_dst, atomic_u8_t par_add) {
            return __atomic_dec8(par_dst, par_add);
}

atomic_u16_t
    atomic_dec16
        (atomic_u16_t * par_dst, atomic_u16_t par_add) {
            return __atomic_dec16(par_dst, par_add);
}

atomic_u32_t
    atomic_dec32
        (atomic_u32_t * par_dst, atomic_u32_t par_add) {
            return __atomic_dec32(par_dst, par_add);
}

atomic_u64_t
    atomic_dec64
        (atomic_u64_t * par_dst, atomic_u64_t par_add) {
            return __atomic_dec64(par_dst, par_add);
}


atomic_u8_t
    atomic_cmpxchg8
        (atomic_u8_t * par_dst, atomic_u8_t par_expected, atomic_u8_t par_exchange) {
            return __atomic_cmpxchg8(par_dst, par_expected, par_exchange);
}

atomic_u16_t
    atomic_cmpxchg16
        (atomic_u16_t * par_dst, atomic_u16_t par_expected, atomic_u16_t par_exchange) {
            return __atomic_cmpxchg16(par_dst, par_expected, par_exchange);
}

atomic_u32_t
    atomic_cmpxchg32
        (atomic_u32_t * par_dst, atomic_u32_t par_expected, atomic_u32_t par_exchange) {
            return __atomic_cmpxchg32(par_dst, par_expected, par_exchange);
}

atomic_u64_t
    atomic_cmpxchg64
        (atomic_u64_t * par_dst, atomic_u64_t par_expected, atomic_u64_t par_exchange) {
            return __atomic_cmpxchg64(par_dst, par_expected, par_exchange);
}