/* ============================================================================
 *  07_static_funksiya.c
 *  MAVZU: "static" funksiya — ko'rinish doirasini FAYL ICHIGA cheklash
 * ==========================================================================*/

#include <stdio.h>

static int qoldiqni_hisobla(int a, int b);
/* Prototipning boshida "static" kalit so'zi qo'shildi. Bu funksiyaning
 * QAYTISH TURI yoki PARAMETRLARIGA hech qanday aloqasi yo'q — bu
 * funksiyaning "LINKAGE" turini (ya'ni boshqa fayllarga ko'rinish-
 * ko'rinmasligini) belgilaydi.
 *
 * Agar bu loyihada YANA bir ".c" fayl bo'lganida (masalan
 * "yordamchi.c"), oddiy (static bo'lmagan) funksiyalarni o'sha fayldan
 * ham "extern" e'lon qilib chaqirish MUMKIN bo'lardi. Lekin "static"
 * bilan belgilangan bu funksiya FAQAT shu "07_static_funksiya.c" fayli
 * ICHIDA ko'rinadi — boshqa hech qanday fayl uni "ko'ra olmaydi" va
 * chaqira olmaydi, xatti bir xil nom bilan e'lon qilinsa ham. */

int narxni_yaxlitlab_chiqar(int narx);
/* Bu esa ODDIY (global linkage'ga ega) funksiya prototipi — "static"
 * so'zi yo'q. Demak bu funksiya boshqa fayllardan ham (agar ular
 * "extern int narxni_yaxlitlab_chiqar(int);" deb e'lon qilsa)
 * chaqirilishi mumkin. Bu funksiya ICHIDA yuqoridagi "static"
 * funksiyadan foydalanadi — buni pastda ko'ramiz. */

int main(void)
{
    int narx = 4570;
    /* Faraz qilaylik, bu — do'kondagi biror mahsulotning narxi. */

    int yaxlitlangan = narxni_yaxlitlab_chiqar(narx);
    /* "narxni_yaxlitlab_chiqar" — GLOBAL (static bo'lmagan) funksiya,
     * shuning uchun uni bemalol main() ichidan chaqiryapmiz. */

    printf("Asl narx: %d, yaxlitlangan narx: %d\n", narx, yaxlitlangan);

    /* Quyidagi qatorni SINAB KO'RING (izohdan chiqarib) — u compile
     * xatosiga OLIB KELMAYDI, chunki biz hozir AYNAN o'sha faylning
     * ICHIDAmiz — "static" funksiya shu fayl ichida to'liq ko'rinadi: */
    int qoldiq = qoldiqni_hisobla(17, 5);
    printf("17 ni 5 ga bo'lgandagi qoldiq (to'g'ridan-to'g'ri chaqirilgan): %d\n",
           qoldiq);

    return 0;
}


static int qoldiqni_hisobla(int a, int b)
/* Ta'rifda ham "static" so'zi TAKRORLANADI — prototip va ta'rifdagi
 * "static" bir xil bo'lishi kerak. Bu — funksiyaning "ICHKI xizmat
 * ko'rsatuvchi" (helper/utility) vazifasini bajarishini bildiradi:
 * u faqat shu faylda ishlatiladigan, "tashqi dunyoga" chiqarilmaydigan
 * yordamchi mantiq. */
{
    return a % b;
    /* "%" — qoldiq (modulo) operatori: "a" ni "b" ga bo'lgandagi
     * qoldiqni beradi. Masalan 17 % 5 = 2 (chunki 17 = 5*3 + 2). */
}
/* Ushbu funksiya BU FAYLDAN TASHQARIDA — masalan agar loyihada
 * "asosiy.c" nomli boshqa fayl bo'lganida — HATTO
 * "extern int qoldiqni_hisobla(int, int);" deb urinib ko'rilsa ham,
 * LINKER xatosi ("undefined reference") berardi, chunki "static"
 * funksiyaning nomi ("symbol") faqat SHU obyekt fayl (.o) ichida
 * mavjud bo'ladi, tashqariga "eksport qilinmaydi". */


int narxni_yaxlitlab_chiqar(int narx)
/* Bu funksiya GLOBAL (static emas) — boshqa fayllardan ham chaqirish
 * mumkin bo'lgan "ochiq" (public) interfeys hisoblanadi. */
{
    int qoldiq = qoldiqni_hisobla(narx, 100);
    /* E'tibor bering: bu funksiya YUQORIDAGI "static" funksiyani
     * O'ZINING ICHIDA, XOTIRJAM ishlatyapti — chunki chaqiruv AYNAN
     * shu fayl ichida sodir bo'lyapti. "static" faqat FAYLDAN
     * TASHQARIGA ko'rinishni cheklaydi, fayl ICHIDA esa hech qanday
     * cheklov yo'q. */

    return narx - qoldiq;
    /* Masalan narx=4570 bo'lsa: 4570 % 100 = 70, natija = 4570-70 = 4500
     * — ya'ni narx eng yaqin yuzlikka "pastga" yaxlitlanadi. */
}
/*
 * XULOSA:
 *   - "static" (funksiya darajasida) — funksiyani FAQAT shu fayl
 *     ichida ko'rinadigan qiladi ("internal linkage").
 *   - Bu katta loyihalarda ICHKI, yordamchi (helper) funksiyalarni
 *     "yashirish" uchun ishlatiladi: tashqi fayllar bilan nom
 *     to'qnashuvi (masalan ikkita faylda ham "qoldiqni_hisobla" nomli
 *     funksiya bo'lsa) OLDINI OLADI.
 *   - "static"siz (ya'ni oddiy) funksiyalar esa "global" — dasturning
 *     boshqa har qanday faylidan (to'g'ri "extern" e'lon bilan)
 *     chaqirilishi mumkin.
 */

