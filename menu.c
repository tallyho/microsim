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
#include "game.h"
#include "activity_log.h"

typedef enum {
    MENU_MAIN,
    MENU_EMPLOYEES,
    MENU_DIRECT_EMPLOYEE,
} menu_type_t;

typedef enum {
    MAIN_MENU_MEETING,
    MAIN_MENU_COMPUTER,
    MAIN_MENU_EMPLOYEES,
    MAIN_MENU_QUIT,
} main_menu_option_t;

menu_type_t active_menu;
employee_t *active_employee;

static void print_menu(menu_type_t menu) {
    switch(menu) {
    case MENU_MAIN:
        printf("---- Main Menu ----\r\n");
        printf("1) Call a meeting\r\n");
        printf("2) Look at your computer\r\n");
        printf("3) Talk to employees\r\n");
        printf("4) Quit\r\n");
        break;

    case MENU_EMPLOYEES:
        printf("\r---- Employees ----\r\n");

        printf("\rB) Back\r\n\n");

        int i;
        int employee_count = 0;
        for (i = 0; i < GAME_EMPLOYEES_MAX; i++) {
            employee_t *e = &game.employees[i];
            if (!e->valid) {
                continue;
            }
            employee_count++;
            printf("%d) %s\r\n", employee_count, e->name);
        }
        break;

    case MENU_DIRECT_EMPLOYEE:
        printf("---- Direct Employee ----\r\n");
        employee_print(active_employee);
        printf("\n");
        printf("B) Back\r\n");
        printf("1) Twiddle thumbs\r\n");
        printf("2) Work on features\r\n");
        printf("3) Fix bugs\r\n");
        break;
        
    default:
        printf("UNKNOWN\r\n");
        break;
    }
}

static void menu_set_active(menu_type_t menu) {
    active_menu = menu;
    print_menu(active_menu);
}

void menu_init(void) {
    menu_set_active(MENU_MAIN);
}

int menu_handle_input(char c) {
    int i;
    int target_index;

    switch(active_menu) {
    case MENU_MAIN:
        switch(c - '1') {
        case MAIN_MENU_QUIT:
            return 1;
        case MAIN_MENU_MEETING:
            product_print(&game.product);
            print_menu(MENU_MAIN);
            break;
        case MAIN_MENU_EMPLOYEES:
            menu_set_active(MENU_EMPLOYEES);
            break;
        }
        break;
    case MENU_EMPLOYEES:
        switch(c) {
        case 'b':
        case 'B':
            menu_set_active(MENU_MAIN);
            break;
        default:
            target_index = c - '1';
            for (i = 0; i < GAME_EMPLOYEES_MAX; i++) {
                employee_t *e = &game.employees[i];
                if (!e->valid) {
                    continue;
                }

                if (target_index != 0) {
                    target_index--;
                    continue;
                }

                active_employee = e;
                menu_set_active(MENU_DIRECT_EMPLOYEE);
                break;
            }
            break;
        }
        break;

    case MENU_DIRECT_EMPLOYEE:
        switch(c) {
        case 'b':
        case 'B':
            menu_set_active(MENU_EMPLOYEES);
            break;
        case '1':
            if (active_employee->action.type != EMPLOYEE_ACTION_IDLE) {
                employee_start_action(active_employee, EMPLOYEE_ACTION_IDLE);
                menu_set_active(MENU_EMPLOYEES);
            }
            break;
        case '2':
            if (active_employee->action.type != EMPLOYEE_ACTION_FEATURE && product_features_idle_remaining(&game.product)) {
                employee_start_action(active_employee, EMPLOYEE_ACTION_FEATURE);
                menu_set_active(MENU_EMPLOYEES);
            }
            break;
        case '3':
            if (active_employee->action.type != EMPLOYEE_ACTION_BUG && product_bugs_idle_remaining(&game.product)) {
                employee_start_action(active_employee, EMPLOYEE_ACTION_BUG);
                menu_set_active(MENU_EMPLOYEES);
            }
            break;
        }

    default:
        break;
    }

    return 0;
}
