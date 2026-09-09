/* ============================================================================
 *  05_havola_buyicha_uzatish.c
 *  MAVZU: Pointer orqali "pass by reference" simulyatsiyasi (swap misoli)
 * ==========================================================================*/

#include <stdio.h>

void ikkitasini_almashtir(int *a, int *b);
/* Prototipga diqqat: parametrlar "int a, int b" emas, balki
 * "int *a, int *b" — ya'ni "a" va "b" endi son EMAS, balki
 * "int turidagi qiymat yotgan xotira manziliga ishora qiluvchi
 * POINTER"lardir. "*" belgisi shu yerda "bu pointer" degan ma'noni
 * bildiradi (e'londa), pastda esa "*a" boshqacha — "dereference"
 * ma'nosida ishlatiladi. */

int main(void)
{
    int x = 10;
    int y = 20;
    /* Ikkita oddiy "int" o'zgaruvchi — xotirada ikkita alohida joy
     * egallaydi, masalan x manzili 0x1000da, y esa 0x1004da deylik
     * (aniq manzillar OS/compiler tomonidan belgilanadi). */

    printf("Almashtirishdan OLDIN: x = %d, y = %d\n", x, y);

    ikkitasini_almashtir(&x, &y);
    /* MUHIM QATOR: "&x" — "x ning QIYMATI emas, balki x QAYERDA
     * joylashganini" (ya'ni manzilini) oladi. Xuddi shunday "&y".
     * Demak funksiyaga bu safar SONLAR emas, MANZILLAR uzatilyapti.
     * Funksiya endi shu manzillar orqali to'g'ridan-to'g'ri main()
     * ning O'Z XOTIRASIGA kirib, uni o'zgartira oladi — bu "pass by
     * value"dan tubdan farq qiladi. */

    printf("Almashtirishdan KEYIN:  x = %d, y = %d\n", x, y);
    /* Bu safar natija HAQIQATDA o'zgaradi: x = 20, y = 10 bo'ladi —
     * chunki funksiya asl xotiraga bevosita kirib ishladi. */

    return 0;
}


void ikkitasini_almashtir(int *a, int *b)
/* Bu yerda "a" — "int ga ishora qiluvchi pointer" turidagi lokal
 * o'zgaruvchi. Uning QIYMATI — bu SON EMAS, balki bir MANZIL (masalan,
 * "x" qayerda turganini ko'rsatuvchi raqam, masalan 0x1000).
 * Xuddi shunday "b" — "y" ning manzilini saqlaydi. */
{
    int vaqtinchalik = *a;
    /* "*a" — bu DEREFERENCE operatsiyasi: "a ichidagi manzilga BORIB,
     * O'SHA YERDAGI qiymatni O'QI" degani. Ya'ni "*a" == x ning
     * hozirgi qiymati (10). Bu qiymat "vaqtinchalik" nomli yangi
     * lokal o'zgaruvchiga saqlanadi — buni "vositachi quti" deb
     * tasavvur qiling, aks holda almashtirish paytida bir qiymat
     * yo'qolib qoladi. */

    *a = *b;
    /* Chap tomondagi "*a" — "a ko'rsatib turgan MANZILGA BOR va O'SHA
     * YERGA yozib qo'y" degani (bu — "lvalue" konteksti).
     * O'ng tomondagi "*b" — "b ko'rsatib turgan manzildagi qiymatni
     * O'QI" (bu — "rvalue" konteksti, ya'ni y ning hozirgi qiymati, 20).
     * Natijada: x turgan xotira joyiga 20 yozib qo'yiladi — bu
     * main() dagi "x" o'zgaruvchisining O'ZINI o'zgartiradi! */

    *b = vaqtinchalik;
    /* "b" ko'rsatib turgan manzilga (ya'ni y ning xotirasiga)
     * "vaqtinchalik" ichida saqlab qo'yilgan ESKI x qiymati (10)
     * yozib qo'yiladi. Shu bilan almashtirish (swap) jarayoni
     * to'liq yakunlanadi: x endi 20, y endi 10. */
}
/*
 * XULOSA:
 *   - "&o'zgaruvchi" — o'zgaruvchining MANZILINI oladi (pointer hosil
 *     qiladi).
 *   - "*pointer" — pointer ko'rsatib turgan manzildagi haqiqiy
 *     qiymatga murojaat qiladi (dereference) — u yerdan O'QISH HAM,
 *     O'SHA YERGA YOZISH HAM mumkin.
 *   - C tilida "reference" tushunchasi yo'q, lekin pointerlar orqali
 *     xuddi shunday natijaga erishiladi: funksiya chaqiruvchining
 *     ASL xotirasini o'zgartira oladi.
 *   - Bu usul ayniqsa BIRDAN ORTIQ qiymatni "qaytarish" kerak
 *     bo'lganda muhim, chunki "return" faqat BITTA qiymat qaytara
 *     oladi.
 */

