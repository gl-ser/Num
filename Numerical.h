//----------------------------------------------------------------------------//
//           *** КЛАСС СТАТИЧЕСКИХ МЕТОДОВ МАНИПУЛЯЦИИ С ЧИСЛАМИ ***          //
//                                                                            //
// Файл Numerical.h                                                           //
//                                                                            //
// Автор ГЛУЩЕНКО Сергей                                                      //
//                                                                            //
//                                                                     Москва //
//----------------------------------------------------------------------------//


#ifndef NumericalH
#define NumericalH

#include <string>
#include <math.h>


class TNumerical
{
  private:
    //Внутрення функция для вычисления суммы цифр числа
    static int FiguresSumRecursive(long int n);

    //Дробная часть от деления A/B
    static int Mod(int A, int B);

    //Возвращает знак вещественного числа
    static int Sign(double Value);

    //Возвращает целую часть числа.
    //Число Value должно быть таким, чтобы по размерности его целая часть могла быть сохранена в типе int
    static int Trunc(double Value);

  public:
    TNumerical(void);
    virtual ~TNumerical(void);

    //Расчет контрольной суммы буфера Buf длиной Len по алгоритму CRC32
    static unsigned int CRC32(unsigned char *Buf, unsigned int Len);

    //Расчет контрольной суммы строки по алгоритму CRC32
    static unsigned int CRC32(std::string Value);

    //Вычисление факториала числа (рекурсивная функция)
    static double Factorial(int n);

    //Комбинаторное число сочетаний "'це' из 'эн' по 'ка'"
    static double CnK(int n, int k);

    //Вычисление суммы цифр в числе. Число должно быть от 0 до 999.999.999
    static long int FiguresSum(long int);

    //Вещественное число превращает в строку с заданным десятичным разделителем
    static std::string ToString(double Value, char Separator);

    //Конвертирует целое десятичное число в двоичное число
    // Работает с числами разрядности от 1 до 64 включительно
    // На вход подаются: само число, количество разрядов в двоичной записи
    static std::string IntToBin(long long int Value, int Digits);

    //Конвертирует двоичное число в целое десятичное
    // Работает с числами разрядности от 1 до 64 включительно
    static long long int BinToInt(std::string Value);

    //Конвертирует двоичное число в шестнадцатеричное число
    static std::string BinToHex(std::string Value);

    //Конвертирует шестнадцатеричное число в двоичное число
    static std::string HexToBin(std::string Value);

    //Переводит градусы типа double в строку вида: гг° мм' сс"
    static std::string GradToString(double Value);
};


#endif
