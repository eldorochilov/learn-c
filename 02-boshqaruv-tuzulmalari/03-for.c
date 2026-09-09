/*
 * 03 -- for SIKLI -- CHUQUR
 * ===========================
 */

#include <stdio.h>

int main(void) {
    // Standart for -- init; shart; increment
    printf("=== Standart for ===\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Teskari for -- kamayish bilan
    printf("\n=== Teskari for ===\n");
    for (int i = 5; i > 0; i--) {
        printf("%d ", i);
    }
    printf("\n");

    // Qadam (step) bilan for -- har 2 qadamda bittadan
    printf("\n=== Qadam bilan for ===\n");
    for (int i = 0; i <= 10; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    // Bir nechta o'zgaruvchi bir for ichida (vergul bilan)
    printf("\n=== Ikkita o'zgaruvchi bilan for ===\n");
    for (int i = 0, j = 10; i < j; i++, j--) {
        printf("(%d,%d) ", i, j);
    }
    printf("\n");

    // Nested for -- ko'p qatorli chiqish, masalan uchburchak shakl
    printf("\n=== Nested for (uchburchak) ===\n");
    for (int qator = 1; qator <= 5; qator++) {
        for (int ustun = 0; ustun < qator; ustun++) {
            printf("* ");
        }
        printf("\n");
    }

    // for ning har bir qismini bo'sh qoldirish mumkin (lekin ehtiyot bo'lish kerak)
    printf("\n=== Bo'sh qismlar bilan for ===\n");
    int i = 0;
    for (; i < 3; ) {     // init va increment tashqarida boshqarilmoqda
        printf("%d ", i);
        i++;
    }
    printf("\n");

    return 0;
}

/*
 * ESLATMA:
 *   - for(;;) -- shartsiz cheksiz sikl (while(1) bilan bir xil natija).
 *   - for ichida e'lon qilingan o'zgaruvchi (`int i`) faqat shu sikl
 *     doirasida (block scope) yashaydi -- sikldan tashqarida ko'rinmaydi.
 *   - Nested for'larda tashqi va ichki sikl o'zgaruvchilarini har doim
 *     har xil nom bilan yozing (i, j, k...) -- aks holda chalkashadi.
 */

