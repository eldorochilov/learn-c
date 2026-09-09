/*
 * 03 -- OPERATORLAR
 * =================
 */

#include <stdio.h>

int main(void) {
    int a = 10, b = 3;

    // Arifmetik operatorlar
    printf("=== Arifmetik ===\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d   (butun bo'lish -- qoldiq tashlanadi)\n", a / b);
    printf("a %% b = %d  (modulo -- qoldiqni beradi)\n", a % b);

    // Solishtirish operatorlari -- natija har doim 0 (false) yoki 1 (true)
    printf("\n=== Solishtirish ===\n");
    printf("a == b: %d\n", a == b);
    printf("a != b: %d\n", a != b);
    printf("a > b : %d\n", a > b);
    printf("a <= b: %d\n", a <= b);

    // Mantiqiy operatorlar
    printf("\n=== Mantiqiy ===\n");
    printf("(a > 5) && (b < 5): %d\n", (a > 5) && (b < 5));  // ikkalasi ham true bo'lsa
    printf("(a > 5) || (b > 5): %d\n", (a > 5) || (b > 5));  // biri true bo'lsa yetarli
    printf("!(a > 5): %d\n", !(a > 5));                       // inkor

    // Bitwise (bitlar darajasida) operatorlar -- assembly/pastki daraja uchun muhim
    printf("\n=== Bitwise ===\n");
    printf("a & b  = %d  (AND)\n", a & b);
    printf("a | b  = %d  (OR)\n", a | b);
    printf("a ^ b  = %d  (XOR)\n", a ^ b);
    printf("~a     = %d  (NOT)\n", ~a);
    printf("a << 1 = %d  (chapga siljitish -- 2 ga ko'paytirish bilan teng)\n", a << 1);
    printf("a >> 1 = %d  (o'ngga siljitish -- 2 ga bo'lish bilan teng)\n", a >> 1);

    // Tayinlash operatorlari
    printf("\n=== Tayinlash ===\n");
    int x = 5;
    x += 3;  printf("x += 3  -> %d\n", x);
    x -= 2;  printf("x -= 2  -> %d\n", x);
    x *= 4;  printf("x *= 4  -> %d\n", x);
    x /= 2;  printf("x /= 2  -> %d\n", x);

    return 0;
}

/*
 * DIQQAT: `=` (tayinlash) va `==` (solishtirish) ni chalkashtirmang --
 * bu C dagi eng xavfli va sokin (silent) xatolardan biri.
 */

