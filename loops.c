#include <stdio.h>

int main() {
  int i, j;

  // Tashqi sikl (Outer loop)
  for (i = 1; i <= 5; i++) {
    printf("Tashqi sikl i = %d\n", i);

    // Ichki sikl (Inner loop)
    for (j = 1; j <= 5; j++) {
      printf("   Ichki sikl j = %d\n", j);
    }
  }

  printf("\n Ikkinchi misol\n");

  for (i = 1; i <= 5; i++) {
    printf("%d ", i);
    for (j = 1; j <= 5; j++) {
      printf("* %4d", i * j); // Har bir ko'paytmani tekislab chiqaradi
    }
    printf("\n"); // Har bir qatordan keyin yangi qatorga o'tish
  }

  printf("\n Uchunchi misol\n");

  int qatorlar = 5;

  for (int i = 1; i <= qatorlar; i++) {
    printf("%d", i);
    for (int j = 1; j <= i; j++) {
      printf("* ");
    }
    printf("\n");
  }

  printf("\n Tortinchi misol\n");

  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (j == 2) {
        break; // Faqat j siklini to'xtatadi, i sikli davom etadi
      }
      printf("i = %d, j = %d\n", i, j);
    }
  }

  return 0;
}
