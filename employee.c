#import <stdio.h>

#import "employee.h"

void employee_print(employee_t *employee) {
    if (employee->valid == 0) {
        return;
    }

    printf("Name: %s", employee->name);
    printf("Speed: %d", employee->speed);
    printf("Accuracy: %d", employee->accuracy);
}
