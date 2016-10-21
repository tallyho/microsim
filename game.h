
#import "product.h"
#import "employee.h"

#ifndef _GAME_H_
#define _GAME_H_

#define MAX_EMPLOYEES 32

typedef struct {
    product_t product;
    employee_t employees[MAX_EMPLOYEES];
} game_t;

extern game_t game;

void game_init();
void game_print();
void game_print_employees();

#endif /* _GAME_H_ */
