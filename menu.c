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

#include "menu.h"

typedef enum {
    MAIN_MENU_PRDUCT,
    MAIN_MENU_EMPLOYEES,
    MAIN_MENU_QUIT,
} main_menu_option_t;

menu_type_t active_menu;

static void print_menu(menu_type_t menu) {
    switch(menu) {
    case MENU_MAIN:
        printf("\r---- Main Menu ----\n");
        printf("\r1) Product Status\n");
        printf("\r2) Employees\n");
        printf("\r3) Quit\n");
        break;
        
    default:
        printf("UNKNOWN\n");
        break;
    }
}


void menu_set_active(menu_type_t menu) {
    active_menu = menu;

    print_menu(active_menu);
}

int menu_handle_input(char c) {
    switch(active_menu) {
    case MENU_MAIN:
        switch(c - '1') {
        case MAIN_MENU_QUIT:
            return 1;
        }
        break;

    default:
        break;
    }

    return 0;
}
