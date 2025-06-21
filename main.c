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
 * Entry point to the program.
 *
 */

#include "dragon.h"
#include "third_party/internal_debug.h"

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    struct d_location *location;
    location = d_location_create(location, __FILE__, __LINE__, __func__);
    d_location_memory_dump(location);
    d_location_destroy(location);

    forge_run();
    return 0;
}
