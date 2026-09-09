/*
 * 02 -- switch-case -- CHUQUR
 * =============================
 */

#include <stdio.h>

int main(void) {
    // Oddiy switch
    printf("=== Oddiy switch ===\n");
    int kun = 3;
    switch (kun) {
        case 1:
            printf("Dushanba\n");
            break;
        case 2:
            printf("Seshanba\n");
            break;
        case 3:
            printf("Chorshanba\n");
            break;
        default:
            printf("Noma'lum\n");
    }

    // FALL-THROUGH -- break yozilmasa, keyingi case ham bajariladi
    printf("\n=== Fall-through (break bo'lmaganda) ===\n");
    int oy = 4;
    switch (oy) {
        case 12:
        case 1:
        case 2:
            printf("Qish\n");
            break;
        case 3:
        case 4:
        case 5:
            printf("Bahor\n");   // oy=4 shu yerga tushadi
            break;               // break bo'lmasa, "Yoz" ham chop etilardi
        case 6:
        case 7:
        case 8:
            printf("Yoz\n");
            break;
        default:
            printf("Kuz\n");
    }

    // Bir nechta case'ni birlashtirish (yuqoridagi misolda ko'rsatilgan) --
    // case 12: case 1: case 2: -- bularning barchasi bitta natijaga olib keladi

    // char bilan switch
    printf("\n=== switch char bilan ===\n");
    char daraja = 'B';
    switch (daraja) {
        case 'A':
            printf("A'lo\n");
            break;
        case 'B':
            printf("Yaxshi\n");
            break;
        case 'C':
            printf("Qoniqarli\n");
            break;
        default:
            printf("Noma'lum daraja\n");
    }

    return 0;
}

/*
 * ESLATMA:
 *   - switch faqat BUTUN son (int, char, enum) bilan ishlaydi -- float yoki
 *     string bilan ISHLATIB BO'LMAYDI (aks holda compile error).
 *   - `break` unutish -- eng ko'p uchraydigan switch xatosi (silent bug,
 *     kompilyator odatda faqat warning beradi).
 *   - `default` har doim yozilishi tavsiya etiladi, hatto oxirida
 *     bo'lmasa ham -- kutilmagan qiymatlarni ushlab qolish uchun.
 */

