#import <stdio.h>

void menu() {
    printf("1) Employees");
    printf("2) Product Status");
    printf("3) Quit");
}

void menu_employees() {
    // list employees
    printf("1) Examine\n");
    printf("2) Hire\n");
    printf("3) First\n");
    printf("4) Back\n");


}

int menu_input(char *options[], int num_options) {
    int c;
    do {
        int i;
        for (i = 0; i < num_options; i++) {
            printf("%d) %s\n", i+1, options[i]);
        }

        printf("\nEnter %d-%d: ", 1, num_options);
        c = getchar() - '0';
    } while (c < 0 || c > num_options);

    return c-1;
}


int main() {
    printf("Welcome to the Micromanager simulator");
    printf("You have been chosen as the manager for a failing business unit.\nPlease save the company!\n\n");

    enum {
        MAIN_OPTION_PRODUCT,
        MAIN_OPTION_EMPLOYEE,
        MAIN_OPTION_QUIT,
        MAIN_OPTION_NUM,
    };

    char *main_options[] = {"Product Status", "Employees", "Quit"};

    while (1) {
        int option = menu_input(main_options, MAIN_OPTION_NUM);
        if (option == MAIN_OPTION_QUIT) {
            break;
        }
    }

    printf("Bye!\n");

	return 0;
}
