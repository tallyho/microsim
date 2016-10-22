#include <stdio.h>
#include <stdlib.h>

#include "game.h"

game_t game; //global

void game_init() {
    product_init(&game.product);
    
    int i;
    int num_employees = GAME_EMPLOYEES_START_MIN + rand() % (GAME_EMPLOYEES_START_MAX-GAME_EMPLOYEES_START_MIN);
    for (i = 0; i < num_employees; i++) {
        employee_init(&game.employees[i]);
    }
}

void game_print() {
    product_print(&game.product);
}

void game_print_employees() {
    int i;
    for (i = 0; i < GAME_EMPLOYEES_MAX; i++) {
        employee_t *e = &game.employees[i];
        if (e->valid) {
            employee_print(e);
            printf("\n");
        }
    }
}
