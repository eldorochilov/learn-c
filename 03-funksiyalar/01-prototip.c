/* ============================================================================
 *  01_prototip.c
 *  MAVZU: Funksiya PROTOTIPI (deklaratsiya) va TA'RIF (definitsiya) farqi
 * ==========================================================================*/

#include <stdio.h>
/* Yuqoridagi qator — preprocessor direktivasi. Kompilyatsiyadan OLDIN
 * "stdio.h" nomli sarlavha (header) faylining butun matnini shu yerga
 * "joylab qo'yadi". Bizga bu fayl printf() funksiyasining PROTOTIPINI
 * berish uchun kerak — ya'ni printf ham aslida shu qoidaga bo'ysunadi. */

void salomlash(void);
/* Bu — FUNKSIYA PROTOTIPI (yoki "forward declaration" ham deyiladi).
 * Diqqat: qator oxirida { } (tana) yo'q, faqat ";" bilan tugaydi.
 * Bu compiler'ga uchta narsani "va'da" qiladi:
 *   1) "salomlash" nomli funksiya albatta mavjud bo'ladi (quyida yoki
 *      boshqa faylda),
 *   2) u hech qanday parametr qabul qilmaydi ("void" — bo'sh degani),
 *   3) u hech qanday qiymat qaytarmaydi ("void" qaytish turi).
 * Prototip main()dan OLDIN yozilgani uchun, main() ichida bu funksiyani
 * hali "tanasi" ko'rinmasa ham xotirjam chaqirish mumkin bo'ladi. */

int kvadratini_hisobla(int son);
/* Yana bir prototip. Bu safar funksiya "int son" nomli bitta butun sonni
 * parametr sifatida oladi va natijada "int" turidagi qiymat qaytaradi
 * degan "shartnoma" tuzilyapti. Compiler main() ichida bu funksiya qanday
 * chaqirilishi kerakligini (necha argument, qaysi tur) shu qatordan bilib
 * oladi — hali funksiyaning ICHKI mantig'ini ko'rmasa ham. */

int main(void)
/* main() — dasturning bosh nuqtasi. Operatsion tizim dasturni ishga
 * tushirganda, aynan shu funksiya birinchi chaqiriladi.
 * "(void)" — main hech qanday parametr olmasligini bildiradi (bu yerda
 * argc/argv ishlatilmayapti). "int" — dastur tugaganda operatsion tizimga
 * bir sonli "chiqish kodi" (exit code) qaytarishini bildiradi. */
{
    /* Quyidagi qatorda "salomlash" funksiyasi CHAQIRILYAPTI.
     * Compiler bu joyga kelganda faylning pastida yozilgan haqiqiy
     * "tana"ni hali ko'rmagan bo'lsa ham — xato bermaydi, chunki yuqorida
     * berilgan PROTOTIP orqali bu funksiya haqida yetarli ma'lumotga
     * ega bo'lib ulgurgan. */
    salomlash();

    /* Bu yerda "kvadratini_hisobla" funksiyasi 5 soni bilan chaqirilyapti,
     * natija esa "int" turidagi "natija" nomli yangi o'zgaruvchiga
     * yozib olinyapti ("=" — tayinlash operatori). */
    int natija = kvadratini_hisobla(5);

    /* printf — ekranga formatlangan matn chiqaruvchi funksiya.
     * "%d" — o'rniga keyingi argument (bu yerda "natija") butun son
     * sifatida qo'yiladi. "\n" — qatorni yangi qatorga o'tkazadi. */
    printf("5 ning kvadrati: %d\n", natija);

    /* main() funksiyasi 0 qiymatini qaytaryapti — bu Unix/Linux
     * dunyosida "dastur muvaffaqiyatli tugadi" degan universal
     * kelishuv (convention) hisoblanadi. */
    return 0;
}
/* main() funksiyasining tanasi shu yerda "}" bilan yopilyapti. */


void salomlash(void)
/* Bu yerda esa "salomlash" funksiyasining HAQIQIY TA'RIFI (definitsiyasi)
 * boshlanyapti — ya'ni funksiya nima QILISHI kerakligining o'zi.
 * Qaytish turi ("void") va parametrlar ("void") yuqoridagi prototip bilan
 * SO'ZMA-SO'Z bir xil bo'lishi SHART — aks holda compiler xato beradi. */
{
    printf("Salom! Prototip va definitsiya farqini o'rganyapmiz.\n");
    /* Funksiya tanasi — bajariladigan haqiqiy amal shu yerda. */
}
/* Funksiya tanasi shu "}" bilan yopiladi. */


int kvadratini_hisobla(int son)
/* "kvadratini_hisobla" funksiyasining haqiqiy ta'rifi. Parametr nomi
 * bu yerda "son" deb ko'rsatilgan — bu nom faqat funksiya ICHIDA
 * ishlatiladi, tashqaridan ko'rinmaydi (lokal o'zgaruvchi kabi). */
{
    return son * son;
    /* "return" — funksiya ishini shu yerda to'xtatadi va "son * son"
     * ifodasining natijasini chaqiruvchi tomonga (bu yerda main()
     * ichidagi "natija" o'zgaruvchisiga) uzatadi. */
}
/* Funksiya ta'rifi shu yerda tugaydi.
 *
 * XULOSA:
 *   - Prototip = "shartnoma e'loni" (faylning boshida, ";" bilan tugaydi)
 *   - Definitsiya = "haqiqiy bajarilish" (faylning istalgan joyida,
 *     { } — tana bilan)
 *   - Katta loyihalarda prototiplar odatda ALOHIDA ".h" (header) faylga
 *     yozib qo'yiladi, shunda bir nechta ".c" fayllar bir xil funksiyani
 *     bemalol chaqira oladi. Buni keyingi darslarda ko'ramiz.
 */

