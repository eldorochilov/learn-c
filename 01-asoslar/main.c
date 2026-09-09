/*
 * ================================================================
 *   main() FUNKSIYASI — TO'LIQ QO'LLANMA
 * ================================================================
 *
 * main() — har qanday C dasturining "kirish nuqtasi" (entry point).
 * Operatsion tizim dasturni ishga tushirganda, aynan shu funksiyani
 * birinchi bo'lib chaqiradi.
 *
 * C standartida main() ning FAQAT 2 ta rasmiy (standart) shakli bor:
 *
 *   1) int main(void)                        — argumentsiz
 *   2) int main(int argc, char *argv[])       — argumentlar bilan
 *
 * Bulardan tashqari ba'zi kompilyatorlar (masalan GCC, Unix/Linux
 * tizimlarida) qo'shimcha, NOSTANDART uchinchi parametrni ham
 * qo'llab-quvvatlaydi — envp (environment variables). Bu haqida
 * pastda alohida bo'limda batafsil yoziladi.
 * ================================================================
 */


/* ================================================================
 * 1-QISM: int main(void) — ENG ODDIY SHAKL
 * ================================================================
 *
 * Bu shaklni ishlatamiz, qachonki dasturimiz buyruq qatoridan
 * (command line) hech qanday argument qabul qilmasa.
 *
 * "void" so'zi MUHIM: u "bu funksiya hech qanday parametr
 * qabul qilmaydi" deb ANIQ bildiradi. Agar shunchaki
 * int main() deb yozilsa (void siz), eski C standartida bu
 * "argumentlar noaniq" degan ma'noni anglatardi — zamonaviy
 * C da bunday yozish tavsiya etilmaydi.
 */

#include <stdio.h>

int main(void)
{
    printf("Bu oddiy main(void) misoli.\n");

    // return 0 — dastur MUVAFFAQIYATLI tugaganini operatsion
    // tizimga bildiradi. Bu qiymatni "exit status" yoki
    // "chiqish kodi" deyiladi.
    //
    // Odat bo'yicha:
    //   0        -> hammasi joyida (muvaffaqiyat)
    //   0 dan boshqa -> xatolik yuz berdi (odatda 1, 2 va h.k.)
    //
    // <stdlib.h> da bu uchun tayyor konstantalar bor:
    //   EXIT_SUCCESS -> 0 ga teng
    //   EXIT_FAILURE -> 1 ga teng (ba'zan boshqa qiymat)
    return 0;
}


/* ================================================================
 * 2-QISM: int main(int argc, char *argv[])
 * ================================================================
 *
 * Bu shaklni ishlatamiz, qachonki dastur BUYRUQ QATORIDAN
 * (terminal/konsoldan) argumentlar qabul qilishi kerak bo'lsa.
 *
 * Masalan, terminalda shunday yozilganda:
 *
 *      ./dastur salom dunyo 123
 *
 * dastur quyidagi ma'lumotlarni oladi:
 *
 *   argc (ARGument Count)  -> argumentlar SONI (int turi)
 *   argv (ARGument Vector) -> argumentlarning o'zi (satrlar massivi)
 *
 * DIQQAT: argv[0] har doim DASTURNING O'ZI NOMI (yoki yo'li) bo'ladi,
 * foydalanuvchi kiritgan HAQIQIY argumentlar argv[1] dan boshlanadi!
 *
 * Yuqoridagi misolda:
 *   argc = 4
 *   argv[0] = "./dastur"
 *   argv[1] = "salom"
 *   argv[2] = "dunyo"
 *   argv[3] = "123"
 *   argv[4] = NULL   <- argv massivi HAR DOIM NULL bilan tugaydi
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    // argv ni "char *argv[]" o'rniga "char **argv" deb ham yozish
    // mumkin — ikkalasi ham AYNAN BIR XIL narsani anglatadi
    // (satrlar massiviga pointer). Bu shunchaki ikki xil yozish
    // uslubi, farqi yo'q.

    printf("Dastur nomi: %s\n", argv[0]);
    printf("Argumentlar soni (argc): %d\n", argc);

    // argc har doim KAMIDA 1 ga teng bo'ladi, chunki argv[0]
    // (dastur nomi) doim mavjud.

    if (argc < 2) {
        // Foydalanuvchi hech qanday qo'shimcha argument bermagan
        printf("Hech qanday argument berilmadi.\n");
        printf("Foydalanish: %s <argument1> <argument2> ...\n", argv[0]);
        return 1;   // xato kodi bilan chiqamiz
    }

    // i = 1 dan boshlaymiz, chunki argv[0] dastur nomi, uni
    // "haqiqiy argument" sifatida hisobga olmaymiz
    for (int i = 1; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    return 0;
}


/* ================================================================
 * 3-QISM: argv orqali kelgan qiymatlarni SONGA aylantirish
 * ================================================================
 *
 * MUHIM: argv[] dagi HAMMA argumentlar SATR (char*) ko'rinishida
 * keladi, hatto foydalanuvchi son kiritgan bo'lsa ham!
 * Ya'ni "./dastur 25" desa, argv[1] "25" SATRI bo'ladi, 25 SONI EMAS.
 * Sonni ishlatish uchun uni albatta strtol/atoi kabi funksiyalar
 * bilan aylantirish kerak (avvalgi darslarimizda strtol ni
 * batafsil ko'rgan edik).
 */

