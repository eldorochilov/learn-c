/* 
================================================================================
  8-QISM: FUNKSIYA POINTERLARI VA DISPATCH JADVALI
================================================================================
  
  Mundarija:
    1. Oddiy funksiya pointeri va sintaksis
    2. Funksiyani boshqa funksiyaga argument sifatida uzatish (Callback)
    3. Massivli Dispatch Table (Funksiya pointerlari massivi)
    4. Kengaytirilgan Dispatch Table (Funksiyalar va nomlar)
================================================================================
*/

#include <stdio.h>
#include <string.h>

/* ============================================================================
   1. ASOSIY ISHCHI FUNKSIYALAR
   ============================================================================
   Dispatch jadvali va pointerlar orqali boshqariladigan sof funksiyalar.
*/

int qo_shish(int a, int b) {
    return a + b;
}

int ayirish(int a, int b) {
    return a - b;
}

int ko_paytirish(int a, int b) {
    return a * b;
}

int bo_lish(int a, int b) {
    if (b == 0) {
        printf("Xatolik: Nolga bo'lish mumkin emas!\n");
        return 0;
    }
    return a / b;
}


/* ============================================================================
   2. FUNKSIYA POINTERINI TYPEDEF QILISH
   ============================================================================
   Bu tur ikkita 'int' qabul qilib, 'int' qaytaradigan har qanday funksiya 
   manzilini saqlay oladi.
*/
typedef int (*MatematikFunksiya)(int, int);


/* ============================================================================
   3. CALLBACK FUNKSIYA
   ============================================================================
   Funksiyani argument sifatida qabul qilib, uni ishga tushiruvchi funksiya.
*/
void hisobla_va_chop_et(MatematikFunksiya bajaruvchi_funksiya, int x, int y) {
    int natija = bajaruvchi_funksiya(x, y);
    printf("Callback natijasi: %d\n", natija);
}


/* ============================================================================
   4. DISPATCH TABLE FUNKSIYALARI
   ============================================================================
*/

// Direct Indexing Dispatch Table (To'g'ridan-to'g'ri indeksli jadval)
// Funksiya pointerlaridan tashkil topgan massiv
MatematikFunksiya mat_jadval[] = {
    qo_shish,      // Indeks 0
    ayirish,       // Indeks 1
    ko_paytirish,  // Indeks 2
    bo_lish        // Indeks 3
};

// Indeks bo'yicha funksiyani chaqiruvchi dispatch funksiyasi
void bajar_indeks_boyicha(int amal_indeksi, int a, int b) {
    if (amal_indeksi < 0 || amal_indeksi >= 4) {
        printf("Xatolik: Noto'g'ri amal indeksi!\n");
        return;
    }
    
    // Switch-case yoki if-else siz, to'g'ridan-to'g'ri funksiyani chaqirish (O(1))
    int natija = mat_jadval[amal_indeksi](a, b);
    printf("Jadval [%d] natijasi: %d\n", amal_indeksi, natija);
}


// Nom bo'yicha qidiruvchi Dispatch Table uchun namuna
void buyruq_ping(void) { printf("-> Javob: PONG!\n"); }
void buyruq_start(void) { printf("-> Tizim ishga tushdi.\n"); }
void buyruq_stop(void) { printf("-> Tizim to'xtatildi.\n"); }

// Argument qabul qilmaydigan va qiymat qaytarmaydigan funksiyalar poenteri
typedef void (*BuyruqFunksiya)(void);

// Text-based Dispatch Table strukturasiz (2 ta parallel massiv orqali)
const char *buyruq_nomlari[] = { "PING", "START", "STOP" };
BuyruqFunksiya buyruq_funksiyalari[] = { buyruq_ping, buyruq_start, buyruq_stop };

// Nom bo'yicha tegishli funksiyani topib chaqiruvchi funksiya
void bajar_nom_boyicha(const char *buyruq_nomi) {
    int buyruqlar_soni = 3;
    
    for (int i = 0; i < buyruqlar_soni; i++) {
        if (strcmp(buyruq_nomi, buyruq_nomlari[i]) == 0) {
            buyruq_funksiyalari[i](); // Mos funksiya chaqiriladi
            return;
        }
    }
    printf("Xatolik: '%s' nomli funksiya topilmadi!\n", buyruq_nomi);
}


/* ============================================================================
   5. BASHARUVCHI MAIN FUNKSIYASI
   ============================================================================
*/
int main(void) {
    printf("=== 1. ODDIIY FUNKSIYA POINTERI ===\n");
    MatematikFunksiya f_ptr = qo_shish;
    printf("qo_shish(10, 20) -> %d\n", f_ptr(10, 20));
    
    f_ptr = ko_paytirish;
    printf("ko_paytirish(10, 20) -> %d\n\n", f_ptr(10, 20));


    printf("=== 2. CALLBACK FUNKSIYALARI ===\n");
    hisobla_va_chop_et(ayirish, 50, 15);
    hisobla_va_chop_et(bo_lish, 100, 4);
    printf("\n");


    printf("=== 3. DISPATCH TABLE (INDEKS BO'YICHA) ===\n");
    // 0: Qo'shish, 1: Ayirish, 2: Ko'paytirish, 3: Bo'lish
    bajar_indeks_boyicha(0, 12, 8);  // qo_shish funksiyasi ishlaydi
    bajar_indeks_boyicha(2, 6, 7);   // ko_paytirish funksiyasi ishlaydi
    bajar_indeks_boyicha(3, 20, 5);  // bo_lish funksiyasi ishlaydi
    printf("\n");


    printf("=== 4. DISPATCH TABLE (NOM BO'YICHA) ===\n");
    bajar_nom_boyicha("PING");   // buyruq_ping funksiyasini chaqiradi
    bajar_nom_boyicha("START");  // buyruq_start funksiyasini chaqiradi
    bajar_nom_boyicha("RESET");  // Topilmaydi
    
    return 0;
}

