#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#import "employee.h"

static void employee_create_name(char *buf);

void employee_create(employee_t *e) {
    e->valid = 1;

    employee_create_name(e->name);
    e->speed = EMPLOYEE_MIN_SPEED + rand() % (EMPLOYEE_MAX_SPEED - EMPLOYEE_MIN_SPEED);
    e->accuracy = EMPLOYEE_MIN_ACCURACY + rand() % (EMPLOYEE_MAX_ACCURACY - EMPLOYEE_MIN_ACCURACY);
}

static void employee_create_name(char *buf) {
    char *first[] = {
        "Michael",
        "Christopher",
        "Matthew",
        "Joshua",
        "Daniel",
        "Andrew",
        "James",
        "Justin",
        "Joseph",
        "Ryan",

        "Jessica",
        "Ashley",
        "Brittany",
        "Amanda",
        "Samantha",
        "Sarah",
        "Stephanie",
        "Jennifer",
        "Elizabeth",
        "Lauren",
        "Megan",
    };
    int num_firsts = 21;

    char *last[] = {
        "Irwin",
        "Burris",
        "Ratliff",
        "McCray",
        "Madden",
        "Kaufman",
        "Beach",
        "Goff",
        "Cash",
        "Bolton",
        "McFadden",
        "Levine",
        "Good",
        "Byers",
        "Kirkland",
        "Kidd"   
    };

    int num_lasts = 16;

    buf[0] = 0;
    strcat(buf, first[random() % num_firsts]);
    strcat(buf, " ");
    strcat(buf, last[random() % num_lasts]);
}

void employee_print(employee_t *e) {
    if (e->valid == 0) {
        return;
    }

    printf("Name: %s\n", e->name);
    printf("Speed: %d\n", e->speed);
    printf("Accuracy: %d\n", e->accuracy);
}
