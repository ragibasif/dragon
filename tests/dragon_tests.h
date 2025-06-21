/*
 * File: dragon_tests.h
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 */

#ifndef __DRAGON_TESTS_H__
#define __DRAGON_TESTS_H__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "../dragon.h"

//------------------------------------------------------------------------------
// d_location_test.c
//------------------------------------------------------------------------------

extern void d_location_test(void);

//------------------------------------------------------------------------------
// d_mem_debug.c
//------------------------------------------------------------------------------

extern void d_mem_debug_test(void);

//------------------------------------------------------------------------------
// d_log.c
//------------------------------------------------------------------------------

extern void d_log_test(void);

//------------------------------------------------------------------------------
// d_math.c
//------------------------------------------------------------------------------

extern void d_math_test(void);

//------------------------------------------------------------------------------
// d_bit_fiddling.c
//------------------------------------------------------------------------------

extern void d_bit_fiddling_test(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __DRAGON_TESTS_H__
