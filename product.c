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

#include "product.h"
#include "game.h"

static void product_create_name(char *buf);

void product_init(product_t *product) {
    product_create_name(product->name);
    product->features = 100;
    product->bugs = 0;
}

static void product_create_name(char *buf) {
    char *adj[] = {
        "Super",
        "Sentient",
        "Cloud",
        "Extreme",
        "Mobile-Centric",
    };
    int num_adjs = 5;

    char *noun[] = {
        "Computer",
        "Framework",
        "Marketplace",
        "Enabler",
        "Chip",
    };
    int num_nouns = 5;

    char *version[] = {
        "V4",
        "900",
        "1.2",
        "0.0.1",
        "Beta",
    };
    int num_versions = 5;

    buf[0] = 0;
    strcat(buf, adj[random() % num_adjs]);
    strcat(buf, " ");
    strcat(buf, noun[random() % num_nouns]);
    strcat(buf, " ");
    strcat(buf, version[random() % num_versions]);
}


void product_print(product_t *product) {
    printf("Name:%s\n", product->name);
    printf("Features Remaining:%d\n", product->features);
    printf("Bugs Remaining:%d\n", product->bugs);
}
