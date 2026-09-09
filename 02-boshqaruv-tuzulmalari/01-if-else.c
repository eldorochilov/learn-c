/*
 * 01 -- if / else if / else -- CHUQUR
 * ======================================
 */

#include <stdio.h>

int main(void) {
    int yosh = 20;

    // Oddiy if/else
    printf("=== Oddiy if/else ===\n");
    if (yosh >= 18) {
        printf("Voyaga yetgan\n");
    } else {
        printf("Voyaga yetmagan\n");
    }

    // Zanjirli else if -- yuqoridan pastga, birinchi TRUE bo'lgan shart ishlaydi
    printf("\n=== else if zanjiri ===\n");
    int baho = 75;
    if (baho >= 90) {
        printf("A'lo\n");
    } else if (baho >= 75) {
        printf("Yaxshi\n");        // shu yerda to'xtaydi, pastdagilar tekshirilmaydi
    } else if (baho >= 60) {
        printf("Qoniqarli\n");
    } else {
        printf("Qoniqarsiz\n");
    }

    // Nested if -- if ichida if
    printf("\n=== Nested if ===\n");
    int togri_hujjat = 1;
    int togri_yosh = 1;
    if (togri_hujjat) {
        if (togri_yosh) {
            printf("Kirish ruxsat etildi\n");
        } else {
            printf("Yosh mos kelmadi\n");
        }
    } else {
        printf("Hujjat noto'g'ri\n");
    }
    // Bir xil natijani && bilan ham yozish mumkin (ko'proq tavsiya etiladi):
    if (togri_hujjat && togri_yosh) {
        printf("(&& bilan) Kirish ruxsat etildi\n");
    }

    // Ternary operator -- qisqa if/else o'rnida
    printf("\n=== Ternary operator (? :) ===\n");
    int son = 7;
    // shart ? true_qiymat : false_qiymat
    const char *natija = (son % 2 == 0) ? "juft" : "toq";
    printf("%d soni -- %s\n", son, natija);

    // Ternary ichma-ich ishlatilishi mumkin, lekin o'qilishi qiyinlashadi
    int x = 5;
    printf("belgisi: %s\n", (x > 0) ? "musbat" : (x < 0) ? "manfiy" : "nol");

    return 0;
}

/*
 * ESLATMA:
 *   - else if zanjirida faqat BITTA blok ishlaydi -- birinchi true bo'lgani.
 *   - Ternary operator faqat oddiy, qisqa holatlar uchun; murakkab mantiq
 *     uchun to'liq if/else o'qilishi osonroq bo'ladi.
 *   - `if (a = 5)` -- bu XATO turi (assignment, comparison emas),
 *     har doim true bo'ladi. `if (a == 5)` deb yozing.
 */

