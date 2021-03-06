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
#include <assert.h>
#include <stdarg.h>

#include "activity_log.h"

static FILE *activity_log_file;

void activity_log_init(void) {
    activity_log_file = fopen("activity.log", "a+");
    assert(activity_log_file != NULL);

    activity_log("---------------------------------- NEW GAME ----------------------------------\n");
}

void activity_log(const char *format, ...) {
    assert(activity_log_file != NULL);

    va_list args;
    va_start(args, format);
    vfprintf(activity_log_file, format, args);
    fflush(activity_log_file);
    va_end(args);
}
