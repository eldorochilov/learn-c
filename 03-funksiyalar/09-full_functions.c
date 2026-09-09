/* ============================================================================
 * 03-funksyalar — C tilida funksiyalar (functions) bo'yicha o'quv fayli
 * ----------------------------------------------------------------------------
 * Bu faylda funksiyalarning barcha asosiy jihatlari birma-bir, professional
 * darajada, lekin tushunarli izohlar bilan ko'rsatilgan:
 *
 *   1. Funksiya prototipi (deklaratsiya) va ta'rifi (definitsiya) farqi
 *   2. void funksiya (parametrsiz, qaytarmaydi)
 *   3. Qiymat qaytaruvchi funksiya
 *   4. Parametrli funksiya va "pass by value" (qiymat bo'yicha uzatish)
 *   5. Pointer orqali parametr uzatish — "pass by reference" simulyatsiyasi
 *   6. Rekursiya (o'z-o'zini chaqiruvchi funksiya) va stek chuqurligi
 *   7. static funksiya — fayl ichida ko'rinish doirasini cheklash
 *   8. Funksiya pointerlari (function pointers) — dispatch jadvali
 *
 * ARM64 assembly bilan bog'liqligi haqida eslatma:
 *   Siz assembly'da o'rgangan narsalar — x0-x7 registrlar orqali argument
 *   uzatish, x30 (link register)da qaytish manzili, stek freym (frame)
 *   ochilishi/yopilishi — aynan shu C funksiyalarining "ost qatlami"dir.
 *   Har bir funksiya chaqiruvida compiler xuddi shu narsalarni avtomatik
 *   generatsiya qiladi. Shu sabab har bir funksiya tavsifida shu bog'liqlik
 *   qisqacha eslatib o'tiladi.
 * ==========================================================================*/

#include <stdio.h>

/* ----------------------------------------------------------------------------
 * 1-QISM: FUNKSIYA PROTOTIPLARI (DEKLARATSIYALAR)
 * ----------------------------------------------------------------------------
 * Prototip — bu funksiyaning "shartnomasi": nomi, qaytaradigan turi va
 * parametrlar turlari. Compiler'ga "bu funksiya keyinroq quyida ta'riflanadi,
 * lekin sen uni hozirdan chaqirishing mumkin" deb aytadi.
 *
 * Nega kerak? C tili faylni yuqoridan pastga bir marta o'qiydi. Agar main()
 * funksiyasi boshqa funksiyani o'zidan pastda joylashgan holda chaqirsa,
 * lekin prototip bo'lmasa — compiler xato yoki ogohlantirish beradi, chunki
 * u hali funksiya haqida hech narsa bilmaydi (qanday parametr kutishini,
 * nima qaytarishini).
 * --------------------------------------------------------------------------*/
void salomlash(void);
int kvadrat(int son);
void ikkitasini_almashtir(int *a, int *b);
long faktorial(int n);
static int qoldiqni_hisobla(int a, int b);   /* static — pastda tushuntiriladi */
int qoshish(int a, int b);
int ayirish(int a, int b);
int kopaytirish(int a, int b);

/* ----------------------------------------------------------------------------
 * 2-QISM: VOID FUNKSIYA — PARAMETRSIZ, HECH NARSA QAYTARMAYDI
 * ----------------------------------------------------------------------------
 * "void" qaytish turi sifatida — funksiya hech qanday qiymat qaytarmasligini
 * bildiradi. ARM64 darajasida bu shuni anglatadiki, funksiya x0 registrini
 * "qaytish qiymati" sifatida ishlatmaydi — u faqat "yon ta'sir" (side effect,
 * masalan ekranga chiqarish) uchun chaqiriladi.
 * --------------------------------------------------------------------------*/
void salomlash(void)
{
    printf("Salom! Bu funksiyalar darsining namunasi.\n");
}

/* ----------------------------------------------------------------------------
 * 3-QISM: QIYMAT QAYTARUVCHI FUNKSIYA
 * ----------------------------------------------------------------------------
 * "return" operatori funksiya ishini to'xtatadi va berilgan qiymatni
 * chaqiruvchi (caller) tomonga uzatadi. ABI darajasida bu qiymat odatda
 * x0 registriga joylashtiriladi (agar u 8 baytdan katta yoki struct bo'lmasa).
 * --------------------------------------------------------------------------*/
