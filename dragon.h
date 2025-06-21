/*
 * File: dragon.h
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * C utility library.
 *
 */

#ifndef __DRAGON_H__
#define __DRAGON_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/* --- Version Information --- */
#define DRAGON_VERSION_MAJOR 1 /**< Major version (API-breaking changes) */
#define DRAGON_VERSION_MINOR                                                   \
    0 /**< Minor version (backwards-compatible additions) */
#define DRAGON_VERSION_PATCH 0 /**< Patch version (bug fixes) */

/* String representation of version */
#define DRAGON_VERSION_STRING "1.0.0"

/* Version comparison macros (useful for dependency checks) */
#define DRAGON_VERSION_CHECK(major, minor, patch)                              \
    ((major) < DRAGON_VERSION_MAJOR ||                                         \
     ((major) == DRAGON_VERSION_MAJOR && (minor) < DRAGON_VERSION_MINOR) ||    \
     ((major) == DRAGON_VERSION_MAJOR && (minor) == DRAGON_VERSION_MINOR &&    \
      (patch) <= DRAGON_VERSION_PATCH))

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include <assert.h> // assert
#include <ctype.h>
#include <limits.h>  // INT_MAX, INT_MIN
#include <pthread.h> // pthread
#include <stdarg.h>  // va_args, va_end, va_start, va_list
#include <stdbool.h> // bool, true, false
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>  // printf, puts
#include <stdlib.h> // malloc, realloc, calloc, free
#include <string.h> // strlen, memcpy, strcpy
#include <time.h>   // time

#include "third_party/internal_debug.h" // internal mem debug and print debug

//------------------------------------------------------------------------------
// Utility Macros
//------------------------------------------------------------------------------

#define D_MOD(a, b) ((a) % (b) + (b)) % (b)

#define D_PI 3.14159265358979323846f
#define D_ABS(val) ((val) < 0) ? -(val) : (val)
#define D_AREA(l, w) (l * w)
#define D_AVERAGE(val1, val2) (((double)(val1) + (val2)) / 2.0)
#define D_BIT_CHK(bit, reg) ((reg >> (bit)) & 1)
#define D_BIT_CLR(value, bit) ((value) &= ~(1L << (bit)))
#define D_BIT_LSB(reg) ((reg) & 1)
#define D_BIT_SET(value, bit) ((value) |= (1L << (bit)))
#define D_CIRCUMFERENCE(radius) (PI * radious * radious) // circle circumference
#define D_IN_RANGE(x, lo, hi) (((x > lo) && (x < hi)) || (x == lo) || (x == hi))
#define D_IS_EVEN(x) !BIT_LSB(x)
#define D_IS_ODD(x) (x & 1)

#define D_MAX(a, b)                                                            \
    ({                                                                         \
        __typeof__(a) _a = (a);                                                \
        __typeof__(b) _b = (b);                                                \
        _a > _b ? _a : _b;                                                     \
    })

#define D_MIN(a, b)                                                            \
    ({                                                                         \
        __typeof__(a) _a = (a);                                                \
        __typeof__(b) _b = (b);                                                \
        _a < _b ? _a : _b;                                                     \
    })

#define D_PERCENT(val, per) ((val) * (per) / 100.0)
#define D_RAND_INT(min, max) ((rand() % (int)(((max) + 1) - (min))) + (min))
#define D_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define D_SUM(a, b) (a + b)
#define D_XOR_SWAP(a, b)                                                       \
    do {                                                                       \
        (a) ^= (b);                                                            \
        (b) ^= (a);                                                            \
        (a) ^= (b);                                                            \
    } while (0)

#define D_PRINT_CHAR(x) printf("%c", x) // print char
#define D_PRINT_STR(x) printf("%s", x)  // print string of characters

