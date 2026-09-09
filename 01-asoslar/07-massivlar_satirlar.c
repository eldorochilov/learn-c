/*
 * 07 -- MASSIVLAR VA SATRLAR (C-STRING)
 * =======================================
 */

#include <stdio.h>
#include <string.h>   // strlen, strcpy va h.k. uchun

int main(void) {
    // Bir o'lchamli massiv
    printf("=== Massiv ===\n");
    int sonlar[5] = {10, 20, 30, 40, 50};   // hajmi va boshlang'ich qiymatlar

    for (int i = 0; i < 5; i++) {
        printf("sonlar[%d] = %d\n", i, sonlar[i]);
    }

    // Massiv indeksi 0 dan boshlanadi, oxirgi indeks = hajm - 1
    printf("Birinchi element: %d\n", sonlar[0]);
    printf("Oxirgi element: %d\n", sonlar[4]);   // sonlar[5] XATO -- chegaradan chiqadi!

    // C-string -- aslida char massivi, oxirida \0 (null terminator) bo'ladi
    printf("\n=== C-string ===\n");
    char ism[20] = "Eldor";   // "Eldor\0" -- avtomatik \0 qo'shiladi

    printf("Ism: %s\n", ism);
    printf("Uzunligi: %zu\n", strlen(ism));   // \0 hisobga olinmaydi

    // Satrni nusxalash -- oddiy `=` bilan bo'lmaydi, funksiya kerak
    char yangi_ism[20];
    strcpy(yangi_ism, ism);
    printf("Nusxa: %s\n", yangi_ism);

    // Satrlarni solishtirish -- == emas, strcmp kerak
    if (strcmp(ism, "Eldor") == 0) {
        printf("Ismlar bir xil\n");
    }

    return 0;
}

/*
 * ESLATMA:
 *   - Massiv chegarasidan chiqib ketish (out-of-bounds) C da COMPILE TIME
 *     da tekshirilmaydi -- bu "undefined behavior" va xavfsizlik zaifligi
 *     (buffer overflow) manbai. Binary exploitation shu joydan boshlanadi.
 *   - C-stringlar har doim \0 bilan tugashi kerak, aks holda strlen,
 *     printf("%s") kabi funksiyalar xotira bo'ylab "adashib ketadi".
 */

