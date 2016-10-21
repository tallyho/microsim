#import "game.h"

game_t game;

void init_game() {
    // create product
    game.product.name = "SUPER CLOUD MACHINE v6";
    game.product.features = 100;
    game.product.bugs = 0;
}

void print_game() {
    product_t *product = &game.product;
    printf("Name:%s\n", product->name);
    printf("Features Remaining:%d\n", product->features);
    printf("Bugs Remaining:%d\n", product->bugs);
}
