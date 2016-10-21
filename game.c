#import "game.h"

game_t game;

void game_init() {
    product_init(&game.product);
}

void game_print() {
    product_print(&game.product);
}

void game_print_employees() {
    for (int i = 0; i < MAX_EMPLOYEES; i++) {
        employee_print(&game.employees[i]);
    }
}
