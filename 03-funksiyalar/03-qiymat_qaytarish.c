/* ============================================================================
 *  03_qiymat_qaytarish.c
 *  MAVZU: Qiymat qaytaruvchi funksiya ("return" operatorining ishlashi)
 * ==========================================================================*/

#include <stdio.h>
/* printf() uchun kerakli prototiplarni oladi. */

int kvadrat(int son);
/* Prototip: "kvadrat" funksiyasi bitta "int" parametr oladi va natijada
 * "int" turidagi qiymat qaytaradi. Qaytish turi funksiya nomidan CHAPDA
 * yoziladi — bu compiler'ga "chaqiruvchi tomon bu funksiyadan qanday
 * turdagi javob kutishi kerak" degan ma'lumotni beradi. */

int max_topish(int a, int b);
/* Ikkita parametrli, "int" qaytaruvchi yana bir funksiya prototipi —
 * ikki sondan kattasini topib beradi. */

int main(void)
{
    int son = 7;
    /* "son" nomli lokal o'zgaruvchi yaratildi va unga 7 qiymati
     * berildi. Bu o'zgaruvchi faqat main() ICHIDA yashaydi. */

    int natija = kvadrat(son);
    /* MUHIM QATOR: "kvadrat(son)" chaqirilganda:
     *   1) "son" ning QIYMATI (ya'ni 7) funksiyaga nusxa sifatida
     *      uzatiladi (buni keyingi darsda — pass by value — chuqurroq
     *      ko'ramiz),
     *   2) funksiya ichida shu qiymat asosida hisob-kitob bajariladi,
     *   3) "return" orqali natija chaqirilgan joyga QAYTARILADI,
     *   4) o'sha qaytgan qiymat "=" belgisi orqali "natija" nomli YANGI
     *      o'zgaruvchiga YOZIB OLINADI.
     * Demak, funksiya chaqiruvi — bu aslida bitta IFODA (expression) bo'lib,
     * u o'zining "qiymatiga" ega, xuddi "3 + 4" ifodasi 7 ga teng
     * bo'lgani kabi. */

    printf("%d ning kvadrati = %d\n", son, natija);
    /* Ikkita "%d" bor — birinchisi "son" o'rniga, ikkinchisi "natija"
     * o'rniga qo'yiladi, argumentlar tartibi mos kelishi SHART. */

    int katta = max_topish(15, 42);
    /* Qaytgan qiymat to'g'ridan-to'g'ri "katta" o'zgaruvchisiga
     * yozilyapti — funksiya chaqiruvini biror oraliq o'zgaruvchisiz ham
     * ishlatish mumkin, masalan: printf("%d", max_topish(15, 42)); */
    printf("15 va 42 dan kattasi: %d\n", katta);

    return 0;
}


int kvadrat(int son)
/* Ta'rif. Parametr nomi bu yerda ham "son" — bu ATAYLAB shunday
 * qilingan, chunki bu FUNKSIYA ICHIDAGI "son" main() ICHIDAGI "son"
 * bilan HECH QANDAY bog'liqligi yo'q — ular butunlay boshqa-boshqa
 * xotira joylarida yashaydigan, faqat NOMI bir xil bo'lgan lokal
 * o'zgaruvchilar. */
{
    int natija = son * son;
    /* Funksiya ICHIDA yana bir lokal o'zgaruvchi — "natija". Bu ham
     * faqat shu funksiya ishlab turgan payt mavjud bo'ladi, funksiya
     * tugashi bilan yo'qoladi (stekdan olib tashlanadi). */

    return natija;
    /* "return natija;" — funksiya ishini shu yerda TO'XTATADI (pastda
     * yana kod bo'lsa ham, u bajarilmaydi) va "natija" ichidagi
     * qiymatni chaqiruvchi tomonga uzatadi. ARM64 darajasida bu qiymat
     * odatda x0 registriga joylanadi. */
}


int max_topish(int a, int b)
{
    if (a > b) {
        /* Shart tekshirilyapti: agar "a" "b"dan katta bo'lsa... */
        return a;
        /* ...unda darhol "a" qaytariladi va funksiya shu yerda TUGAYDI —
         * pastdagi "return b;" qatoriga ENDI YETIB BORILMAYDI. */
    }
    return b;
    /* Agar yuqoridagi "if" sharti YOLG'ON bo'lsa (ya'ni a <= b),
     * dastur shu qatorga tushadi va "b" qaytariladi.
     * Bitta funksiyada BIRDAN ORTIQ "return" bo'lishi mumkin — muhimi,
     * har bir mumkin bo'lgan yo'l (path) oxir-oqibat biror qiymat
     * qaytarishi kerak. */
}
/*
 * XULOSA:
 *   - Funksiya chaqiruvi o'zi ham bir "ifoda" — natijasi bor.
 *   - "return" — ham qiymatni qaytaradi, HAM funksiya ishini to'xtatadi.
 *   - Bitta funksiyada bir nechta "return" bo'lishi mumkin (turli
 *     shartlar uchun turli natija), lekin HAR BIR yo'l qandaydir
 *     qiymat bilan tugashi SHART (aks holda "undefined behavior").
 */

