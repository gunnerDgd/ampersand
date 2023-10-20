#ifndef __TYPE_H__
#define __TYPE_H__

#ifdef PRESET_LINUX
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdarg.h>
#endif

#ifdef PRESET_WIN32
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdarg.h>
#endif

typedef uint8_t  u8_t ;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;
typedef int8_t   i8_t ;
typedef int16_t  i16_t;
typedef int32_t  i32_t;
typedef int64_t  i64_t;
typedef bool     bool_t;

#define false_t  0
#define true_t   1

#endif
