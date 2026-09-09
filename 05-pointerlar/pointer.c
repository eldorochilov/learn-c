#include <stdio.h>
#include <stdlib.h>

int son = 0;
// Noto'g'ri usul — ishlamaydi
void increment_wrong(int x) {
    x += 1;
    // faqat lokal nusxa  o'zgaradi
}
// To'g'ri usul — pointer bilan
void increment_right(int *x) {
    *x += 1;
    // asl o'zgaruvchi o'zgaradi
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int (*op)(int, int);
// funksiya pointer e'loni

int main(void) {

    int num = 10;
    int *p = &num;
    // p endi numning manzilini saqlaydi

    printf("num qiymati: %d\n", num); // 10
    printf("num manzili: %p\n", &num);
    // masalan: 0x7ffd5a3c
    printf("p qiymati: %p\n", p);
    // xuddi shu manzil: 0x7ffd5a3c
    printf("p orqali x: %d\n", *p);
    // 10 (dereference qilish)

    int dig = 5;
    increment_wrong(dig);
    printf("%d\n", dig); // 5 — o'zgarmadi

    increment_right(&dig);
    printf("%d\n", dig); // 6 — o'zgardi!

    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    // massiv nomi — birinchi elementga pointer

    printf("%d\n", *ptr); // 10
    printf("%d\n", *(ptr + 1));
    // 20 (p+1 = 4 bayt keyingi joy, int uchun)
    printf("%d\n", *(ptr + 2)); // 30

    ptr++;                // endi p arr[1] ni ko'rsatadi
    printf("%d\n", *ptr); // 20

    int mssv[3] = {1, 2, 3};

    // Bu ikkisi bir xil natija beradi:
    printf("%d\n", mssv[1]);     // 2
    printf("%d\n", *(mssv + 1)); // 2

    // arr[i] aslida *(arr + i) ning "shakar" (syntax sugar) shakli
    int x_num = 100;
    int *pr = &x_num;
    int **pp = &pr; // pp — p ning manzilini saqlaydi

    printf("%d\n", **pp); // 100 — ikki marta dereference

    *pp = NULL; // p ni NULL qiladi (p o'zi, x emas)

    int *pmlc = (int *)malloc(sizeof(int) * 5); // 5 ta int uchun joy

    if (pmlc == NULL) {
        // xotira ajratilmadi
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        pmlc[i] = i * 10; // p[i] === *(p+i)
    }

    free(pmlc);  // xotirani qaytarish
    pmlc = NULL; // dangling pointer bo'lmasligi uchun

    /**int *pnl = NULL;
     *pnl = 5; // SEGMENTATION FAULT — NULL ni dereference qilib bo'lmaydi **/

    int *q;
    {
        int local = 10;
        q = &local;
    }
    // bu yerda 'local' scope tugadi, q "dangling pointer" bo'ldi
    printf("%d\n", *q); // aniqlanmagan xatti-harakat (undefined behavior)

    int w = 5, y = 10;

    const int *p1 = &w;       // *p1 orqali x ni o'zgartirib bo'lmaydi, lekin p1 = &y mumkin
    int *const p2 = &w;       // p2 boshqa manzilga ko'rsata olmaydi, lekin *p2 = 20 mumkin
    const int *const p3 = &w; // ikkalasi ham qat'iy

    op = add;
    printf("%d\n", op(3, 4)); // 7

    op = sub;
    printf("%d\n", op(3, 4)); // -1

    int *pSon = &son;
    *pSon = 44;
    printf("son qiymati 0 edi: %d\n", son);
    printf("son qiymati uzgardi: %d\n", *pSon);
    printf("son manzili: %p\n", &son);
    printf("pSon qiymati: %p\n", pSon);
    printf("pSon manzili: %p\n", &pSon);
    return 0;
}
