/*
 * 01 -- SINTAKSIS ASOSLARI
 * ========================
 * Har bir C dasturi shu tuzilmadan iborat:
 *   1. Preprocessor direktivalari (#include)
 *   2. Funksiya e'lonlari (kerak bo'lsa)
 *   3. main() -- dastur shu yerdan boshlanadi
 */

#include <stdio.h>   // standart kirish/chiqish kutubxonasi (printf, scanf va h.k.)

// Bu bir qatorli kommentar
/* Bu esa
   ko'p qatorli kommentar */

int main(void) {          // dastur ijrosi shu funksiyadan boshlanadi
    printf("Salom, C!\n"); // ekranga matn chiqarish

    return 0;               // 0 -- dastur muvaffaqiyatli tugadi degani (OS ga signal)
}

/*
 * KOMPILYATSIYA JARAYONI:
 *   .c fayl -> preprocessing -> compiling -> assembling -> linking -> binary
 *   $ gcc 01-sintaksis.c -o dastur
 *   $ ./dastur
 *
 * return 0 nima uchun kerak?
 *   OS (yoki chaqiruvchi skript) dastur muvaffaqiyatli tugaganini
 *   shu qiymat orqali biladi. 0 = muvaffaqiyat, 0 dan farqli = xato kodi.
 */

