#ifndef _MENU_H_
#define _MENU_H_

typedef void (*menu_cb_t)();
typedef struct {
    char *label;
    menu_cb_t cb;
} menu_entry_t;

void do_menu(menu_entry_t *entries, int num_entries);
void print_title(char *title);

#endif /* _MENU_H_ */
