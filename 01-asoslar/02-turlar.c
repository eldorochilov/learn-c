/*
 * 02 -- MA'LUMOT TURLARI VA O'ZGARUVCHILAR
 * =========================================
 */

#include <stdio.h>

int main(void) {
    // Butun sonlar
    int      son      = 42;              // odatiy butun son (4 bayt, platformaga bog'liq)
    short    kichik    = 10;              // kichikroq diapazon (2 bayt)
    long     katta     = 100000L;         // kattaroq diapazon (4 yoki 8 bayt)
    long long juda_katta = 10000000000LL; // eng katta diapazon (kamida 8 bayt)

    // signed vs unsigned -- manfiy son bo'lish-bo'lmasligi
    unsigned int manfiy_bolmaydi = 5;     // faqat 0 va musbat sonlar

    // Kasr sonlar
    float  f = 3.14f;      // 4 bayt, aniqlik kamroq
    double d = 3.14159265; // 8 bayt, aniqlik yuqoriroq (default tanlov shu bo'lishi kerak)

    // Belgi (character)
    char harf = 'A';       // 1 bayt, aslida kichik butun son (ASCII kod)

    // sizeof -- turning xotirada qancha joy egallashini ko'rsatadi
    printf("int  hajmi: %zu bayt\n", sizeof(int));
    printf("char hajmi: %zu bayt\n", sizeof(char));
    printf("double hajmi: %zu bayt\n", sizeof(double));

    printf("\nson=%d kichik=%d katta=%ld\n", son, kichik, katta);
    printf("f=%.2f d=%.8f harf=%c (kod: %d)\n", f, d, harf, harf);
    printf("unsigned: %u\n", manfiy_bolmaydi);

    return 0;
}

/*
 * ESLATMA:
 *   - Har doim ishlatiladigan qiymatga mos tur tanlang (masalan yosh uchun
 *     `long long` shart emas -- `int` yetarli).
 *   - O'zgaruvchi ishlatishdan oldin initsializatsiya qiling, aks holda
 *     u "axlat" (garbage) qiymat saqlaydi.
 */

