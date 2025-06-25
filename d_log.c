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
 * Compile the library with `-DD_LOG_COLOR` to print with ANSI color escape
 * codes. If a log file is specified, ANSI color escape will be disabled
 * regardless of the flag.
 *
 */

#include "dragon.h"

static pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;
static FILE *d_log_file = NULL;
static enum d_log_type current_log_level = D_LT_INFO;

static const char *level_strings[] = {
    [D_LT_INFO] = "[INFO]",   [D_LT_DEBUG] = "[DEBUG]",
    [D_LT_TRACE] = "[TRACE]", [D_LT_WARNING] = "[WARNING]",
    [D_LT_ERROR] = "[ERROR]", [D_LT_FATAL] = "[FATAL]"};

#ifdef D_LOG_COLOR
static const char *level_colors[] = {
    [D_LT_INFO] = D_AEC_GREEN,    [D_LT_DEBUG] = D_AEC_CYAN,
    [D_LT_TRACE] = D_AEC_BLUE,    [D_LT_WARNING] = D_AEC_YELLOW,
    [D_LT_ERROR] = D_AEC_MAGENTA, [D_LT_FATAL] = D_AEC_RED};
#endif // D_LOG_COLOR

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

#ifdef D_LOG_COLOR
    if (d_log_file != stdout) {
        // do not output colors if logging to file
        fprintf(d_log_file, "%s [%s:%u (%s)] %s ", time_str, file, line,
                function, level_strings[level]);
    } else {
        fprintf(d_log_file, "%s%s [%s:%u (%s)]%s %s%s%s%s ", D_AEC_DIM,
                time_str, file, line, function, D_AEC_RESET, D_AEC_BOLD,
                level_colors[level], level_strings[level], D_AEC_RESET);
    }
#else
    fprintf(d_log_file, "%s [%s:%u (%s)] %s ", time_str, file, line, function,
            level_strings[level]);
#endif // D_LOG_COLOR

    va_list args;
    va_start(args, format);
    vfprintf(d_log_file, format, args);
    va_end(args);

    fprintf(d_log_file, "\n");
    fflush(d_log_file);

    pthread_mutex_unlock(&log_mutex);
}
