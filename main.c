#import <stdio.h>

#import "menu.h"
#import "game.h"

void show_main();

void show_product() {
    print_title("PRODUCT STATUS");
    product_print(&game.product);

    menu_entry_t menu[] = {
        {.label = "Product Status", .cb = show_product},
        {.label = "Business"},
        {.label = "Employees", .cb = game_print_employees},
        {.label = "Back", .cb = show_main},
    };

    do_menu(menu, sizeof(menu)/sizeof(menu_entry_t));
}

void show_main() {
    print_title("MAIN");
    menu_entry_t menu[] = {
        {.label = "Product Status", .cb = show_product},
        {.label = "Employees", .cb = game_print_employees},
        {.label = "Quit"},
    };

    do_menu(menu, sizeof(menu)/sizeof(menu_entry_t));
}

int main() {
    printf("Welcome to the Micromanager simulator");
    printf("You have been chosen as the manager for a failing business unit.\nPlease save the company!\n\n");

    game_init();

    show_main();
    printf("Bye!\n");

	return 0;
}
