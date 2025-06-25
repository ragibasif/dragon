/*
 * File: d_bit_fiddling.c
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 *
 * Notes:
 *      - n & (n - 1) == n with its lowest set bit erased
 *
 *
 *
 */

#include "dragon.h"

// time: O(N)
int d_bit_count(int n) {
    int num_bits = 0;
    while (n) {
        num_bits += n & 1;
        n >>= 1;
    }
    return num_bits;
}

// 1 if # of 1s in the word is odd, otherwise 0
// brute force method, time: O(N)
// iteratively check the value of each bit and count ones
// we only care if there are odd or even number of ones so store it mod 2
int d_bit_parity(int n) {
    int result = 0;
    while (n) {
        result ^= n & 1;
        n >>= 1;
    }
    return result;
}
