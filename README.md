# 🚀 C Dasturlash Tilini O'rganish

<div align="center">

![C Language](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Status](https://img.shields.io/badge/Status-Learning-brightgreen?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)

**C dasturlash tilini noldan mukammal darajagacha o'rganish jarayoni — nazariya, amaliy misollar va loyihalar bilan.**

[Boshlash](#-qanday-boshlash-kerak) • [Mavzular](#-mavzular-royxati) • [Loyihalar](#-loyihalar) • [Manbalar](#-foydali-manbalar)

</div>

---

## 📖 Bu repository haqida

Ushbu repository C dasturlash tilini **boshlang'ich darajadan murakkab darajagacha** bosqichma-bosqich o'rganish uchun yaratilgan. Har bir mavzu:

- ✅ Batafsil izohlangan kod namunalari bilan
- ✅ O'zbek tilida tushuntirishlar bilan
- ✅ Amaliy mashqlar va kichik loyihalar bilan
- ✅ Keng tarqalgan xatolar va ularning yechimlari bilan

ta'minlangan.

---

## 🗂 Repository tuzilishi

```
c-ogrenish/
├── 01-asoslar/              # O'zgaruvchilar, turlar, operatorlar
├── 02-boshqaruv-tuzilmalari/ # if/else, switch, for, while, do-while
├── 03-funksiyalar/          # Funksiya turlari, rekursiya, pointerlar
├── 04-massivlar-va-satrlar/ # Array, string, ko'p o'lchamli massivlar
├── 05-pointerlar/           # Pointer arifmetikasi, dinamik xotira
├── 06-strukturalar/         # struct, union, enum
├── 07-fayllar-bilan-ishlash/ # File I/O (fopen, fread, fwrite...)
├── 08-ilgor-mavzular/       # Xotira boshqaruvi, function pointers,
│                            # dispatch table, memoization
├── loyihalar/               # Amaliy mini-loyihalar
└── README.md
```

---

## 🎯 Qanday boshlash kerak

1. Repositoryni klonlang:
   ```bash
   git clone https://github.com/foydalanuvchi-nomi/c-ogrenish.git
   cd learn-c
   ```

2. GCC kompilyatorini o'rnating (agar hali o'rnatilmagan bo'lsa):
   ```bash
   # Ubuntu / Debian
   sudo apt install gcc

   # macOS (Homebrew)
   brew install gcc

   # Windows — MinGW yoki WSL orqali
   ```

3. Istalgan faylni kompilyatsiya qilib ishga tushiring:
   ```bash
   gcc -Wall -Wextra -o dastur fayl_nomi.c
   ./dastur
   ```

   > 💡 **Maslahat:** `-Wall -Wextra` flaglari kompilyatorni barcha ogohlantirishlarni (warning) ko'rsatishga majburlaydi — bu xatolarni erta topishga yordam beradi.

---

## 📚 Mavzular ro'yxati

### 🟢 Boshlang'ich daraja
- [ ] O'zgaruvchilar va ma'lumot turlari (`int`, `float`, `char`, `double`...)
- [ ] Kiritish/chiqarish (`printf`, `scanf`, `fgets`)
- [ ] Operatorlar (arifmetik, mantiqiy, taqqoslash)
- [ ] Shartli operatorlar (`if`, `else if`, `else`, `switch`)
- [ ] Takrorlash sikllari (`for`, `while`, `do-while`)

### 🟡 O'rta daraja
- [ ] Massivlar (bir va ko'p o'lchamli)
- [ ] Satrlar (strings) va `string.h` kutubxonasi
- [ ] Funksiyalar: e'lon qilish, chaqirish, qaytish qiymatlari
- [ ] Parametrlarni uzatish: qiymat bo'yicha vs pointer bo'yicha
- [ ] Struktura (`struct`), `union`, `enum`
- [ ] Fayllar bilan ishlash (`fopen`, `fclose`, `fread`, `fwrite`)

### 🔴 Yuqori daraja
- [ ] Pointerlar va pointer arifmetikasi *(eng muhim mavzu!)*
- [ ] Dinamik xotira boshqaruvi (`malloc`, `calloc`, `realloc`, `free`)
- [ ] Rekursiya va tail recursion optimizatsiyasi
- [ ] Funksiya pointerlari (function pointers) va dispatch table
- [ ] Variadic funksiyalar (`stdarg.h`)
- [ ] Inline va static funksiyalar
- [ ] Memoization va samaradorlikni oshirish texnikalari
- [ ] Preprocessor direktivalari (`#define`, `#ifdef`, makroslar)
- [ ] Multi-file loyihalar va header fayllar (`.h`)

---

## 💡 Muhim tushunchalar (Cheat Sheet)

| Mavzu | Qisqacha izoh |
|---|---|
| **Pointer** | Xotiradagi manzilni saqlovchi o'zgaruvchi — C tilining yuragi |
| **Stack vs Heap** | Stack — avtomatik, tez, cheklangan; Heap — qo'lda boshqariladigan, katta hajmli |
| **Qiymat bo'yicha uzatish** | Funksiyaga nusxa boriladi, asl o'zgaruvchi o'zgarmaydi |
| **Pointer bo'yicha uzatish** | Funksiyaga manzil boriladi, asl o'zgaruvchini o'zgartirish mumkin |
| **Rekursiya** | Funksiyaning o'zini o'zi chaqirishi — har doim "base case" bo'lishi shart |

> ⚠️ **Eng ko'p uchraydigan xatolar:**
> - Lokal o'zgaruvchiga pointer qaytarish (dangling pointer)
> - Rekursiyada base case yo'qligi (cheksiz chaqiruv → stack overflow)
> - `malloc` dan keyin `free` qilishni unutish (memory leak)
> - Massiv chegarasidan chiqib ketish (buffer overflow)

---

## 🛠 Loyihalar

Nazariyani mustahkamlash uchun amaliy loyihalar:

| # | Loyiha nomi | Qo'llaniladigan mavzular |
|---|---|---|
| 1 | Kalkulyator | Funksiyalar, switch |
| 2 | Talabalar bazasi (CRUD) | Struct, massivlar, fayllar |
| 3 | Bog'langan ro'yxat (Linked List) | Pointerlar, dinamik xotira |
| 4 | So'zlarni saralash dasturi | Satrlar, algoritmlar |
| 5 | Oddiy "shell" emulyatori | Fayllar, jarayonlar |

---

## 📌 Progress Tracker

- [x] Asoslar bilan tanishish
- [x] Boshqaruv tuzilmalari (sikllar, shartlar)
- [x] Funksiyalar — barcha turlari
- [ ] Pointerlar va dinamik xotira
- [ ] Fayllar bilan ishlash
- [ ] Yakuniy loyiha

---

## 📎 Foydali manbalar

- [C Reference — cppreference.com](https://en.cppreference.com/w/c)
- [Learn-C.org](https://www.learn-c.org/)
- *"The C Programming Language"* — K&R (Kernighan & Ritchie) — klassik kitob
- [GDB Debugger qo'llanmasi](https://sourceware.org/gdb/documentation/)

---

## 🤝 Hissa qo'shish

Agar sizda takliflar yoki tuzatishlar bo'lsa, Pull Request yuborishdan tortinmang! Har qanday yordam mamnuniyat bilan qabul qilinadi.

---

<div align="center">

**⭐ Agar bu repository foydali bo'lsa, star bosishni unutmang!**

</div>

