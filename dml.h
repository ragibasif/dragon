/*
 * File: dml.h
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

#ifndef DML_H_
#define DML_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "shared.h"

#ifdef D_MEMORY_LOG
#endif // D_MEMORY_LOG

extern void d_mem_log_create(void);
extern void *d_mem_log_malloc(const char *file, unsigned int line,
                              const char *function, void *pointer, size_t size);
extern void *d_mem_log_realloc(void);
extern void *d_mem_log_calloc(void);
extern void d_mem_log_free(void);
extern void d_mem_log_report(void);
extern void d_mem_log_memory_dump(void);
extern void d_mem_log_destroy(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // DML_H_
