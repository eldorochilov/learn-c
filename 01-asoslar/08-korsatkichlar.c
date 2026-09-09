/*
 * 08 -- KO'RSATKICHLAR (POINTER) -- ASOSIY DARAJA
 * ==================================================
 * Bu C tilining eng muhim va past darajadagi kontseptsiyalaridan biri --
 * assembly va binary exploitation shu tushunchaga tayanadi.
 */

#include <stdio.h>

void ikkiga_kopaytir(int *son);   // pointer qabul qiluvchi funksiya prototipi

int main(void) {
    int son = 10;

    // & -- o'zgaruvchining XOTIRADAGI MANZILINI olish
    printf("=== & va * operatorlari ===\n");
    printf("son qiymati: %d\n", son);
    printf("son manzili: %p\n", (void*)&son);

    // Pointer -- boshqa o'zgaruvchining manzilini saqlaydigan o'zgaruvchi
    int *ptr = &son;    // ptr endi son ning manzilini saqlaydi

    printf("ptr o'zi (manzil): %p\n", (void*)ptr);
    printf("*ptr (manzil ko'rsatgan qiymat): %d\n", *ptr);  // * -- dereferencing

    // Pointer orqali qiymatni o'zgartirish
    *ptr = 99;    // son ning o'zi ham o'zgaradi, chunki ptr uni ko'rsatib turibdi
    printf("son o'zgartirilgandan keyin: %d\n", son);

    // Funksiyaga pointer uzatish -- pass by reference simulyatsiyasi
    printf("\n=== Pointer funksiyaga uzatilganda ===\n");
    int x = 5;
    printf("chaqirishdan oldin: %d\n", x);
    ikkiga_kopaytir(&x);     // x ning manzilini uzatamiz
    printf("chaqirishdan keyin: %d\n", x);   // funksiya asl x ni o'zgartira oldi

    // Massiv va pointer aloqasi
    printf("\n=== Massiv va pointer ===\n");
    int massiv[3] = {100, 200, 300};
    int *mptr = massiv;   // massiv nomi -- birinchi elementga pointer bilan teng

    printf("massiv[0] = %d, *mptr = %d\n", massiv[0], *mptr);
    printf("massiv[1] = %d, *(mptr+1) = %d\n", massiv[1], *(mptr + 1));

    return 0;
}

void ikkiga_kopaytir(int *son) {
    *son = *son * 2;   // manzil orqali asl qiymatni o'zgartiramiz
}

/*
 * ESLATMA:
 *   - `&x`   = "x ning manzili qayerda?"
 *   - `*ptr` = "ptr ko'rsatib turgan manzildagi qiymat nima?"
 *   - Pointer initsializatsiya qilinmasa (`int *p;` -- qiymat berilmagan),
 *     u "wild pointer" bo'ladi -- shu joyni dereference qilish CRASH beradi.
 *   - Bu mavzu assembly darajasida x0-x8 registrlar, stack pointer (SP)
 *     tushunchalariga to'g'ridan-to'g'ri bog'lanadi.
 */

