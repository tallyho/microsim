#import <stdio.h>

#import "product.h"
#import "game.h"

void product_init(product_t *product) {
    product->name = "SUPER CLOUD MACHINE v6";
    product->features = 100;
    product->bugs = 0;
}

void product_print(product_t *product) {
    printf("Name:%s\n", product->name);
    printf("Features Remaining:%d\n", product->features);
    printf("Bugs Remaining:%d\n", product->bugs);
}
