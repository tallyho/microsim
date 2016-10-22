#include <stdio.h>

#include "menu.h"

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
