/*
 * 04 -- KIRISH VA CHIQISH (printf / scanf)
 * =========================================
 */

#include <stdio.h>

int main(void) {
    // printf format spesifikatorlari
    int    son   = 25;
    float  narx  = 19.99f;
    char   harf  = 'X';
    char   satr[] = "Salom";

    printf("=== printf format spesifikatorlari ===\n");
    printf("%%d -> %d\n", son);      // butun son
    printf("%%f -> %f\n", narx);     // kasr son (default 6 xona)
    printf("%%.2f -> %.2f\n", narx); // kasr son, 2 xona aniqlik bilan
    printf("%%c -> %c\n", harf);     // bitta belgi
    printf("%%s -> %s\n", satr);     // satr (string)
    printf("%%x -> %x\n", son);      // 16-lik (hex) ko'rinishda
    printf("%%o -> %o\n", son);      // 8-lik (octal) ko'rinishda

    // scanf -- foydalanuvchidan ma'lumot o'qish
    // DIQQAT: o'zgaruvchi manzili (&) berilishi shart, o'zi emas!
    printf("\nYoshingizni kiriting: ");
    int yosh;
    scanf("%d", &yosh);   // & -- "yosh o'zgaruvchisining xotiradagi manzili"
    printf("Siz %d yoshdasiz\n", yosh);

    return 0;
}

/*
 * ESLATMA:
 *   - scanf("%d", &yosh) da & ni unutish -- eng ko'p uchraydigan xato,
 *     bu dasturni crash qilishi yoki noto'g'ri xotiraga yozishi mumkin.
 *   - satr (string) uchun scanf("%s", satr) -- bu yerda & KERAK EMAS,
 *     chunki massiv nomi allaqachon manzilga ishora qiladi.
 */

