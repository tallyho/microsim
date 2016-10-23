#include <stdio.h>

#include "menu.h"
#include "game.h"
#include "util.h"

void show_main();

void show_product() {
    print_title("PRODUCT STATUS");
    product_print(&game.product);
    show_main();
}

void show_employees() {
    print_title("EMPLOYEES");
    game_print_employees();
    show_main();
}

void show_main() {
    print_title("MAIN");
    menu_entry_t menu[] = {
        {.label = "Product Status", .cb = show_product},
        {.label = "Employees",      .cb = show_employees},
        {.label = "Quit"},
    };

    do_menu(menu, ARRAY_SIZE(menu));
}

int main() {
    printf("Welcome to the Micromanager simulator");
    printf("You have been chosen as the manager for a failing business unit.\nPlease save the company!\n\n");

    game_init();

    show_main();
    printf("Bye!\n");

	return 0;
}
