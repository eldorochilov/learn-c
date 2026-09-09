#include <stdio.h>

int main(void) {

    int vals[5] = {5, 10, 20, 30, 40};

    printf("vals[0] = %d.\n", vals[0]);
    printf("*vals = %d.\n", *vals);
    printf("*(vals+1) = %d\n", *(vals + 1));

    char name[] = "Eldor! Hello!";
    printf("%c\n", name[0]);

    char *pName = "Eldor! Hello!";
    printf("%c\n", *pName);

    pName = "Hello! World!";
    printf("%s\n", pName);
    return 0;
}