#include <stdio.h>
#include <stdlib.h>   // strtol uchun

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Foydalanish: %s <son>\n", argv[0]);
        return 1;
    }

    char *end;
    long son = strtol(argv[1], &end, 10);

    if (end == argv[1]) {
        fprintf(stderr, "Xato: '%s' son emas.\n", argv[1]);
        return 1;
    }

    printf("Kiritilgan son: %ld\n", son);
    printf("Ikki barobari: %ld\n", son * 2);

    return 0;
}


/* ================================================================
 * 4-QISM: int main(int argc, char *argv[], char *envp[])
 * ================================================================
 *
 * Bu — NOSTANDART (lekin GCC, Clang kabi ko'p kompilyatorlarda,
 * ayniqsa Linux/Unix tizimlarida) keng qo'llaniladigan uchinchi
 * shakl. envp — "environment pointer" — bu orqali OPERATSION
 * TIZIM O'ZGARUVCHILARIGA (environment variables) kirish mumkin.
 *
 * Masalan: PATH, HOME, USER kabi tizim o'zgaruvchilari.
 *
 * DIQQAT: Bu ISO C standartining rasmiy qismi EMAS — ya'ni
 * bu kod Windows-ning ba'zi kompilyatorlarida yoki "qat'iy
 * standart" (-std=c99 -pedantic) rejimida ishlamasligi mumkin.
 * Portativ (ko'chma) kod yozish uchun buning o'rniga <stdlib.h>
 * dagi getenv() funksiyasini ishlatish tavsiya etiladi.
 */

#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    (void)argc;   // bu misolda argc ishlatilmayapti, shuning uchun
    (void)argv;   // kompilyatorning "ishlatilmagan parametr" haqidagi
                  // ogohlantirishini (warning) bostirish uchun shunday
                  // "(void)" bilan belgilab qo'yamiz — bu keng
                  // tarqalgan, professional amaliyot

    printf("Tizim muhit o'zgaruvchilari (environment variables):\n\n");

    // envp massivi ham argv kabi NULL bilan tugaydi.
    // Har bir element "NOM=QIYMAT" formatidagi satr bo'ladi.
    for (int i = 0; envp[i] != NULL; i++) {
        printf("%s\n", envp[i]);
    }

    return 0;
}


/* ================================================================
 * 5-QISM: PORTATIV (ko'chma) usul — getenv() bilan
 * ================================================================
 *
 * envp o'rniga, barcha platformalarda ishlaydigan STANDART usul —
 * bu <stdlib.h> kutubxonasidagi getenv() funksiyasi.
 * U bitta muhit o'zgaruvchisining qiymatini nomi bo'yicha qaytaradi.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // getenv("NOM") — agar shunday nomli muhit o'zgaruvchisi mavjud
    // bo'lsa, uning qiymatini (char*) qaytaradi; aks holda NULL.
    char *uy_papka = getenv("HOME");   // Linux/Mac da uy papka yo'li
                                         // Windows da "USERPROFILE" ishlatiladi

    if (uy_papka != NULL) {
        printf("Uy papka: %s\n", uy_papka);
    } else {
        printf("HOME o'zgaruvchisi topilmadi.\n");
    }

    return 0;
}


/* ================================================================
 * XULOSA JADVALI
 * ================================================================
 *
 * Shakl                                    | Qachon ishlatiladi
 * ------------------------------------------|--------------------------------
 * int main(void)                            | Argumentsiz oddiy dasturlar
 * int main(int argc, char *argv[])          | Buyruq qatoridan argument olish
 * int main(int argc, char **argv)           | Yuqoridagi bilan bir xil (uslub farqi)
 * int main(int argc, char *argv[], char *envp[]) | Muhit o'zgaruvchilariga to'g'ridan-to'g'ri kirish (NOSTANDART)
 * getenv("NOM")                             | Muhit o'zgaruvchisini PORTATIV (standart) o'qish usuli
 *
 * ESLATMA: Bitta .c faylda bir nechta main() funksiyasi BO'LISHI
 * MUMKIN EMAS — bu fayl faqat TA'LIMIY maqsadda, har bir bo'limni
 * ALOHIDA fayl yoki alohida kompilyatsiya qilib sinab ko'rish uchun
 * mo'ljallangan namuna sifatida tuzilgan.
 * ================================================================
 */

