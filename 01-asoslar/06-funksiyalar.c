/*
 * 06 -- FUNKSIYALAR
 * =================
 */

#include <stdio.h>

// Funksiya prototipi (e'lon) -- compiler'ga oldindan xabar berish
int yigindi(int a, int b);
void salomlash(void);       // parametrsiz, qaytish qiymati yo'q

int main(void) {
    salomlash();

    int natija = yigindi(5, 7);   // funksiya chaqirilmoqda, natija saqlanmoqda
    printf("Yig'indi: %d\n", natija);

    // Funksiyani to'g'ridan-to'g'ri ifodada ishlatish ham mumkin
    printf("Yig'indi x2: %d\n", yigindi(3, 4) * 2);

    return 0;
}

// Funksiya ta'rifi (definition) -- haqiqiy kod shu yerda
int yigindi(int a, int b) {
    return a + b;    // qaytish qiymati -- chaqirgan joyga qaytadi
}

void salomlash(void) {
    printf("Salom, funksiyalar dunyosiga!\n");
    // return kerak emas, chunki qaytish turi void (hech narsa qaytarmaydi)
}

/*
 * ESLATMA:
 *   - Prototip nima uchun kerak? main() dan pastda joylashgan funksiyalarni
 *     compiler oldindan "tanishi" uchun. Aks holda "implicit declaration" xatosi.
 *   - Parametrlar funksiyaga NUSXA (copy) sifatida uzatiladi (pass by value) --
 *     funksiya ichida parametrni o'zgartirish chaqiruvchidagi asl qiymatga
 *     ta'sir qilmaydi (buni o'zgartirish uchun pointer kerak -- 08-faylga qarang).
 */

