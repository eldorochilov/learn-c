/* ============================================================================
 *  06_rekursiya.c
 *  MAVZU: Rekursiya — funksiyaning o'z-o'zini chaqirishi (faktorial misoli)
 * ==========================================================================*/

#include <stdio.h>

long faktorial(int n);
/* Prototip: "n" — qaysi son uchun faktorial hisoblanayotgani,
 * qaytish turi "long" — chunki faktorial juda tez o'sadi (masalan
 * 13! allaqachon oddiy "int" sig'imidan chiqib ketishi mumkin),
 * shuning uchun kattaroq sig'imli "long" tur tanlangan. */

int main(void)
{
    int n = 6;
    /* Biz 6! (6 faktorial) ni hisoblamoqchimiz: 6! = 6*5*4*3*2*1 = 720 */

    long natija = faktorial(n);
    /* Bitta oddiy chaqiruv — lekin ICHKARIDA nima bo'layotganini
     * pastda batafsil kuzatamiz. */

    printf("%d! = %ld\n", n, natija);
    /* "%ld" — "long" turini chop etish uchun format spetsifikatori
     * (oddiy "%d" bu yerda noto'g'ri bo'lardi, chunki "natija" — long). */

    return 0;
}


long faktorial(int n)
/* MUHIM TUSHUNCHA: bu funksiya o'z ICHIDA yana o'zini — "faktorial"ni —
 * chaqiradi. Bunga "rekursiya" deyiladi. Har bir chaqiruv YANGI, mustaqil
 * "stek freym" (stack frame) hosil qiladi: o'zining "n" qiymati, o'zining
 * qaytish manzili (ARM64'da bu — x30/link register qiymati) bilan. */
{
    /* --- BAZAVIY HOLAT (base case) --- */
    if (n <= 1) {
        /* Bu — rekursiyaning "TO'XTASH SHARTI". Bazaviy holat BO'LMASA,
         * funksiya cheksiz o'z-o'zini chaqiraverib, oxir-oqibat "stack
         * overflow" xatosiga olib keladi (stek xotirasi tugab qoladi —
         * xuddi ARM64 assembly'da "sp" registri chegaradan chiqib
         * ketgani kabi). */
        return 1;
        /* 0! va 1! matematik jihatdan 1 ga teng — shu yerda rekursiya
         * ZANJIRI TO'XTAYDI va qiymatlar "yig'ila boshlaydi" (pastga
         * qarab qaytadi). */
    }

    /* --- REKURSIV HOLAT (recursive case) --- */
    return (long)n * faktorial(n - 1);
    /* Bu qatorda IKKI narsa sodir bo'ladi:
     *   1) "faktorial(n - 1)" — funksiya O'ZINI, lekin BIR KICHIKROQ
     *      argument bilan ("n-1") chaqiradi. Bu chaqiruv TUGAMAGUNCHA,
     *      joriy funksiya "kutib turadi" — uning ICHKI holati (jumladan
     *      "n" qiymati) STEKDA saqlanib turadi.
     *   2) Ichki chaqiruv qandaydir qiymat qaytargach, o'sha qiymat
     *      joriy "n" ga ko'paytiriladi va NATIJA o'z navbatida YUQORIGI
     *      chaqiruvchiga qaytariladi.
     *
     * Vizual tarzda 6! uchun chaqiruvlar zanjiri:
     *   faktorial(6) = 6 * faktorial(5)
     *   faktorial(5) = 5 * faktorial(4)
     *   faktorial(4) = 4 * faktorial(3)
     *   faktorial(3) = 3 * faktorial(2)
     *   faktorial(2) = 2 * faktorial(1)
     *   faktorial(1) = 1                    <-- bazaviy holat, TO'XTAYDI
     *
     * Endi natijalar PASTDAN YUQORIGA "yig'iladi" (bu jarayon "unwind"
     * deyiladi):
     *   faktorial(1) -> 1
     *   faktorial(2) -> 2 * 1  = 2
     *   faktorial(3) -> 3 * 2  = 6
     *   faktorial(4) -> 4 * 6  = 24
     *   faktorial(5) -> 5 * 24 = 120
     *   faktorial(6) -> 6 * 120 = 720   <-- yakuniy javob
     *
     * "(long)n" qismidagi "(long)" — bu "cast" (tur aylantirish):
     * "n" (int) ni ko'paytirishdan OLDIN "long" turiga aylantiryapmiz,
     * shunda ko'paytma katta sonlarda ham to'g'ri hisoblanadi (int
     * sig'imidan "toshib ketish" — overflow — ehtimolini kamaytiradi). */
}
/*
 * XULOSA:
 *   - Rekursiya = funksiyaning o'zini-o'zi (kichikroq masala uchun)
 *     chaqirishi.
 *   - HAR DOIM bazaviy holat (base case) bo'lishi SHART — aks holda
 *     cheksiz chaqiruv va "stack overflow".
 *   - Har bir chaqiruv o'zining alohida stek freymiga ega — bu xotira
 *     jihatidan "bepul emas": chuqur rekursiya ko'p stek xotirasini
 *     yeydi. Shu sababli juda katta "n" uchun rekursiya o'rniga
 *     iterativ (sikl asosidagi) yechim ko'proq tavsiya etiladi.
 */

