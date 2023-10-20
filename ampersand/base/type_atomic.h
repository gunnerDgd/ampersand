#ifndef __TYPE_ATOMIC_H__
#define __TYPE_ATOMIC_H__

#include "type.h"

typedef volatile uint8_t  atomic_u8_t ;
typedef volatile uint16_t atomic_u16_t;
typedef volatile uint32_t atomic_u32_t;
typedef volatile uint64_t atomic_u64_t;

typedef volatile int8_t   atomic_i8_t ;
typedef volatile int16_t  atomic_i16_t;
typedef volatile int32_t  atomic_i32_t;
typedef volatile int64_t  atomic_i64_t;

#endif
