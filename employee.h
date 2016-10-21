#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

typedef struct {
    char valid;
    char *name;
    int speed;    /* how fast do they complete things */
    int accuracy; /* how good is what they complete */
} employee_t;

//void init_employee();
void employee_print();

#endif /* _EMPLOYEE_H_ */
