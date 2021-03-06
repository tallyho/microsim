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

#include "util.h"
#include "random.h"
#include "product.h"
#include "game.h"

static void product_create_name(char *buf);

void product_init(product_t *product) {
    product_create_name(product->name);
    product->features.total = 100;
    product->bugs.total = 0;
}

static void product_create_name(char *buf) {
    char *adj[] = {
        "Super",
        "Sentient",
        "Cloud",
        "Extreme",
        "Mobile-Centric",
    };

    char *noun[] = {
        "Computer",
        "Framework",
        "Marketplace",
        "Enabler",
        "Chip",
    };

    char *version[] = {
        "V4",
        "900",
        "1.2",
        "0.0.1",
        "Beta",
    };

    buf[0] = '\0';
    strcat(buf, adj[rand_uint32_max(ARRAY_SIZE(adj))]);
    strcat(buf, " ");
    strcat(buf, noun[rand_uint32_max(ARRAY_SIZE(noun))]);
    strcat(buf, " ");
    strcat(buf, version[rand_uint32_max(ARRAY_SIZE(version))]);
}

void product_print(product_t *product) {
    printf("Name:%s\r\n", product->name);
    printf("Features %d of %d. %d active\r\n", product->features.completed, product->features.total, product->features.active);
    printf("Bugs %d of %d. %d active\r\n", product->bugs.completed, product->bugs.total, product->bugs.active);
}

int product_features_idle_remaining(product_t *product) {
    return product->features.total - product->features.completed - product->features.active;
}

int product_bugs_idle_remaining(product_t *product) {
    return product->bugs.total - product->bugs.completed - product->bugs.active;
}
