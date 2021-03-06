/*
 * MicroSim Project
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 LocalAreaGaming
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "random.h"
#include "game.h"

game_t game; //global

void game_init(void) {
    memset(&game, 0, sizeof(game_t));
    product_init(&game.product);
    
    int i;
    int num_employees = rand_uint32_range(GAME_EMPLOYEES_START_MIN, GAME_EMPLOYEES_START_MAX);
    for (i = 0; i < num_employees; i++) {
        employee_init(&game.employees[i]);
    }
}

void game_print(void) {
    product_print(&game.product);
}

void game_print_employees(void) {
    int i;
    for (i = 0; i < GAME_EMPLOYEES_MAX; i++) {
        employee_t *e = &game.employees[i];
        if (e->valid) {
            employee_print(e);
            printf("\n");
        }
    }
}

void game_step(void) {
    int i;
    // handle input

    for (i = 0; i < GAME_EMPLOYEES_MAX; i++) {
        employee_t *e = &game.employees[i];
        if (e->valid) {
            employee_step(&game.employees[i]);
        }
    }
    game.step++;
}
