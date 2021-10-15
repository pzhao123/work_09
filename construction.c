#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct price {
    char *name;
    int original;
    int discount;
};

void print_price(struct price *p) {
    printf("A %s with a %d%% discount at a base price of $%d is $%0.2f.\n", p->name, p->discount, p->original, (p->original - (p->original * (p->discount * .01))));
}

struct price * make_price(char *n, int o, int d) {
    struct price *p = malloc(sizeof(struct price));
    p->name = n;
    p->original = o;
    p->discount = d;
    return p;
}

int main() {
    srand(time(NULL));
    char name[] = "basketball";
    int original = 30;
    int discount = rand() % 100;

    struct price *item = make_price(name, original, discount);
    print_price(item);
    free(item);

    return 0;
}