/*
 * ============================================================
 *  C TILIDA `while` SIKLI — TOʻLIQ PROFESSIONAL QOʻLLANMA
 * ============================================================
 *
 * ISHLASH MANTIGʻI (execution flow):
 *   1. `shart` hisoblanadi.
 *   2. Agar natija 0 (false) boʻlsa -> sikldan darhol chiqiladi,
 *      tana HECH QACHON ishlamaydi.
 *   3. Agar natija 0 dan farqli (true) boʻlsa -> tana bajariladi.
 *   4. Tana tugagach, yana 1-qadamga qaytiladi.
 *   5. Shart false boʻlguncha shu tsikl davom etadi.
 *
 * XULOSA: shart boshidanoq false boʻlsa, while tanasi
 * bir marta ham ishlamaydi (bu do-while dan farqi).
 * ============================================================
 */

#include <stdio.h>

/* ------------------------------------------------------------
 * MUMKIN BOʻLGAN QOIDALAR
 * ------------------------------------------------------------ */

/* 1) Shart har qanday butun songa aylanadigan ifoda boʻlishi mumkin */
void qoida_1_har_qanday_ifoda(void) {
    printf("=== Qoida 1: shart sifatida har qanday integer ifoda ===\n");

    int x = 3;
    while (x) {              // x != 0 boʻlsa true, shu qadar davom etadi
        printf("x = %d\n", x);
        x--;                  // x kamayadi, oxiri 0 bo'lganda shart false bo'ladi
    }
    printf("\n");
}

/* 2) Tana bitta operator boʻlsa qavs shart emas — LEKIN professional
 *    kodda doim { } ishlatish tavsiya etiladi (xavfsizlik uchun) */
void qoida_2_qavssiz_va_qavsli(void) {
    printf("=== Qoida 2: qavssiz (tavsiya etilmaydi) vs qavsli (tavsiya) ===\n");

    int i = 0;
    while (i < 3)
        printf("qavssiz: %d\n", i++);   // faqat shu 1 qator siklga tegishli

    int j = 0;
    while (j < 3) {                     // professional yondashuv: doim { }
        printf("qavsli: %d\n", j);
        j++;
    }
    printf("\n");
}

/* 3) break va continue ishlatish mumkin */
void qoida_3_break_continue(void) {
    printf("=== Qoida 3: break va continue ===\n");

    int i = 0;
    while (1) {                 // cheksiz sikl, lekin nazorat ostida
        i++;
        if (i > 10) break;      // break -- siklni butunlay to'xtatadi
        if (i % 2 == 0) continue; // continue -- shu iteratsiyani tashlab, shartni qayta tekshiradi
        printf("toq son: %d\n", i);
    }
    printf("\n");
}

/* 4) Nested while (sikl ichida sikl) mumkin */
void qoida_4_nested_while(void) {
    printf("=== Qoida 4: sikl ichida sikl ===\n");

    int i = 0;
    while (i < 3) {
        int j = 0;
        while (j < 3) {
            printf("(%d,%d) ", i, j);
            j++;
        }
        i++;
    }
    printf("\n\n");
}

/* 5) Shartni funksiya chaqiruvi orqali boshqarish mumkin
 *    (real loyihalarda eng ko'p ishlatiladigan pattern -- fayl/stream o'qish) */
void qoida_5_funksiya_sharti(void) {
    printf("=== Qoida 5: shart -- funksiya natijasi (demo hisoblagich bilan) ===\n");

    int hisoblagich = 0;
    // Real holatda: while (fgets(buffer, sizeof(buffer), stdin) != NULL) { ... }
    while (hisoblagich++ < 3) {
        printf("chaqiruv %d\n", hisoblagich);
    }
    printf("\n");
}

/* 6) Cheksiz sikl -- lekin chiqish yo'li SHART bo'lishi kerak
 *    (server, o'yin loop, real-time tizimlarda normal yondashuv) */
