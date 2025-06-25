/*
 * File: main.c
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

#include "dragon.h"
#include "third_party_c/internal_debug.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    d_log_create(NULL);
    D_LOG("Welcome");
    D_LOG_WARNING("HELLO");
    D_LOG_DEBUG("HELLO");
    D_LOG_TRACE("HELLO");
    D_LOG_ERROR("HELLO");
    D_LOG_FATAL("HELLO");
    d_log_destroy();

    forge_run();
    return 0;
}
