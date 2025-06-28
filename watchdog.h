/*
 * File: watchdog.h
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 *
 */

#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "shared.h"

extern void w_create(void);
extern void *w_malloc(const char *file, unsigned int line, const char *function,
                      void *pointer, size_t size);
extern void *w_realloc(void);
extern void *w_calloc(void);
extern void w_free(void);
extern void w_report(void);
extern void w_dump(void);
extern void w_destroy(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // WATCHDOG_H_