void qoida_6_cheksiz_sikl_toʻgʻri(void) {
    printf("=== Qoida 6: cheksiz sikl, lekin nazoratli chiqish bilan ===\n");

    int hodisalar = 0;
    while (1) {
        hodisalar++;
        printf("hodisa ishlandi: %d\n", hodisalar);
        if (hodisalar == 3) {
            break;                // chiqish sharti aniq belgilangan
        }
    }
    printf("\n");
}


/* ------------------------------------------------------------
 * MUMKIN BOʻLMAGAN / TAQIQLANGAN HOLATLAR
 * (quyidagilar korrekt kodga izoh sifatida yozilgan --
 *  haqiqiy xato beruvchi qatorlar ataylab kommentga olingan)
 * ------------------------------------------------------------ */

void mumkin_emas_qoidalar(void) {
    printf("=== Mumkin bo'lmagan holatlar (tushuntirish) ===\n");

    /* XATO 1: shartni butunlay olib tashlab bo'lmaydi
     *   while () { ... }   // COMPILE ERROR -- shart majburiy
     * for(;;) kabi bo'sh qoldirishga ruxsat beruvchi sintaksis while'da yo'q.
     */

    /* XATO 2: C tilida shart ichida yangi o'zgaruvchi e'lon qilib bo'lmaydi
     *   while (int i = 0) { ... }   // C da XATO (bu C++ ga xos xususiyat)
     */

    /* XATO 3: hisoblagichni yangilashni unutish -- CHEKSIZ SIKL xatosi
     *   int i = 0;
     *   while (i < 5) {
     *       printf("%d\n", i);
     *       // i++; yozilmagan -- dastur abadiy shu yerda "osilib qoladi"
     *   }
     * Bu -- eng ko'p uchraydigan boshlang'ich xato.
     */

    /* XATO 4: nuqta-vergul bilan siklni "bo'shatib qo'yish" (silent bug)
     *   int i = 0;
     *   while (i < 5);      // DIQQAT: bu yerda ";" -- BO'SH TANA hisoblanadi!
     *   {
     *       printf("%d\n", i);  // bu blok siklga aloqasi yo'q, faqat 1 marta ishlaydi
     *       i++;
     *   }
     * Kompilyator xato bermaydi, lekin mantiq butunlay buziladi.
     * Natija: cheksiz sikl (chunki i hech qachon oshmaydi).
     */

    /* XATO 5: sikl o'zgaruvchisini noto'g'ri qayta ishga tushirish
     *   int i = 0;
     *   while (i < 5) {
     *       printf("%d\n", i);
     *       i++;
     *       i = 0;   // XATO: i doim 0ga qaytadi -- CHEKSIZ SIKL
     *   }
     */

    /* XATO 6: `=` va `==` ni chalkashtirish (eng xavfli xato turlaridan biri)
     *   int flag = 0;
     *   while (flag = 1) {   // XATO: bu TAYINLASH, solishtirish emas!
     *       // flag doim 1ga tayinlanadi, shart doim "true" -- CHEKSIZ SIKL
     *   }
     * To'g'ri yozilishi: while (flag == 1)
     * Kompilyator ko'pincha faqat warning beradi, error emas -- shuning
     * uchun bu xato ishlab chiqarishgacha yetib borishi mumkin.
     */

    /* XATO 7: sikl ichida e'lon qilingan o'zgaruvchini tashqarida ishlatish
     *   while (i < 5) {
     *       int x = i * 2;
     *   }
     *   printf("%d", x);   // XATO: x faqat sikl tanasi ichida yashaydi (block scope)
     */

    printf("(Yuqoridagi xatolar kod ichida izoh sifatida ko'rsatilgan)\n\n");
}


/* ------------------------------------------------------------
 * do-while BILAN FARQI (solishtirish uchun)
 * ------------------------------------------------------------ */
