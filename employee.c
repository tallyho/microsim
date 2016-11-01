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
static void employee_action_feature_complete(employee_t *e);
static void employee_action_bug_complete(employee_t *e);

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

    printf("Name: %s\r\n", e->name);
    printf("Speed: %d\r\n", e->speed);
    printf("Accuracy: %d\r\n", e->accuracy);
    printf("Action: %s %d/%d\r\n", employee_action2str(e->action.type), e->action.steps.completed, e->action.steps.total);
}

static char *employee_action2str(employee_action_t action) {
    switch (action) {
    case EMPLOYEE_ACTION_IDLE:
        return "Idle";
    case EMPLOYEE_ACTION_FEATURE:
        return "Feature";
    case EMPLOYEE_ACTION_BUG:
        return "Bug";
    default:
        return "Unknown";
    }
}

void employee_start_action(employee_t *e, employee_action_t type) {
    // stop working on last action
    if (e->action.active) {
        switch(e->action.type) {
        case EMPLOYEE_ACTION_FEATURE:
            game.product.features.active--;
            activity_log("%s stopped developing features\n", e->name);
            break;
        case EMPLOYEE_ACTION_BUG:
            game.product.bugs.active--;
            activity_log("%s stopped fixing bugs\n", e->name);
            break;
        case EMPLOYEE_ACTION_IDLE:
            break;
        default:
            activity_log("%s stopped at %d/%d\r\n", e->name, employee_action2str(e->action.type), e->action.steps.completed, e->action.steps.total); 
            break;
        }
    }

    e->action.active = 1;
    e->action.type = type;
    e->action.steps.completed = 0;

    // start new action
    switch(type) {
    case EMPLOYEE_ACTION_IDLE:
        activity_log("%s is twiddling their thumbs\n", e->name);
        break;
    case EMPLOYEE_ACTION_FEATURE:
        e->action.steps.total = EMPLOYEE_ACTION_FEATURE_STEPS;
        game.product.features.active++;
        activity_log("%s started developing features\n", e->name);
        break;
    case EMPLOYEE_ACTION_BUG:
        e->action.steps.total = EMPLOYEE_ACTION_BUG_STEPS;
        game.product.bugs.active++;
        activity_log("%s started fixing bugs\n", e->name);
        break;
    default:
        activity_log("%s started (%d)\r\n", e->name, employee_action2str(e->action.type), e->action.steps.total); 
        break;
    }
}

void employee_step(employee_t *e) {
    if (e->action.type != EMPLOYEE_ACTION_IDLE) {
        if (e->action.steps.completed++ == e->action.steps.total) {
            e->action.active = 0;

            switch(e->action.type) {
            case EMPLOYEE_ACTION_FEATURE:
                employee_action_feature_complete(e);
                break;
            case EMPLOYEE_ACTION_BUG:
                employee_action_bug_complete(e);
                break;
            default:
                break;
            }
            employee_start_action(e, EMPLOYEE_ACTION_IDLE);
        }
    }
}

static void employee_action_feature_complete(employee_t *e) {
    int bug_chance;

    /* chance they create a bug instead! */
    /* 25% base chance */
    bug_chance = random() % 1000 * e->accuracy / 100;
    if (bug_chance < 250) {
        activity_log("%s created a bug!\r\n", e->name);
        game.product.bugs.total++;
    } else {
        activity_log("%s completed a feature!\r\n", e->name);
        game.product.features.completed++;
        game.product.features.active--;
    }
}

static void employee_action_bug_complete(employee_t *e) {
    int bug_chance;

    /* chance they create a bug instead! */
    /* 25% base chance */
    bug_chance = random() % 1000 * e->accuracy / 100;
    game.product.bugs.active--;
    if (bug_chance < 250) {
        activity_log("%s failed to fix bug!\r\n", e->name);
    } else {
        activity_log("%s fixed a bug!\r\n", e->name);
        game.product.bugs.completed++;
    }
}
