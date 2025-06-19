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

    dbg(d_count_bits(2342432));
    dbg(d_compute_parity(2342432));

    forge_run();
    return 0;
}