int kvadrat(int son)
{
    return son * son;   /* natija x0 orqali qaytadi (ARM64 AAPCS64 qoidasi) */
}

/* ----------------------------------------------------------------------------
 * 4-QISM: PASS BY VALUE — "QIYMAT BO'YICHA UZATISH" MANTIQI
 * ----------------------------------------------------------------------------
 * C tilida barcha oddiy parametrlar QIYMATI (nusxasi) uzatiladi, MANZILI emas.
 * Ya'ni funksiya ichida parametrni o'zgartirish — asl o'zgaruvchiga TA'SIR
 * QILMAYDI. Buni pastdagi main() ichida amaliy tarzda ko'rasiz.
 *
 * Nima uchun bu muhim? Chunki har bir chaqiruvda argumentning nusxasi
 * registrga (yoki agar registrlar tugasa — stekka) yoziladi. Asl xotira
 * manzili funksiyaga umuman uzatilmaydi.
 * --------------------------------------------------------------------------*/
static void ozgartirishga_urinish(int son)
{
    son = son + 100;   /* faqat lokal nusxa o'zgaradi, chaqiruvchidagi asl
                           o'zgaruvchiga hech qanday ta'sir yo'q */
}

/* ----------------------------------------------------------------------------
 * 5-QISM: POINTER ORQALI "PASS BY REFERENCE" SIMULYATSIYASI
 * ----------------------------------------------------------------------------
 * C tilida haqiqiy "reference" (C++dagidek) yo'q, lekin xuddi shu natijaga
 * pointer orqali erishiladi: funksiyaga o'zgaruvchining QIYMATI emas,
 * MANZILI (&a, &b) uzatiladi. Funksiya ichida * (dereference) operatori
 * orqali o'sha manzildagi haqiqiy xotiraga borib, qiymatni o'zgartiradi.
 *
 * Klassik misol — ikki o'zgaruvchini almashtirish (swap). Agar pointer
 * ishlatilmasa, bu funksiya matematik jihatdan MUMKIN EMAS, chunki C faqat
 * bitta qiymatni "return" orqali qaytara oladi.
 * --------------------------------------------------------------------------*/
void ikkitasini_almashtir(int *a, int *b)
{
    int vaqtinchalik = *a;  /* *a — 'a' manzilidagi qiymatni o'qiydi */
    *a = *b;                /* 'a' manzilidagi joyga 'b'ning qiymatini yozadi */
    *b = vaqtinchalik;
}

/* ----------------------------------------------------------------------------
 * 6-QISM: REKURSIYA — FUNKSIYANING O'Z-O'ZINI CHAQIRISHI
 * ----------------------------------------------------------------------------
 * Har bir rekursiv chaqiruv o'zining YANGI stek freymini (stack frame)
 * yaratadi: yangi lokal o'zgaruvchilar, yangi qaytish manzili (x30 saqlanadi).
 * "Bazaviy holat" (base case) bo'lmasa, stek cheksiz o'sib, "stack overflow"
 * xatosiga olib keladi — bu ARM64 assembly'da stek pointer (sp) chegaradan
 * chiqib ketishi bilan bir xil muammo.
 *
 * n! = n * (n-1) * (n-2) * ... * 1,  va  0! = 1 (bazaviy holat)
 * --------------------------------------------------------------------------*/
long faktorial(int n)
{
    if (n <= 1) {
        return 1;                     /* bazaviy holat — rekursiya to'xtaydi */
    }
    return (long)n * faktorial(n - 1); /* rekursiv chaqiruv — yangi freym */
}

