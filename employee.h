#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#define EMPLOYEE_MIN_SPEED 50
#define EMPLOYEE_MAX_SPEED 100

#define EMPLOYEE_MIN_ACCURACY 80
#define EMPLOYEE_MAX_ACCURACY 100

typedef struct {
    char valid;
    char name[256];
    int speed;    /* how fast do they complete things 50-100 */
    int accuracy; /* how good is what they complete 50-100 */
} employee_t;

void employee_create(employee_t *e);
void employee_print();

#endif /* _EMPLOYEE_H_ */
