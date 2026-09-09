/*
 * 04 -- while va do-while -- CHUQUR QO'LLANILISH
 * =================================================
 * (while ning to'liq nazariyasi alohida while_sikli_professional.c faylida --
 *  bu yer amaliy qo'llanilish patternlariga qaratilgan)
 */

#include <stdio.h>

int main(void) {
    // while -- shart oldindan tekshiriladi
    printf("=== while: massiv bo'ylab yurish ===\n");
    int massiv[] = {5, 10, 15, 20, 25};
    int uzunlik = 5;
    int i = 0;
    while (i < uzunlik) {
        printf("%d ", massiv[i]);
        i++;
    }
    printf("\n");

    // do-while -- kamida 1 marta ishlaydi, menu/input validation uchun ideal
    printf("\n=== do-while: input validation patterni ===\n");
    int son;
    int marta = 0;
    do {
        // Real dasturda: scanf("%d", &son); shu yerda bo'lardi
        son = (marta == 0) ? -5 : 10;   // demo uchun -- birinchi safar noto'g'ri qiymat
        marta++;
        if (son < 0) {
            printf("Xato: manfiy son, qayta urinib ko'ring\n");
        }
    } while (son < 0);
    printf("To'g'ri qiymat qabul qilindi: %d\n", son);

    // while vs do-while -- shart boshidanoq false bo'lgan holat
    printf("\n=== Farq: shart darhol false bo'lganda ===\n");
    int shart = 0;

    printf("while natijasi: ");
    while (shart) {              // hech qachon ishlamaydi
        printf("bu chiqmaydi ");
    }
    printf("(hech narsa chiqmadi)\n");

    printf("do-while natijasi: ");
    do {
        printf("bu bir marta chiqadi ");   // kamida 1 marta ishlaydi
    } while (shart);
    printf("\n");

    return 0;
}

/*
 * QACHON QAYSI BIRINI ISHLATISH KERAK:
 *   - while     -> iteratsiya soni oldindan noma'lum, shart 0 ham bo'lishi mumkin
 *                  (masalan: fayldan o'qish, qidiruv)
 *   - do-while  -> kamida 1 marta bajarilishi SHART bo'lgan holatlar
 *                  (masalan: menu ko'rsatish, foydalanuvchi kiritishini tekshirish)
 */