void solishtirish_do_while(void) {
    printf("=== while vs do-while farqi ===\n");

    int shart_false_son = 10;

    // while: shart oldindan tekshiriladi -- agar false bo'lsa, tana ishlamaydi
    while (shart_false_son < 5) {
        printf("bu hech qachon chiqmaydi\n");
    }

    // do-while: tana KAMIDA 1 MARTA ishlaydi, chunki shart OXIRIDA tekshiriladi
    do {
        printf("do-while kamida 1 marta ishlaydi, hatto shart false bo'lsa ham\n");
    } while (shart_false_son < 5);

    printf("\n");
}


/* ------------------------------------------------------------
 * REAL HAYOTIY MISOLLAR (professional patternlar)
 * ------------------------------------------------------------ */

/* Sentinel (nazorat qiymati) pattern -- foydalanuvchi kiritishini
 * maxsus qiymat kelguncha davom ettirish */
void real_misol_sentinel(void) {
    printf("=== Real misol: sentinel pattern ===\n");
    printf("(Demo -- interaktiv kiritish o'rniga statik massiv ishlatilmoqda)\n");

    int qiymatlar[] = {5, 12, 8, -1, 20};   // -1 -- sentinel (to'xtatish belgisi)
    int i = 0;

    while (qiymatlar[i] != -1) {   // -1 kelguncha davom etadi
        printf("qiymat: %d\n", qiymatlar[i]);
        i++;
    }
    printf("Sentinel (-1) topildi, sikl to'xtadi\n\n");
}

/* Flag (bayroqcha) pattern -- element topilganda darhol to'xtatish */
void real_misol_flag(void) {
    printf("=== Real misol: flag pattern (qidiruv) ===\n");

    int massiv[] = {4, 8, 15, 16, 23, 42};
    int uzunlik = 6;
    int qidirilayotgan = 15;
    int i = 0;
    int topildi = 0;             // flag: hali topilmagan

    while (i < uzunlik && !topildi) {   // ikkita shart && bilan birlashtirilgan
        if (massiv[i] == qidirilayotgan) {
            topildi = 1;          // flag o'zgaradi -- shart false bo'lib, sikl tugaydi
            printf("Topildi: indeks %d\n", i);
        }
        i++;
    }

    if (!topildi) {
        printf("Qiymat topilmadi\n");
    }
    printf("\n");
}

/* Akkumulyator pattern -- massiv elementlari yig'indisi */
void real_misol_akkumulyator(void) {
    printf("=== Real misol: akkumulyator pattern (yig'indi) ===\n");

    int massiv[] = {10, 20, 30, 40, 50};
    int uzunlik = 5;
    int yigindi = 0;
    int indeks = 0;

    while (indeks < uzunlik) {
        yigindi += massiv[indeks];   // har bir elementni yig'indiga qo'shish
        indeks++;
    }

    printf("Yig'indi: %d\n\n", yigindi);
}


/* ------------------------------------------------------------
 * XULOSA -- 5 TA OLTIN QOIDA (kod tuzilishida eslatma sifatida)
 * ------------------------------------------------------------
 * 1. Shart bajarilishdan OLDIN tekshiriladi.
 * 2. Shartga ta'sir qiluvchi o'zgaruvchi ALBATTA yangilanishi kerak.
 * 3. `while (shart);` -- ortiqcha ";" bo'sh tana yasaydi, ehtiyot bo'ling.
 * 4. `=` va `==` ni chalkashtirmang.
 * 5. Har doim { } ishlating, hatto tana bitta qator bo'lsa ham.
 * ------------------------------------------------------------ */

int main(void) {
    qoida_1_har_qanday_ifoda();
    qoida_2_qavssiz_va_qavsli();
    qoida_3_break_continue();
    qoida_4_nested_while();
    qoida_5_funksiya_sharti();
    qoida_6_cheksiz_sikl_toʻgʻri();

    mumkin_emas_qoidalar();
    solishtirish_do_while();

    real_misol_sentinel();
    real_misol_flag();
    real_misol_akkumulyator();

    return 0;
}

