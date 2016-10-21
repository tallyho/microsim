#ifndef _PRODUCT_H_
#define _PRODUCT_H_

typedef struct {
    char *name;
    int features;
    int bugs;
} product_t;

void product_init(product_t *product);
void product_print(product_t *product);

#endif /* _PRODUCT_H_ */
