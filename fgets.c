#include <stdio.h>      
// printf, fprintf, fgets — standart kirish/chiqish funksiyalari
#include <string.h>    
// strcspn — satr ichidan belgi qidirish uchun

int main(void)
{
  // Foydalanuvchi ismini saqlash uchun massiv.
  // 100 bayt — odatiy ism uchun yetarli, lekin fgets bilan
  // buferdan oshib ketish (overflow) ehtimoli yo'q, chunki
  // fgets max shu hajmda o'qiydi.
  char name[100];

  // Foydalanuvchiga so'rov chiqaramiz.
  // \n qo'ymadik, chunki kursor shu qatorda qolishi kerak.
  printf("Ismingiz: ");

  // fgets(buffer, buffer_hajmi, stdin) — stdin dan bitta qatorni o'qiydi.
  // sizeof name ishlatilishi muhim: massiv hajmini avtomatik hisoblaydi,
  // shuning uchun qattiq kodlangan "100" sonidan ko'ra xavfsizroq
  // (agar massiv hajmi keyinchalik o'zgarsa ham kod ishlayveradi).
  //
  // fgets NULL qaytarsa — bu demak o'qish muvaffaqiyatsiz bo'ldi
  // (masalan, EOF — Ctrl+D bosilgan, yoki kirish oqimida xatolik bor).
  if (fgets(name, sizeof name, stdin) == NULL) {
    // Xato xabarini stderr ga yozamiz (stdout emas),
    // chunki bu diagnostik xabar, dastur natijasi emas.
      fprintf(stderr, "Kiritishni o'qishda xato.\n");
      return 1;   // Dasturdan xato kodi bilan chiqamiz (0 emas — muvaffaqiyatsizlik belgisi)
}

    // fgets qatorni o'qiganda, agar foydalanuvchi Enter bossa,
    // o'sha "\n" belgisi ham name massiviga qo'shilib qoladi.
    // Bizga bu kerak emas, shuning uchun uni olib tashlaymiz:
    //
    // strcspn(name, "\n") — name ichida "\n" belgisi uchramaguncha
    // nechta belgi borligini qaytaradi (ya'ni \n ning pozitsiyasi).
    // O'sha pozitsiyaga '\0' (satr tugash belgisi) qo'yib,
    // satrni "\n" belgisidan oldin kesib tashlaymiz.
    //
    // Eslatma: agar foydalanuvchi 99 ta belgidan ko'p kiritsa va
    // \n bufer ichiga sig'may qolsa, strcspn butun satr uzunligini
    // qaytaradi va bu holatda ham kod xavfsiz ishlaydi (faqat \n
    // olib tashlanmay qoladi, lekin dastur qulamaydi).
  name[strcspn(name, "\n")] = '\0';

    // Endi name faqat foydalanuvchi ismini (ortiqcha \n siz) saqlaydi.
  printf("Salom, %s!\n", name);

  return 0;   // Dastur muvaffaqiyatli tugadi
}
