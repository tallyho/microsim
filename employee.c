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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "employee.h"
#include "activity_log.h"

static void employee_init_name(char *buf);
static char *employee_action2str(employee_action_t action);

void employee_init(employee_t *e) {
    e->valid = 1;

    employee_init_name(e->name);
    e->speed = EMPLOYEE_MIN_SPEED + rand() % (EMPLOYEE_MAX_SPEED - EMPLOYEE_MIN_SPEED);
    e->accuracy = EMPLOYEE_MIN_ACCURACY + rand() % (EMPLOYEE_MAX_ACCURACY - EMPLOYEE_MIN_ACCURACY);
    employee_start_action(e, EMPLOYEE_ACTION_IDLE);
}

static void employee_init_name(char *buf) {
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
    printf("Action: %s\n", employee_action2str(e->action));
}

static char *employee_action2str(employee_action_t action) {
    switch (action) {
    case EMPLOYEE_ACTION_IDLE:
        return "Idle";
    case EMPLOYEE_ACTION_FEATURE:
        return "Feature";
    default:
        return "Unknown";
    }
}

void employee_start_action(employee_t *e, employee_action_t action) {
    // stop working on last action
    switch(e->action) {
    case EMPLOYEE_ACTION_FEATURE:
        activity_log("%s stopped developing features\n", e->name);
        break;
    case EMPLOYEE_ACTION_IDLE:
        break;
    default:
        activity_log("%s stopped %s(%d)\n", e->name, employee_action2str(action), action); 
        break;
    }

    e->action = action;

    // start new action
    switch(action) {
    case EMPLOYEE_ACTION_IDLE:
        e->action_steps_left = 0;
        activity_log("%s is twiddling their thumbs\n", e->name);
        break;
    case EMPLOYEE_ACTION_FEATURE:
        e->action_steps_left = GAME_STEPS_PER_SEC*30;
        activity_log("%s started developing features\n", e->name);
        break;
    default:
        activity_log("%s started %s(%d)\n", e->name, employee_action2str(action), action); 
        break;
    }
}

void employee_step(employee_t *e) {
}
