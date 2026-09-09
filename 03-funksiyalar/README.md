# 03-funksyalar

C tilida **funksiyalar** (functions) mavzusini chuqur o'rganish uchun o'quv loyihasi. Kod bitta faylga (`funksiyalar.c`) yozilgan bo'lib, har bir konsepsiya izchil, professional darajadagi izohlar bilan tushuntirilgan.

## Nima o'rganiladi

| # | Mavzu | Faylda qayerda |
|---|-------|-----------------|
| 1 | Funksiya prototipi (deklaratsiya) vs ta'rif (definitsiya) | 1-qism |
| 2 | `void` funksiya — parametrsiz, qiymat qaytarmaydi | 2-qism |
| 3 | Qiymat qaytaruvchi funksiya (`return`) | 3-qism |
| 4 | **qiymat buyicha qaytarish** — parametrlar qanday nusxalanadi | 4-qism |
| 5 | Pointer orqali **havola buyicha uzatish** simulyatsiyasi (swap misoli) | 5-qism |
| 6 | **Rekursiya** va bazaviy holat (faktorial misoli) | 6-qism |
| 7 | `static` funksiya — ko'rinish doirasini faylga cheklash | 7-qism |
| 8 | **Funksiya pointerlari** — dispatch jadvali (kalkulyator misoli) | 8-qism |

Har bir bo'limda, siz o'rganayotgan ARM64 assembly bilan bog'liq qisqacha eslatmalar ham bor — masalan, argumentlar qanday qilib `x0`–`x7` registrlari orqali uzatilishi, qaytish qiymati `x0`da saqlanishi va rekursiyada har bir chaqiruv nega yangi stek freym ochishi.

## Talab qilinadigan vositalar

- **C kompilyatori**: `gcc` yoki `clang` (ikkalasi ham ishlaydi)
- Termux muhitida: `pkg install clang` (agar `gcc` bo'lmasa)

## Kompilyatsiya va ishga tushirish

```bash
gcc full_functions.c -o dastur -Wall -Wextra
./dastur
```

yoki Termux/ARM64 muhitida `clang` bilan:

```bash
clang full_functions.c -o dastur -Wall -Wextra
./dastur
```

`-Wall -Wextra` bayroqlari qo'shimcha ogohlantirishlarni yoqadi — bu real loyihalarda yashirin xatolarni erta topishga yordam beradi, shuning uchun har doim ishlatish tavsiya etiladi.

## Kutilayotgan natija

```
Salom! Bu funksiyalar darsining namunasi.

7 ning kvadrati: 49

Pass by value: funksiyadan keyin ham qiymat o'zgarmadi -> 5

Almashtirishdan oldin: x=10, y=20
Almashtirishdan keyin:  x=20, y=10

6! (faktorial) = 720

17 ni 5 ga bo'lgandagi qoldiq: 2

Funksiya pointerlari orqali kalkulyator:
  8 va 3 uchun qo'shish natijasi: 11
  8 va 3 uchun ayirish natijasi: 5
  8 va 3 uchun ko'paytirish natijasi: 24
```

## Keyingi qadamlar (o'zingiz sinab ko'rish uchun)

- `faktorial()` funksiyasini iterativ (rekursiyasiz, `for` sikli bilan) qayta yozib, ikkalasini tezlik jihatidan solishtiring.
- `ikkitasini_almashtir()` ni `long` yoki `double` turlari uchun ham ishlaydigan qilib generic yondashuv bilan qayta yozishga urinib ko'ring.
- `objdump -d dastur` yoki `gdb` bilan `kvadrat()` funksiyasining ARM64 assembly chiqishini ko'ring va uni o'zingiz yozgan `.s` fayllar bilan solishtiring.

