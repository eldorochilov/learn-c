#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *user;
    fgets(user, 8, stdin);
    printf("%s\n", user);
    return 0;
}
