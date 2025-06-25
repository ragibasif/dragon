/*
 * File: log.h
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 * Minimal logging library.
 *
 */

#ifndef LOG_H_
#define LOG_H_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

enum log_type {
    LT_INFO = 0,
    LT_DEBUG = 1,
    LT_WARN = 3,
    LT_ERROR = 4,
};

extern void log_initialize(const char *file);
extern void log_finalize(void);
extern void log_message(enum log_type level, const char *file,
                        unsigned int line, const char *function,
                        const char *format, ...);

#define LOG_INFO(format, ...)                                                  \
    log_message(LT_INFO, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define LOG_DEBUG(format, ...)                                                 \
    log_message(LT_DEBUG, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define LOG_WARN(format, ...)                                                  \
    log_message(LT_WARN, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)
#define LOG_ERROR(format, ...)                                                 \
    log_message(LT_ERROR, __FILE__, __LINE__, __func__, format, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // LOG_H_
