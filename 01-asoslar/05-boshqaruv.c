/*
 * 05 -- BOSHQARUV STRUKTURALARI
 * ==============================
 * (while sikli haqida alohida chuqur fayl mavjud -- bu yerda umumiy ko'rinish)
 */

#include <stdio.h>

int main(void) {
    // if / else if / else
    int baho = 85;
    printf("=== if / else if / else ===\n");
    if (baho >= 90) {
        printf("A\n");
    } else if (baho >= 80) {
        printf("B\n");
    } else if (baho >= 70) {
        printf("C\n");
    } else {
        printf("F\n");
    }

    // switch -- bir nechta aniq qiymatni tekshirish uchun qulay
    printf("\n=== switch ===\n");
    int kun = 3;
    switch (kun) {
        case 1:
            printf("Dushanba\n");
            break;          // break bo'lmasa, keyingi case ham bajariladi (fall-through)
        case 2:
            printf("Seshanba\n");
            break;
        case 3:
            printf("Chorshanba\n");
            break;
        default:
            printf("Noma'lum kun\n");
    }

    // for -- iteratsiya soni oldindan ma'lum bo'lganda
    printf("\n=== for ===\n");
    for (int i = 0; i < 5; i++) {   // init; shart; increment -- bittа qatorda
        printf("%d ", i);
    }
    printf("\n");

    // while -- shart oldindan tekshiriladi (batafsili alohida faylda)
    printf("\n=== while ===\n");
    int j = 0;
    while (j < 5) {
        printf("%d ", j);
        j++;
    }
    printf("\n");

    // do-while -- kamida 1 marta ishlaydi
    printf("\n=== do-while ===\n");
    int k = 0;
    do {
        printf("%d ", k);
        k++;
    } while (k < 5);
    printf("\n");

    return 0;
}