// integer
#define D_INPUT_INT(x) scanf("%d", &x)     // int
#define D_INPUT_SHORT(x) scanf("%hd", &x)  // short int
#define D_INPUT_LINT(x) scanf("%ld", &x)   // lont int
#define D_INPUT_LLINT(x) scanf("%lld", &x) // long long int
#define D_INPUT_OCT(x) scanf("%o", &x)     // octal
#define D_INPUT_HEX(x) scanf("%x", &x)     // hexadecimal
#define D_INPUT_UINT(x) scanf("%u", &x)    // unsigned int

#define D_PRINT_INT(x) printf("%d", x)     // int
#define D_PRINT_SHORT(x) printf("%hd", x)  // short int
#define D_PRINT_LINT(x) printf("%ld", x)   // long int
#define D_PRINT_LLINT(x) printf("%lld", x) // long long int
#define D_PRINT_OCT(x) printf("%o", x)     // octal without leading zeros
#define D_PRINT_HEX(x) printf("%x", x)     // hexadecimal
#define D_PRINT_UINT(x) printf("%u", x)    // unsigned int

// floating point
#define D_INPUT_FLOAT(x) scanf("%f", &x)    // float
#define D_INPUT_DOUBLE(x) scanf("%lf", &x)  // double
#define D_INPUT_LDOUBLE(x) scanf("%Lf", &x) // long double
#define D_INPUT_FLOATEXP(x) scanf("%e", &x) // floating point exponent

#define D_PRINT_FLOAT(x) printf("%f", x)    // float
#define D_PRINT_DOUBLE(x) printf("%lf", x)  // double
#define D_PRINT_LDOUBLE(x) printf("%Lf", x) // long double
#define D_PRINT_FLOATEXP(x) printf("%e", x) // floating point exponent

// rounded integer division:

#define D_FLOOR_DIV(x, y) ((x) / (y))
#define D_CEIL_DIV(x, y) FLOOR_DIV((x) + (y - 1), y)
#define D_ROUND_DIV(x, y) FLOOR_DIV((x) + (y) / 2, y)

#define D_OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

#define D_SWAP(a, b)                                                           \
    do {                                                                       \
        __typeof__(a) _a = (a);                                                \
        __typeof__(b) _b = (b);                                                \
        _a < _b ? _a : _b;                                                     \
        (a) = _b;                                                              \
        (b) = _a;                                                              \
    } while (0)

#define D_STR(x) #x

typedef unsigned char BYTE; // name BYTE for one-byte numbers

// press any key (linux & ms windows)
#define D_PRESSKEY                                                             \
    printf("\n\t Press any key to continue...");                               \
    while (1) {                                                                \
        if (getc(stdin)) {                                                     \
            break;                                                             \
        }                                                                      \
    }

//------------------------------------------------------------------------------
// ANSI Escape Codes
//------------------------------------------------------------------------------

// Reset all attributes
#define D_AEC_RESET "\x1b[0m"

// Text colors
#define D_AEC_BLACK "\x1b[30m"
#define D_AEC_RED "\x1b[31m"
#define D_AEC_GREEN "\x1b[32m"
#define D_AEC_YELLOW "\x1b[33m"
#define D_AEC_BLUE "\x1b[34m"
#define D_AEC_MAGENTA "\x1b[35m"
#define D_AEC_CYAN "\x1b[36m"
#define D_AEC_WHITE "\x1b[37m"
#define D_AEC_DEFAULT "\x1b[39m"

// Background colors
#define D_AEC_BG_BLACK "\x1b[40m"
#define D_AEC_BG_RED "\x1b[41m"
#define D_AEC_BG_GREEN "\x1b[42m"
#define D_AEC_BG_YELLOW "\x1b[43m"
#define D_AEC_BG_BLUE "\x1b[44m"
#define D_AEC_BG_MAGENTA "\x1b[45m"
#define D_AEC_BG_CYAN "\x1b[46m"
#define D_AEC_BG_WHITE "\x1b[47m"
#define D_AEC_BG_DEFAULT "\x1b[49m"

