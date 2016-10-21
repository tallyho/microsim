#import <stdio.h>

#import "menu.h"
#import "game.h"

void show_main();

void show_product() {
    print_title("PRODUCT STATUS");

    print_game();

    menu_entry_t menu[] = {
        {.label = "Product Status", .cb = show_product},
        {.label = "Business"},
        {.label = "Employees"},
        {.label = "Back", .cb = show_main},
    };

    do_menu(menu, sizeof(menu)/sizeof(menu_entry_t));
}

void show_main() {
    print_title("MAIN");
    menu_entry_t menu[] = {
        {.label = "Product Status", .cb = show_product},
        {.label = "Employees"},
        {.label = "Quit"},
    };

    do_menu(menu, sizeof(menu)/sizeof(menu_entry_t));
}

int main() {
    printf("Welcome to the Micromanager simulator");
    printf("You have been chosen as the manager for a failing business unit.\nPlease save the company!\n\n");

    init_game();

    show_main();
    printf("Bye!\n");

	return 0;
}
