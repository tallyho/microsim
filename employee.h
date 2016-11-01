/*
 * MicroSim Project
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 LocalAreaGaming
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#define EMPLOYEE_MIN_SPEED 50
#define EMPLOYEE_MAX_SPEED 100

#define EMPLOYEE_MIN_ACCURACY 80
#define EMPLOYEE_MAX_ACCURACY 100

#define EMPLOYEE_ACTION_FEATURE_STEPS GAME_STEPS_PER_SEC*30
#define EMPLOYEE_ACTION_BUG_STEPS GAME_STEPS_PER_SEC*15

typedef enum {
    EMPLOYEE_ACTION_IDLE,
    EMPLOYEE_ACTION_FEATURE,
    EMPLOYEE_ACTION_BUG,
    EMPLOYEE_ACTION_NUM
} employee_action_t;

typedef struct {
    char valid;
    char name[256];
    int speed;    /* how fast do they complete things multiplier around 100 */
    int accuracy; /* how good is what they complete ?? */

    struct {
        char active;
        employee_action_t type;
        struct {
            int total;
            int completed;
        } steps;
    } action;
} employee_t;

void employee_init(employee_t *e);
void employee_print(employee_t *e);
void employee_step(employee_t *e);
void employee_start_action(employee_t *e, employee_action_t type);

#endif /* _EMPLOYEE_H_ */
