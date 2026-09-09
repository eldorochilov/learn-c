#include <stdio.h>

int main(void) {

    int num = 43;  // 4 byte
    int *p = &num; // num adrees -> p

    printf("num: %d\n", num);
    printf("%d\n", *p);
    printf("Manzil: %p\n", p);
    return 0;
}
