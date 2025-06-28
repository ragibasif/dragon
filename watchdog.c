/*
 * File: watchdog.c
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

#include "watchdog.h"

struct location {
    char *file;
    unsigned int line;
    char *function;
};

static struct location *location_create(struct location *location,
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

static void location_destroy(struct location *location) {
    free(location->file);
    location->file = NULL;
    free(location->function);
    location->function = NULL;
    location->line = 0;
    free(location);
    location = NULL;
}

struct allocation_buffer {
    void *pointer;
    size_t size;
};

struct free_buffer {
    void *pointer;
    size_t size;
};

struct allocation_metadata {
    struct allocation_buffer *buffer;
    struct location *location;
    struct allocation_metadata *prev;
    struct allocation_metadata *next;
};

struct freed_metadata {
    struct allocation_metadata *allocation;
    struct location *location;
    struct freed_metadata *prev;
    struct freed_metadata *next;
};

struct allocation_data {
    struct allocation_metadata *allocation_head;
    struct freed_metadata *free_head;
    size_t total_bytes_allocated;
    size_t total_bytes_freed;
    size_t total_allocations;
    size_t total_frees;
};

static struct allocation_data mem_data;

void w_create(void) {
    mem_data.allocation_head = NULL;
    mem_data.free_head = NULL;
    mem_data.total_bytes_allocated = 0;
    mem_data.total_bytes_freed = 0;
    mem_data.total_allocations = 0;
    mem_data.total_frees = 0;
}

void *w_malloc(const char *file, unsigned int line, const char *function,
               void *pointer, size_t size);
void *w_realloc(void);
void *w_calloc(void);
void w_free(void);
void w_report(void);
void w_dump(void);
void w_destroy(void);
