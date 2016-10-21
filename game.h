#ifndef _GAME_H_
#define _GAME_H_

typedef struct {
    char *name;
    int features;
    int bugs;
} product_t;

typedef struct {
    char valid;
    char *name;
    int speed;    /* how fast do they complete things */
    int accuracy; /* how good is what they complete */
} employee_t;

#define MAX_EMPLOYEES 32

typedef struct {
    product_t product;
    employee_t employees[MAX_EMPLOYEES];
} game_t;

extern game_t game;

void init_game();
void print_game();

#endif /* _GAME_H_ */
