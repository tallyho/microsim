#include "product.h"
#include "employee.h"

#ifndef _GAME_H_
#define _GAME_H_

#define GAME_EMPLOYEES_MAX 32
#define GAME_EMPLOYEES_START_MIN 2
#define GAME_EMPLOYEES_START_MAX 5

typedef struct {
    product_t product;
    employee_t employees[GAME_EMPLOYEES_MAX];
} game_t;

extern game_t game;

void game_init();
void game_print();
void game_print_employees();

#endif /* _GAME_H_ */
