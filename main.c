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

#include "log.h"
#include "third_party_c/internal_debug.h"

void log_demo(void) {
    int port = 8080;
    size_t i = 32;
    char *filename = "output.txt";
    log_initialize(NULL);
    LOG_INFO("Server running on port %d.", port);
    LOG_WARN("Low memory detected.");
    LOG_DEBUG("Loop iteration: %u", i);
    LOG_ERROR("File not found - %s.", filename);
    log_finalize();
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    log_demo();
    forge_run();
    return 0;
}
