#import <stdio.h>
#import <stdlib.h>
#import <string.h>

#import "product.h"
#import "game.h"

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
