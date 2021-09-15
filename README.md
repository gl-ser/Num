# Num
Библиотека работы с числовыми данными

1. TNumerical - Класс статических методов манипуляции с числами

2. TNumber - Целое число в различных системах счисления

---

### 1. TNumerical

#### Публичные статические методы

1.1. _Factorial_ вычисление факториала числа (рекурсивная функция)

Синтаксис:

```cpp
static double Factorial(int n)
```

1.2. _CnK_ комбинаторное число сочетаний 'це' из 'эн' по 'ка'

Синтаксис:

```cpp
static double CnK(int n, int k)
```

1.3. _FiguresSum_ вычисление суммы цифр в числе. Число должно быть от 0 до 999.999.999

Синтаксис:

```cpp
static long int FiguresSum(long int)
```

1.4. _ToString_ вещественное число превращает в строку с заданным десятичным разделителем

Синтаксис:

```cpp
static std::string ToString(double Value, char Separator)
```

1.5. _CRC32_ перегруженный метод расчета контрольной суммы буфера Buf длиной Len по алгоритму CRC32

Синтаксис:

```cpp
static unsigned int CRC32(unsigned char *Buf, unsigned int Len)
```

1.6. _CRC32_ перегруженный метод расчета контрольной суммы строки по алгоритму CRC32

Синтаксис:

```cpp
static unsigned int CRC32(std::string Value)
```

1.7. _IntToBin_ конвертирует целое десятичное число в двоичное число

Работает с числами разрядности от 1 до 64 включительно.

На вход подаются: само число, количество разрядов в двоичной записи.

Синтаксис:

```cpp
static std::string IntToBin(long long int Value, int Digits)
```

1.8. _BinToInt_ конвертирует двоичное число в целое десятичное

Работает с числами разрядности от 1 до 64 включительно.

Синтаксис:

```cpp
static long long int BinToInt(std::string Value)
```

1.9. _BinToHex_ конвертирует двоичное число в шестнадцатеричное число

Синтаксис:

```cpp
static std::string BinToHex(std::string Value)
```

1.10. _GradToString_ переводит градусы типа double в строку вида: гг° мм' сс"

Синтаксис:

```cpp
static std::string GradToString(double Value);
```

1.11. _HexToBin_ конвертирует шестнадцатеричное число в двоичное число

Синтаксис:

```cpp
static std::string HexToBin(std::string Value)
```

---

### 2. TNumber

#### Публичные методы

2.1. _Empty_ инициализирует число нулями и устанавливает 8-разрядную сетку

Синтаксис:

```cpp
void Empty(void)
```

2.2. _GetSomeBits_ возвращает выбранный пользователем битовый массив (часть битов) из числа

На вход подаются старший и младший биты. Биты нумеруются справа-налево.

Например, число 123 (десятичное) в двоичной 8-разрядной форме

```
имеет вид 01111011
          76543210 - номера битов
```

GetSomeBits(5,3) вернёт 111 (двоичное), то есть 7 (десятичное).

Синтаксис:

```cpp
std::string GetSomeBits(int MaxBit, int MinBit)
```

2.3. _SetSize_ задаёт разрядность числа (от 1 до 64 включительно)

По умолчанию 8-разрядное.

Синтаксис:

```cpp
void SetSize(int Value)
```

2.4. _GetSize_ прочитать разрядность числа

Синтаксис:

```cpp
int GetSize(void)
```

2.5. _SetAsInt_ задать число в десятичной системе счисления

Синтаксис:

```cpp
void SetAsInt(long long int Value)
```

2.6. _GetAsInt_ прочитать число в десятичной системе счисления

Синтаксис:

```cpp
long long int GetAsInt(void)
```

2.7. _SetAsBin_ задать число в двоичной системе счисления

Синтаксис:

```cpp
void SetAsBin(std::string Value)
```

2.8. _GetAsBin_ прочитать число в двоичной системе счисления

Синтаксис:

```cpp
std::string GetAsBin(void)
```

2.9. _SetAsHex_ задать число в шестнадцатеричной системе счисления

Синтаксис:

```cpp
void SetAsHex(std::string Value)
```

2.10. _GetAsHex_ прочитать число в шестнадцатеричной системе счисления

Синтаксис:

```cpp
std::string GetAsHex(void)
```