// Bright text colors
#define D_AEC_BRIGHT_BLACK "\x1b[90m"
#define D_AEC_BRIGHT_RED "\x1b[91m"
#define D_AEC_BRIGHT_GREEN "\x1b[92m"
#define D_AEC_BRIGHT_YELLOW "\x1b[93m"
#define D_AEC_BRIGHT_BLUE "\x1b[94m"
#define D_AEC_BRIGHT_MAGENTA "\x1b[95m"
#define D_AEC_BRIGHT_CYAN "\x1b[96m"
#define D_AEC_BRIGHT_WHITE "\x1b[97m"

// Bright background colors
#define D_AEC_BG_BRIGHT_BLACK "\x1b[100m"
#define D_AEC_BG_BRIGHT_RED "\x1b[101m"
#define D_AEC_BG_BRIGHT_GREEN "\x1b[102m"
#define D_AEC_BG_BRIGHT_YELLOW "\x1b[103m"
#define D_AEC_BG_BRIGHT_BLUE "\x1b[104m"
#define D_AEC_BG_BRIGHT_MAGENTA "\x1b[105m"
#define D_AEC_BG_BRIGHT_CYAN "\x1b[106m"
#define D_AEC_BG_BRIGHT_WHITE "\x1b[107m"

// Text attributes
#define D_AEC_BOLD "\x1b[1m"
#define D_AEC_DIM "\x1b[2m"
#define D_AEC_ITALIC "\x1b[3m"
#define D_AEC_UNDERLINE "\x1b[4m"
#define D_AEC_BLINK "\x1b[5m"
#define D_AEC_REVERSE "\x1b[7m"
#define D_AEC_HIDDEN "\x1b[8m"
#define D_AEC_STRIKETHROUGH "\x1b[9m"

// Reset specific attributes
#define D_AEC_NO_BOLD "\x1b[21m" // or "\x1b[22m" (both work)
#define D_AEC_NO_ITALIC "\x1b[23m"
#define D_AEC_NO_UNDERLINE "\x1b[24m"
#define D_AEC_NO_BLINK "\x1b[25m"
#define D_AEC_NO_REVERSE "\x1b[27m"
#define D_AEC_NO_HIDDEN "\x1b[28m"
#define D_AEC_NO_STRIKETHROUGH "\x1b[29m"

// 256-color support
#define D_AEC_COLOR256(n) "\033[38;5;" #n "m"
#define D_AEC_BG_COLOR256(n) "\033[48;5;" #n "m"

// Truecolor (RGB) support
#define D_AEC_RGB(r, g, b) "\033[38;2;" #r ";" #g ";" #b "m"
#define D_AEC_BG_RGB(r, g, b) "\033[48;2;" #r ";" #g ";" #b "m"

// Cursor movement
#define D_AEC_CURSOR_UP(n) "\x1b[" #n "A"
#define D_AEC_CURSOR_DOWN(n) "\x1b[" #n "B"
#define D_AEC_CURSOR_FORWARD(n) "\x1b[" #n "C"
#define D_AEC_CURSOR_BACK(n) "\x1b[" #n "D"
#define D_AEC_CURSOR_NEXT_LINE(n) "\x1b[" #n "E"
#define D_AEC_CURSOR_PREV_LINE(n) "\x1b[" #n "F"
#define D_AEC_CURSOR_COLUMN(n) "\x1b[" #n "G"
#define D_AEC_CURSOR_POSITION(row, col) "\x1b[" #row ";" #col "H"

// Save and restore cursor position
#define D_AEC_CURSOR_SAVE "\x1b[s"
#define D_AEC_CURSOR_RESTORE "\x1b[u"

// Cursor visibility
#define D_AEC_CURSOR_HIDE "\x1b[?25l"
#define D_AEC_CURSOR_SHOW "\x1b[?25h"

