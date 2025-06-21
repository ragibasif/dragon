/*
 * File: d_location_test.c
 * Author: Ragib Asif
 * Email: ragib.asif30@myhunter.cuny.edu
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 *
 */

#include "../dragon.h"

void d_location_test() {
    puts("========================================");
    printf("%s %s\n", __FILE__, __func__);

    {
        static struct d_location *a;
        static const char *file = __FILE__;
        static const char *function = __func__;
        static const unsigned int line = __LINE__;
        a = d_location_create(a, file, line, function);
        d_location_memory_dump(a);
        assert(*a->file == *file);
        assert(a->line == line);
        assert(*a->function == *function);
        d_location_destroy(a);
    }

    {
        static struct d_location *a;
        static const char *file = "";
        static const char *function = "";
        static const unsigned int line = 0;
        a = d_location_create(a, file, line, function);
        d_location_memory_dump(a);
        assert(*a->file == *file);
        assert(a->line == line);
        assert(*a->function == *function);
        d_location_destroy(a);
    }

    {
        static struct d_location *a;
        static const char *file = __FILE__;
        static const char *function = __func__;
        static const unsigned int line = __LINE__;
        a = d_location_create(a, "main.c", __LINE__, function);
        d_location_memory_dump(a);
        assert(*a->file != *file);
        assert(a->line != line);
        assert(*a->function == *function);
        d_location_destroy(a);
    }

    puts("========================================");
}
