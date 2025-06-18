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

// time: O(N)
int count_bits(int n) {
    int num_bits = 0;
    while (n) {
        num_bits += n & 1;
        n >>= 1;
    }
    return num_bits;
}

// 1 if # of 1s in the word is odd
// otherwise 0

// brute force method, time: O(N)
// iteratively check the value of each bit and count ones
// we only care if there are negative or positive number of ones so store it
// mod 2
int parity_00(int n) {
    int result = 0;
    while (n) {
        result ^= n & 1;
        n >>= 1;
    }
    return result;
}
int parity_01(int n) {
    // n & (n - 1) == n with its lowest set bit erased
    int result = 0;
    while (n) {
        result ^= n & 1;
        n >>= 1;
    }
    return result;
}

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;

    dbg(count_bits(2342432));
    printf("%d\n", count_bits(2342432));

    forge_run();
    return 0;
}
