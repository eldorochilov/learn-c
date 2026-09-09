/* ============================================================================
 *  04_qiymat_boyicha_qaytarish.c
 *  MAVZU: "Pass by value" — parametrlar QIYMAT (nusxa) sifatida uzatiladi
 * ==========================================================================*/

#include <stdio.h>

void yuzga_oshirish(int son);
/* Diqqat: funksiya HECH NARSA qaytarmaydi ("void"), lekin parametr
 * sifatida "int" qabul qiladi. Nega bunday funksiya "ma'nosiz" bo'lib
 * ko'rinsa-da, pastda main() ichida uni ATAYLAB shu tarzda yozdik —
 * shu orqali "pass by value" qanday ISHLAMASLIGINI (ya'ni chaqiruvchi
 * o'zgaruvchiga ta'sir qilmasligini) ko'rsatib berish uchun. */

int main(void)
{
    int mening_sonim = 5;
    /* "mening_sonim" — main() ning O'Z lokal o'zgaruvchisi, xotirada
     * ma'lum bir manzilga ega, hozircha qiymati 5. */

    printf("Funksiyani chaqirishdan OLDIN: mening_sonim = %d\n",
           mening_sonim);

    yuzga_oshirish(mening_sonim);
    /* MUHIM: bu yerda "mening_sonim" ning O'ZI emas, balki uning
     * QIYMATINING NUSXASI (ya'ni "5" raqamining o'zi) funksiyaga
     * uzatiladi. Funksiya ichida "son" nomli YANGI, BUTUNLAY MUSTAQIL
     * lokal o'zgaruvchi yaratiladi va unga shu "5" nusxalanadi.
     * ARM64 darajasida: "5" qiymati bitta registrga (masalan w0) yoziladi
     * va funksiya o'sha registrni O'ZINING lokal nusxasi sifatida
     * ishlatadi — main() dagi asl xotira manziliga esa funksiya
     * umuman kira olmaydi. */

    printf("Funksiyani chaqirishdan KEYIN:  mening_sonim = %d\n",
           mening_sonim);
    /* Natija: qiymat HALI HAM 5 — chunki funksiya ichidagi o'zgarish
     * faqat NUSXAGA tegdi, asl o'zgaruvchiga emas. Buni pastda
     * yuzga_oshirish() ta'rifida yana ko'ramiz. */

    return 0;
}


void yuzga_oshirish(int son)
/* Bu yerdagi "son" — main() dagi "mening_sonim" bilan HECH QANDAY
 * XOTIRA BOG'LIQLIGIGA ega emas. Bu — funksiya chaqirilgan payt
 * yaratiladigan, funksiya tugagach yo'q bo'lib ketadigan, TO'LIQ
 * MUSTAQIL lokal o'zgaruvchi. Uning boshlang'ich qiymati chaqiruvchi
 * tomonidan uzatilgan qiymatning NUSXASI (bu holda — 5). */
{
    son = son + 100;
    /* Bu qator FAQAT shu funksiyaning ICHIDAGI lokal "son"ni
     * o'zgartiradi — uni 5 dan 105 ga aylantiradi. LEKIN bu o'zgarish
     * main() dagi "mening_sonim"ga hech qanday tarzda "qaytmaydi",
     * chunki ular ikkita mustaqil xotira joyi. */

    printf("Funksiya ICHIDA:                son = %d\n", son);
    /* Shu yerda "son" = 105 ekanini ko'ramiz — LEKIN bu faqat funksiya
     * ichidagi vaqtinchalik holat. Funksiya tugashi bilan bu "son"
     * o'zgaruvchisi stekdan butunlay o'chib ketadi, natija hech
     * qayerga "qaytarilmaydi" (chunki "return" yo'q va turi "void"). */
}
/*
 * XULOSA:
 *   - C tilida oddiy parametrlar (int, float, char va h.k.) har doim
 *     QIYMAT bo'yicha uzatiladi — funksiya har safar YANGI, mustaqil
 *     nusxa bilan ishlaydi.
 *   - Funksiya ichida parametrni o'zgartirish — chaqiruvchi tarafdagi
 *     ASL o'zgaruvchiga HECH QANDAY ta'sir qilmaydi.
 *   - Agar chaqiruvchidagi o'zgaruvchini haqiqatan ham o'zgartirish
 *     kerak bo'lsa — POINTER kerak bo'ladi (buni keyingi faylda,
 *     05_pass_by_reference.c da ko'ramiz).
 */

