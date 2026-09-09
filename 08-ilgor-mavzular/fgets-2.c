#include <stdio.h>      // printf, fprintf, fgets
#include <stdlib.h>     // strtol — satrni songa aylantirish uchun
#include <errno.h>      // errno, ERANGE — o'girish xatolarini aniqlash uchun
#include <limits.h>      // LONG_MIN, LONG_MAX (kerak bo'lsa chegaralarni tekshirish uchun)

int main(void)
{
    // Kiritilgan matnni saqlash uchun bufer.
    // 100 bayt — yosh kabi qisqa son uchun ortiqcha ham yetarli.
    char buf[100];

    printf("Yoshingiz: ");

    // Foydalanuvchi kiritgan qatorni o'qiymiz.
    // fgets ishlatilgan sabab avvalgi kod bilan bir xil:
    // xavfsiz, hajm chegarasini o'zi nazorat qiladi.
    //
    // Agar o'qish muvaffaqiyatsiz bo'lsa (EOF yoki xato) — dasturdan chiqamiz.
    if (fgets(buf, sizeof buf, stdin) == NULL)
        return 1;

    // strtol ("string to long") — matnni long turidagi songa aylantiradi.
    // Nima uchun atoi() emas, aynan strtol()?
    // atoi() xato bo'lsa ham hech narsa bildirmaydi — 0 qaytaradi,
    // va bu 0 "haqiqiy nol" bilan "xato" o'rtasidagi farqni yo'qotadi.
    // strtol() esa xatolarni aniq tekshirish imkonini beradi (pastda ko'rasiz).
    char *end;      // strtol o'qishni to'xtatgan joyni shu yerga yozadi
    errno = 0;      // errno ni oldindan 0 ga tenglashtiramiz — bu MUHIM,
                     // chunki strtol errno ni faqat xato bo'lsa o'zgartiradi,
                     // muvaffaqiyatli chaqiruvda uni 0 ga qaytarib qo'ymaydi.
                     // Shuning uchun eski qiymat qolib ketmasligi uchun
                     // har chaqiruvdan oldin qo'lda tozalash kerak.

    // strtol(satr, &end_pointer, asos/baza)
    // - buf     : o'qiladigan satr
    // - &end    : o'qish qayerda to'xtaganini ko'rsatgan pointer qaytaradi
    // - 10      : o'nlik sanoq sistemasi (agar 0 bo'lsa, u avtomatik
    //             0x... yoki 0... prefikslarni ham tushunar edi)
    long age = strtol(buf, &end, 10);

    // Endi natijani bir necha jihatdan tekshiramiz:
    //
    // 1) end == buf
    //    Bu degani — strtol hech qanday raqamni o'qiy olmadi,
    //    ya'ni foydalanuvchi umuman son kiritmagan
    //    (masalan bo'sh qator yoki "abc" kabi matn kiritilgan holat).
    //
    // 2) errno == ERANGE
    //    Bu degani — kiritilgan son juda katta yoki juda kichik,
    //    long turi sig'dira olmaydigan darajada (overflow/underflow).
    //
    // 3) age < 0 || age > 150
    //    Bu esa dasturning o'z mantiqiy chegarasi — inson yoshi
    //    0 dan kichik yoki 150 dan katta bo'lishi mumkin emas.
    //    Bu "sintaktik to'g'ri, lekin mantiqan noto'g'ri" holatlarni tutadi
    //    (masalan -5 yoki 99999 kabi sonlar).
    if (end == buf || errno == ERANGE ||
        age < 0 || age > 150) {
        fprintf(stderr, "Noto'g'ri son.\n");
        return 1;
    }

    // Barcha tekshiruvlardan o'tgan bo'lsa — natija ishonchli, chop etamiz.
    printf("Yosh: %ld\n", age);

    return 0;
}