// Screen operations
#define D_AEC_SCREEN_CLEAR "\x1b[2J"
#define D_AEC_SCREEN_CLEAR_LINE "\x1b[2K"
#define D_AEC_SCREEN_CLEAR_TO_END "\x1b[0J"
#define D_AEC_SCREEN_CLEAR_TO_START "\x1b[1J"
#define D_AEC_LINE_CLEAR_TO_END "\x1b[0K"
#define D_AEC_LINE_CLEAR_TO_START "\x1b[1K"
#define D_AEC_SCROLL_UP(n) "\x1b[" #n "S"
#define D_AEC_SCROLL_DOWN(n) "\x1b[" #n "T"

// Terminal modes
#define D_AEC_ALTERNATE_BUFFER "\x1b[?1049h"
#define D_AEC_MAIN_BUFFER "\x1b[?1049l"
#define D_AEC_LINE_WRAP_ON "\x1b[?7h"
#define D_AEC_LINE_WRAP_OFF "\x1b[?7l"

//------------------------------------------------------------------------------
// d_location.c
//------------------------------------------------------------------------------

struct d_location {
    char *file;
    unsigned int line;
    char *function;
};

extern struct d_location *d_location_create(struct d_location *location,
                                            const char *file, unsigned int line,
                                            const char *function);
extern void d_location_memory_dump(struct d_location *location);
extern void d_location_destroy(struct d_location *location);

//------------------------------------------------------------------------------
// d_mem_debug.c
//------------------------------------------------------------------------------

#ifdef D_MEMORY_DEBUG_ENABLE
#endif // D_MEMORY_DEBUG_ENABLE

extern void d_mem_debug_create(void);
extern void d_mem_debug_malloc(const char *file, unsigned int line,
                               const char *function, void *pointer,
                               size_t size);
extern void d_mem_debug_realloc(void);
extern void d_mem_debug_calloc(void);
extern void d_mem_debug_free(void);
extern void d_mem_debug_report(void);
extern void d_mem_debug_memory_dump(void);
extern void d_mem_debug_destroy(void);

//------------------------------------------------------------------------------
// d_log.c
//------------------------------------------------------------------------------

enum d_log_type {
    D_INFO_TYPE = 0,
    D_DEBUG_TYPE = 1,
    D_TRACE_TYPE = 2,
    D_WARNING_TYPE = 3,
    D_ERROR_TYPE = 4,
    D_FATAL_TYPE = 5,
    D_COUNT_TYPE = 6
};

extern void d_log_create(const char *file);
extern void d_log_destroy();

extern void d_set_log_level(enum d_log_type level);
extern void d_log_message(enum d_log_type level, const char *file,
                          unsigned int line, const char *function,
                          const char *format, ...);

#define D_LOG_INFO(format, ...)                                                \
    log_message(D_INFO_TYPE, __FILE__, __LINE__, __func__, format,             \
                ##__VA_ARGS__)
#define D_LOG_DEBUG(format, ...)                                               \
    log_message(D_DEBUG_TYPE, __FILE__, __LINE__, __func__, format,            \
                ##__VA_ARGS__)
#define D_LOG_TRACE(format, ...)                                               \
    log_message(D_TRACE_TYPE, __FILE__, __LINE__, __func__, format,            \
                ##__VA_ARGS__)
#define D_LOG_WARNING(format, ...)                                             \
    log_message(D_WARNING_TYPE, __FILE__, __LINE__, __func__, format,          \
                ##__VA_ARGS__)
#define D_LOG_ERROR(format, ...)                                               \
    log_message(D_ERROR_TYPE, __FILE__, __LINE__, __func__, format,            \
                ##__VA_ARGS__)
#define D_LOG_FATAL(format, ...)                                               \
    log_message(D_FATAL_TYPE, __FILE__, __LINE__, __func__, format,            \
                ##__VA_ARGS__)

//------------------------------------------------------------------------------
// d_math.c
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Data Structures
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Algorithms
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// d_bit_fiddling.c
//------------------------------------------------------------------------------

extern int d_count_bits(int n);
extern int d_compute_parity(int n);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __DRAGON_H__