/* ----------------------------------------------------------------------------
 * 7-QISM: STATIC FUNKSIYA — KO'RINISH DOIRASINI FAYL ICHIGA CHEKLASH
 * ----------------------------------------------------------------------------
 * Oddiy funksiya "global linkage"ga ega — u boshqa .c fayllardan ham
 * ko'rinadi (extern orqali). "static" kalit so'zi bilan e'lon qilingan
 * funksiya esa faqat SHU FAYL ICHIDA ko'rinadi ("internal linkage").
 *
 * Bu katta loyihalarda juda muhim: ichki, yordamchi (helper) funksiyalarni
 * boshqa fayllardan "yashiradi", nom to'qnashuvlarining (name collision)
 * oldini oladi va linker uchun ham qulayroq (kamroq belgi — symbol).
 * --------------------------------------------------------------------------*/
static int qoldiqni_hisobla(int a, int b)
{
    return a % b;   /* bu funksiya faqat shu faylda chaqirilishi mumkin */
}

/* ----------------------------------------------------------------------------
 * 8-QISM: FUNKSIYA POINTERLARI — DISPATCH JADVALI (CALCULATOR NAMUNASI)
 * ----------------------------------------------------------------------------
 * C tilida funksiyaning o'zi ham xotirada manzilga ega — demak, unga
 * pointer orqali ishora qilish mumkin. Bu "birinchi darajali funksiya"
 * (first-class function) tushunchasiga yaqin imkoniyat beradi: funksiyalarni
 * massivga joylashtirish, boshqa funksiyaga argument sifatida uzatish va h.k.
 *
 * Quyida oddiy arifmetik amallarni bitta massiv (jadval) orqali chaqiramiz —
 * bu "if/else" yoki "switch" zanjiridan ko'ra tozaroq yechim.
 * --------------------------------------------------------------------------*/
int qoshish(int a, int b)     { return a + b; }
int ayirish(int a, int b)     { return a - b; }
int kopaytirish(int a, int b) { return a * b; }

/* funksiya pointeri turi: "int qaytaradigan, ikkita int oladigan funksiya" */
typedef int (*ArifmetikAmal)(int, int);

/* ----------------------------------------------------------------------------
 * MAIN — barcha yuqoridagi konsepsiyalarni amalda ko'rsatish
 * --------------------------------------------------------------------------*/
int main(void)
{
    /* --- 2-qism: void funksiya --- */
    salomlash();

    /* --- 3-qism: qiymat qaytaruvchi funksiya --- */
    int son = 7;
    printf("\n%d ning kvadrati: %d\n", son, kvadrat(son));

    /* --- 4-qism: pass by value isboti --- */
    int asl_qiymat = 5;
    ozgartirishga_urinish(asl_qiymat);
    printf("\nPass by value: funksiyadan keyin ham qiymat o'zgarmadi -> %d\n",
           asl_qiymat);   /* natija hamon 5 bo'ladi */

    /* --- 5-qism: pointer orqali haqiqiy o'zgartirish --- */
    int x = 10, y = 20;
    printf("\nAlmashtirishdan oldin: x=%d, y=%d\n", x, y);
    ikkitasini_almashtir(&x, &y);   /* manzillar (&) uzatilyapti, qiymat emas */
    printf("Almashtirishdan keyin:  x=%d, y=%d\n", x, y);

    /* --- 6-qism: rekursiya --- */
    int n = 6;
    printf("\n%d! (faktorial) = %ld\n", n, faktorial(n));

    /* --- 7-qism: static funksiya (fayl ichida ishlatish) --- */
    printf("\n17 ni 5 ga bo'lgandagi qoldiq: %d\n", qoldiqni_hisobla(17, 5));

    /* --- 8-qism: funksiya pointerlari va dispatch jadvali --- */
    ArifmetikAmal amallar[3] = { qoshish, ayirish, kopaytirish };
    const char *nomlar[3] = { "qo'shish", "ayirish", "ko'paytirish" };

    printf("\nFunksiya pointerlari orqali kalkulyator:\n");
    for (int i = 0; i < 3; i++) {
        int natija = amallar[i](8, 3);   /* pointer orqali funksiyani chaqirish */
        printf("  8 va 3 uchun %s natijasi: %d\n", nomlar[i], natija);
    }

    return 0;   /* main() operatsion tizimga 0 (muvaffaqiyat) qaytaradi */
}

