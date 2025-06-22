/*
 * File: d_log.c
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Thread safe logging.
 *
 * References:
 *      - https://dev.to/scovl/creating-a-robust-logging-system-in-c-2fg6
 */

// TODO: External and Dynamic Configuration
// TODO: Custom Log Formatting
// TODO: Improve Error Handling
// TODO: Refactor for Code consistency
// TODO: Performance and Efficiency
// TODO: Security Enhancement
// TODO: Integrate with logging tools
// TODO: Testing and Validation
// TODO: Cross-platform logging

#include "../dragon.h"

static pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;
static FILE *d_log_file = NULL;
static enum d_log_type current_log_level = D_LT_INFO;

void d_log_create(const char *file) {
    pthread_mutex_lock(&log_mutex);
    if (file) {
        d_log_file = fopen(file, "a");
        if (!d_log_file) {
            fprintf(stderr, "Failed to open log file: %s\n", file);
            pthread_mutex_unlock(&log_mutex);
            exit(EXIT_FAILURE);
        }
    } else {
        d_log_file = stdout; // default to standard output
    }
    pthread_mutex_unlock(&log_mutex);
}

void d_log_destroy(void) {
    pthread_mutex_lock(&log_mutex);
    if (d_log_file && d_log_file != stdout) {
        fclose(d_log_file);
        d_log_file = NULL;
    }
    pthread_mutex_unlock(&log_mutex);
}

void d_log_set_level(enum d_log_type level) {
    pthread_mutex_lock(&log_mutex);
    current_log_level = level;
    pthread_mutex_unlock(&log_mutex);
}

void d_log_message(enum d_log_type level, const char *file, unsigned int line,
                   const char *function, const char *format, ...) {

    pthread_mutex_lock(&log_mutex);

    if (!d_log_file) {
        fprintf(stderr, "Logging not initialized.\n");
        pthread_mutex_unlock(&log_mutex);
        return;
    }
    time_t now;
    char *time_str;
    now = time(NULL);
    time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0';

    const char *level_strings[] = {
        [D_LT_INFO] = "[INFO]",   [D_LT_DEBUG] = "[DEBUG]",
        [D_LT_TRACE] = "[TRACE]", [D_LT_WARNING] = "[WARNING]",
        [D_LT_ERROR] = "[ERROR]", [D_LT_FATAL] = "[FATAL]"};

    fprintf(d_log_file, "%s [%s:%d (%s)] %s ", time_str, file, line, function,
            level_strings[level]);

    va_list args;
    va_start(args, format);
    vfprintf(d_log_file, format, args);
    va_end(args);

    fprintf(d_log_file, "\n");
    fflush(d_log_file);
    pthread_mutex_unlock(&log_mutex);
}
