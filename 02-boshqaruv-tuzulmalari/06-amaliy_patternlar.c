/*
 * 06 -- AMALIY PATTERNLAR
 * =========================
 * do-while + switch menu, input validation, qidiruv/saralash asoslari
 */

#include <stdio.h>

int main(void) {
    // PATTERN 1: Menu -- do-while + switch birgalikda (klassik kombinatsiya)
    printf("=== Pattern 1: Menu tuzilmasi (demo, statik tanlovlar bilan) ===\n");
    int tanlovlar[] = {1, 2, 4};   // demo uchun -- real dasturda scanf bo'lardi
    int idx = 0;
    int chiqish = 0;

    do {
        int tanlov = tanlovlar[idx++];
        printf("Tanlov: %d -> ", tanlov);
        switch (tanlov) {
            case 1:
                printf("Ma'lumot ko'rish\n");
                break;
            case 2:
                printf("Qo'shish\n");
                break;
            case 3:
                printf("O'chirish\n");
                break;
            case 4:
                printf("Chiqish\n");
                chiqish = 1;
                break;
            default:
                printf("Noto'g'ri tanlov\n");
        }
    } while (!chiqish);

    // PATTERN 2: Input validation -- to'g'ri qiymat kelguncha qayta so'rash
    printf("\n=== Pattern 2: Input validation ===\n");
    int demo_qiymatlar[] = {-3, -1, 7};   // demo -- oxirida to'g'ri qiymat
    int i = 0, qiymat;
    do {
        qiymat = demo_qiymatlar[i++];
        if (qiymat < 0) {
            printf("Xato: %d manfiy, qayta so'ralmoqda...\n", qiymat);
        }
    } while (qiymat < 0);
    printf("Qabul qilindi: %d\n", qiymat);

    // PATTERN 3: Chiziqli qidiruv (linear search) -- flag + while
    printf("\n=== Pattern 3: Chiziqli qidiruv ===\n");
    int massiv[] = {4, 8, 15, 16, 23, 42};
    int uzunlik = 6;
    int qidirilayotgan = 23;
    int topildi_indeks = -1;
    int j = 0;

    while (j < uzunlik) {
        if (massiv[j] == qidirilayotgan) {
            topildi_indeks = j;
            break;              // topilgach darhol to'xtash -- samaradorlik uchun muhim
        }
        j++;
    }

    if (topildi_indeks != -1) {
        printf("%d qiymati indeks %d da topildi\n", qidirilayotgan, topildi_indeks);
    } else {
        printf("Topilmadi\n");
    }

    // PATTERN 4: Oddiy saralash (bubble sort) asosi -- nested for
    printf("\n=== Pattern 4: Bubble sort asosi ===\n");
    int arr[] = {5, 2, 9, 1, 5};
    int n = 5;

    for (int a = 0; a < n - 1; a++) {
        for (int b = 0; b < n - a - 1; b++) {
            if (arr[b] > arr[b + 1]) {         // qo'shni elementlarni solishtirish
                int vaqtincha = arr[b];         // almashtirish (swap)
                arr[b] = arr[b + 1];
                arr[b + 1] = vaqtincha;
            }
        }
    }

    printf("Saralangan: ");
    for (int a = 0; a < n; a++) {
        printf("%d ", arr[a]);
    }
    printf("\n");

    return 0;
}

/*
 * ESLATMA:
 *   - Menu pattern -- do-while ishlatiladi, chunki menu kamida 1 marta
 *     ko'rsatilishi kerak (chiqish tanlanmaguncha).
 *   - Qidiruvda topilgach darhol `break` qilish -- katta massivlarda
 *     samaradorlikka katta ta'sir qiladi (keraksiz iteratsiyalarni tejaydi).
 *   - Bubble sort -- eng sodda saralash algoritmi, murakkabligi O(n^2),
 *     lekin nested for va swap mantig'ini o'rganish uchun ideal boshlang'ich.
 */

