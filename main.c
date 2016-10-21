#import <stdio.h>

void show_main();

typedef struct {
    char *name;
    int age;

    int speed;    /* how fast do they complete things */
    int accuracy; /* how good is what they complete */
} employee_t;

typedef void (*menu_cb_t)();
typedef struct {
    char *label;
    menu_cb_t cb;
} menu_entry_t;

void do_menu(menu_entry_t *entries, int num_entries) {
    int c;
    do {
        int i;
        for (i = 0; i < num_entries; i++) {
            printf("%d) %s\n", i+1, entries[i].label);
        }

        printf("\nEnter %d-%d: ", 1, num_entries);

        if (scanf("%d", &c) == -1) {
            continue;
        }
        c--;
    } while (c < 0 || c >= num_entries);

    printf("\n"); //clean up

    menu_cb_t cb = entries[c].cb;
    if (cb) {
        cb();
    }
}

void print_title(char *title) {
    printf("------%s------\n", title);
}

void show_product() {
    print_title("PRODUCT STATUS");

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

    show_main();
    printf("Bye!\n");

	return 0;
}
