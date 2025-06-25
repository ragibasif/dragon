/*
 * File: d_mem_debug.c
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Store the file name, line number, and function name. This is useful for
 * debugging and logging.
 *
 */

#include "dragon.h"

struct d_location {
    char *file;
    unsigned int line;
    char *function;
};

static struct d_location *d_location_create(struct d_location *location,
                                            const char *file, unsigned int line,
                                            const char *function) {
    location = malloc(sizeof(*location));
    location->file = malloc((strlen(file) + 1) * sizeof(*location->file));
    memcpy(location->file, file, strlen(file));
    location->file[strlen(file)] = '\0';
    location->line = line;
    location->function =
        malloc((strlen(function) + 1) * sizeof(*location->function));
    memcpy(location->function, function, strlen(function));
    location->function[strlen(function)] = '\0';
    return location;
}

static void d_location_destroy(struct d_location *location) {
    free(location->file);
    location->file = NULL;
    free(location->function);
    location->function = NULL;
    location->line = 0;
    free(location);
    location = NULL;
}

extern void d_mem_debug_create(void);
extern void *d_mem_debug_malloc(const char *file, unsigned int line,
                                const char *function, void *pointer,
                                size_t size);
extern void *d_mem_debug_realloc(void);
extern void *d_mem_debug_calloc(void);
extern void d_mem_debug_free(void);
extern void d_mem_debug_report(void);
extern void d_mem_debug_memory_dump(void);
extern void d_mem_debug_destroy(void);
