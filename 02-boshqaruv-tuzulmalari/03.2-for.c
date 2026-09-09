#include <stdio.h>

/*
 * ============================================================
 *   FOR SIKLI — TO'LIQ QO'LLANMA VA MISOLLAR
 * ============================================================
 *
 * for sikli sintaksisi:
 *
 *      for (boshlang'ich; shart; qadam) {
 *          // takrorlanadigan kod
 *      }
 *
 *   1) boshlang'ich  — faqat 1 marta bajariladi, hisoblagichni o'rnatadi
 *   2) shart         — har aylanishdan OLDIN tekshiriladi;
 *                       true bo'lsa sikl davom etadi, false bo'lsa to'xtaydi
 *   3) qadam         — har aylanishdan KEYIN bajariladi
 *                       (odatda hisoblagichni oshiradi yoki kamaytiradi)
 * ============================================================
 */

int main(void)
{
    // ==========================================================
    // 1) ODDIY O'SUVCHI SIKL — 1 dan 10 gacha sanash
    // ==========================================================
    printf("=== 1) Oddiy o'suvchi sikl ===\n");

    for (int i = 1; i <= 10; i++) {
        // i = 1, 2, 3, ..., 10 — har safar 1 ga oshadi (i++)
        printf("%d ", i);
    }
    printf("\n\n");


    // ==========================================================
    // 2) KAMAYUVCHI SIKL — 10 dan 1 gacha teskari sanash
    // ==========================================================
    printf("=== 2) Kamayuvchi sikl ===\n");

    for (int i = 10; i >= 1; i--) {
        // i-- : har safar 1 ga kamayadi
        printf("%d ", i);
    }
    printf("\n\n");


    // ==========================================================
    // 3) QADAM (STEP) BILAN SIKL — faqat juft sonlarni chiqarish
    // ==========================================================
    printf("=== 3) Juft sonlar (qadam = 2) ===\n");

    for (int i = 0; i <= 20; i += 2) {
        // i += 2 : har safar 2 ga oshadi (0, 2, 4, 6, ...)
        printf("%d ", i);
    }
    printf("\n\n");


    // ==========================================================
    // 4) YIG'INDI HISOBLASH — 1 dan 100 gacha sonlar yig'indisi
    // ==========================================================
    printf("=== 4) 1 dan 100 gacha yig'indi ===\n");

    long yigindi = 0;   // natijani saqlaydigan o'zgaruvchi (0 dan boshlaymiz)

    for (int i = 1; i <= 100; i++) {
        yigindi += i;   // yigindi = yigindi + i
    }

    printf("Yig'indi = %ld\n\n", yigindi);


    // ==========================================================
    // 5) FAKTORIAL HISOBLASH — n! = 1 * 2 * 3 * ... * n
    // ==========================================================
    printf("=== 5) Faktorial (5!) ===\n");

    int n = 5;
    long faktorial = 1;   // ko'paytmada boshlang'ich qiymat 1 bo'lishi shart
                           // (0 bo'lsa hamma narsa 0 ga aylanib qoladi)

    for (int i = 1; i <= n; i++) {
        faktorial *= i;    // faktorial = faktorial * i
    }

    printf("%d! = %ld\n\n", n, faktorial);


    // ==========================================================
    // 6) MASSIV (ARRAY) ELEMENTLARINI KO'RIB CHIQISH
    // ==========================================================
    printf("=== 6) Massiv elementlari ===\n");

    int sonlar[] = {12, 45, 7, 89, 23, 56};

    // sizeof(sonlar) — massivning umumiy hajmi (baytda)
    // sizeof(sonlar[0]) — bitta elementning hajmi (baytda)
    // Ularni bo'lish orqali massivdagi elementlar sonini topamiz.
    int uzunlik = sizeof(sonlar) / sizeof(sonlar[0]);

    for (int i = 0; i < uzunlik; i++) {
        // Massiv indekslari har doim 0 dan boshlanadi!
        printf("sonlar[%d] = %d\n", i, sonlar[i]);
    }
    printf("\n");


    // ==========================================================
    // 7) MASSIVDAGI ENG KATTA ELEMENTNI TOPISH
    // ==========================================================
    printf("=== 7) Eng katta sonni topish ===\n");

    int eng_katta = sonlar[0];   // dastlab birinchi elementni "nomzod" deb olamiz

    for (int i = 1; i < uzunlik; i++) {
        // i = 1 dan boshlaymiz, chunki sonlar[0] allaqachon tekshirilgan
        if (sonlar[i] > eng_katta) {
            eng_katta = sonlar[i];   // yangi rekord topilsa, uni saqlaymiz
        }
    }

    printf("Eng katta son: %d\n\n", eng_katta);


    // ==========================================================
    // 8) ICHMA-ICH (NESTED) SIKL — ko'paytirish jadvali
    // ==========================================================
    printf("=== 8) Ko'paytirish jadvali (1-5) ===\n");

    for (int i = 1; i <= 5; i++) {          // tashqi sikl — qatorlar
        for (int j = 1; j <= 5; j++) {      // ichki sikl — ustunlar
            printf("%3d", i * j);           // %3d — 3 xonaga tekislab chiqaradi
        }
        printf("\n");   // har bir qator tugagach yangi qatorga o'tamiz
    }
    printf("\n");


    // ==========================================================
    // 9) YULDUZCHALAR UCHBURCHAGI — nested sikl bilan shakl chizish
    // ==========================================================
    printf("=== 9) Yulduzcha uchburchagi ===\n");

    int balandlik = 5;

    for (int i = 1; i <= balandlik; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");


    // ==========================================================
    // 10) continue OPERATORI — bitta qadamni o'tkazib yuborish
    // ==========================================================
    printf("=== 10) continue: faqat toq sonlarni chiqarish ===\n");

    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            // i juft bo'lsa, continue shu aylanishning qolgan qismini
            // o'tkazib yuboradi va to'g'ridan-to'g'ri keyingi i ga o'tadi
            continue;
        }
        printf("%d ", i);   // faqat toq sonlar uchun bajariladi
    }
    printf("\n\n");


    // ==========================================================
    // 11) break OPERATORI — shartga yetganda siklni to'xtatish
    // ==========================================================
    printf("=== 11) break: 7 ga yetganda to'xtash ===\n");

    for (int i = 1; i <= 20; i++) {
        if (i == 7) {
            // break — siklni butunlay tark etadi (i qolgan qiymatlarga
            // hech qachon yetmaydi)
            break;
        }
        printf("%d ", i);
    }
    printf("\n\n");


    // ==========================================================
    // 12) CHEKSIZ SIKL (for bilan) — qo'lda to'xtatiladi
    // ==========================================================
    printf("=== 12) Cheksiz sikl namunasi (5 martada to'xtatamiz) ===\n");

    int hisoblagich = 0;

    // for (;;) — barcha uchta qism bo'sh qoldirilsa, sikl cheksiz aylanadi.
    // Bunday sikllarni faqat ichida break bo'lgandagina ishlatish kerak!
    for (;;) {
        printf("Aylanish: %d\n", hisoblagich);
        hisoblagich++;

        if (hisoblagich >= 5) {
            break;   // aks holda dastur to'xtovsiz ishlab, "osilib" qoladi
        }
    }

    return 0;
}

