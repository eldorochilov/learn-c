/*
 * 05 -- break, continue, goto/label
 * ====================================
 */

#include <stdio.h>

int main(void) {
    // break -- siklni BUTUNLAY to'xtatadi
    printf("=== break ===\n");
    for (int i = 0; i < 10; i++) {
        if (i == 5) {
            break;            // i=5 bo'lganda sikl butunlay to'xtaydi
        }
        printf("%d ", i);
    }
    printf("\n");

    // continue -- faqat JORIY iteratsiyani tashlab, keyingisiga o'tadi
    printf("\n=== continue ===\n");
    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            continue;         // juft sonlarni o'tkazib yuboradi
        }
        printf("%d ", i);     // faqat toq sonlar chop etiladi
    }
    printf("\n");

    // break faqat ENG ICHKI siklni to'xtatadi -- nested holatda diqqat qiling
    printf("\n=== break nested sikldagi cheklovi ===\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 1) {
                break;         // faqat ICHKI (j) siklni to'xtatadi
            }
            printf("(%d,%d) ", i, j);
        }
    }
    printf("\n");

    // Ikkita siklni birdan to'xtatish uchun -- flag yoki goto kerak bo'ladi
    printf("\n=== Ikkita siklni birdan to'xtatish (flag bilan) ===\n");
    int topildi = 0;
    for (int i = 0; i < 3 && !topildi; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                topildi = 1;
                break;         // ichki sikldan chiqadi
            }
            printf("(%d,%d) ", i, j);
        }
    }
    printf("\n");

    // goto -- C da mavjud, lekin ZAMONAVIY kodda DEYARLI ISHLATILMAYDI.
    // Yagona keng qabul qilingan holat -- ko'p darajali nested sikldan
    // bir zarbda chiqish (masalan xato holatlarida cleanup uchun).
    printf("\n=== goto (kam ishlatiladigan, lekin mavjud) ===\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                goto tugadi;    // barcha nested sikllardan bir zarbda chiqadi
            }
            printf("(%d,%d) ", i, j);
        }
    }
    tugadi:                    // label -- goto shu yerga "sakraydi"
    printf("\ngoto orqali shu yerga sakrab keldik\n");

    return 0;
}

/*
 * ESLATMA:
 *   - goto dan qochish tavsiya etiladi -- u kodni o'qishni qiyinlashtiradi
 *     ("spaghetti code"). Ko'pchilik holatlarda flag yoki funksiyaga
 *     ajratib chiqish (return bilan) yaxshiroq yechim.
 *   - Lekin C da xato boshqaruvi (error handling, resurslarni tozalash)
 *     uchun ba'zan goto haligacha "toza" yechim hisoblanadi -- bu haqda
 *     Linux kernel kod uslubida ko'proq o'qishingiz mumkin.
 */

