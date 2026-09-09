/* ============================================================================
 *  02_void_funksiya.c
 *  MAVZU: "void" funksiya — parametr olmaydi va qiymat qaytarmaydi
 * ==========================================================================*/

#include <stdio.h>
/* stdio.h — printf() kabi kiritish/chiqarish (input/output) funksiyalarining
 * prototiplarini beradi. Buni har bir faylda alohida yozamiz, chunki har bir
 * ".c" fayli o'zining "#include"lariga muhtoj — ular bir-biridan mustaqil
 * kompilyatsiya qilinadi (bu haqda alohida darsda gaplashamiz). */

void sarlavha_chiqar(void);
/* "void sarlavha_chiqar(void)" — ikkita "void" bor, ikkalasi ham boshqa-
 * boshqa ma'noda:
 *   - Chapdagi "void" = QAYTISH TURI: funksiya hech narsa qaytarmaydi.
 *   - Qavs ichidagi "void" = PARAMETR RO'YXATI: funksiya hech qanday
 *     argument qabul qilmaydi (bo'sh qavs "()" bilan farqi shundaki,
 *     eski C standartida bo'sh qavs "noma'lum parametrlar" degani edi;
 *     shu sabab zamonaviy C'da aniqlik uchun har doim "(void)" yoziladi). */

void sana_korsat(void);
/* Yana bitta void funksiya prototipi — pastda ta'rifini ko'ramiz. */

int main(void)
{
    /* Bu ikki funksiya ham hech qanday qiymat QAYTARMAYDI, shuning uchun
     * ularni "int x = funksiya();" kabi biror o'zgaruvchiga TENGLASHTIRIB
     * BO'LMAYDI — bu compile-xato bo'lar edi. Ular faqat "chaqiriladi",
     * ya'ni ularning ICHIDAGI amal (bu yerda — ekranga chiqarish) uchun
     * ishlatiladi. Bunday funksiyalar odatda "yon ta'sir" (side effect)
     * uchun yoziladi: ekranga chiqarish, faylga yozish, global holatni
     * o'zgartirish va h.k. */
    sarlavha_chiqar();
    sana_korsat();

    /* Diqqat qiling: yuqoridagi ikki qatorda hech qanday "=" belgisi yo'q —
     * chunki qaytadigan narsa yo'q, uni hech narsaga saqlab bo'lmaydi. */

    return 0;
    /* Eslatma: main() o'zi "int" qaytaradi (yuqoridagi ikkita funksiyadan
     * farqli o'laroq), chunki operatsion tizim dastur natijasini bilishi
     * kerak (0 = muvaffaqiyat, boshqa son = xatolik kodi). */
}


void sarlavha_chiqar(void)
/* Funksiya ta'rifi boshlandi. Parametr yo'q — demak funksiya ICHIDA hech
 * qanday "tashqaridan kelgan" ma'lumot bilan ishlamaydi, faqat o'zining
 * doimiy (statik) matnini chiqaradi. */
{
    printf("======================================\n");
    /* Bu qatorda "======...=" belgilaridan iborat chiziq chop etilyapti —
     * odatda dastur natijalarini vizual ajratish uchun ishlatiladi. */
    printf("   VOID FUNKSIYALAR HAQIDA DARS\n");
    printf("======================================\n");
    /* Funksiya faqat ekranga yozib, HECH QANDAY qiymatni tashqariga
     * "qaytarmaydi" — shuning uchun ta'rif ichida "return" qatori
     * umuman yo'q (ixtiyoriy: "return;" — qiymatsiz return yozish
     * mumkin, lekin "void" funksiyada shart emas). */
}
/* Funksiya tanasi shu yerda tugadi — "}" dan keyin dastur avtomatik
 * ravishda chaqirgan joyga (main() ichiga) qaytadi. */


void sana_korsat(void)
{
    /* Bu misolda haqiqiy sanani olish uchun <time.h> kerak bo'lar edi,
     * lekin bu darsimiz FAQAT funksiya tuzilishiga bag'ishlangani uchun,
     * soddalik uchun sana "qattiq yozilgan" (hardcoded) qiymat sifatida
     * ko'rsatilyapti. */
    printf("Bugungi sana namunasi: 2026-09-09\n");
}
/*
 * XULOSA:
 *   - "void" qaytish turi — funksiya natija QAYTARMASLIGINI bildiradi.
 *   - "(void)" parametr ro'yxatida — funksiya HECH QANDAY argument
 *     olmasligini bildiradi.
 *   - Bunday funksiyalar odatda biror ish (chop etish, sozlash,
 *     tozalash) bajarish uchun ishlatiladi, natija esa kerak emas.
 */

