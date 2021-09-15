//----------------------------------------------------------------------------//
//           *** КЛАСС СТАТИЧЕСКИХ МЕТОДОВ МАНИПУЛЯЦИИ С ЧИСЛАМИ ***          //
//                                                                            //
// Файл Numerical.cpp                                                         //
//                                                                            //
// Автор ГЛУЩЕНКО Сергей                                                      //
//                                                                            //
//                                                                     Москва //
//----------------------------------------------------------------------------//


#include "Numerical.h"


TNumerical::TNumerical()
{
  //Пустой конструктор
}


TNumerical::~TNumerical()
{
  //Пустой деструктор
}


std::string TNumerical::IntToBin(long long int Value, int Digits)
{
int i;
std::string res;
  res = "";
  for(i=0;i<=Digits-1;i++)
  {
    if ((Value & (static_cast<long long int>(1) << static_cast<long long int>(i))) > 0)
      res = "1"+res;
    else
      res = "0"+res;
  }
  return res;
}


long long int TNumerical::BinToInt(std::string Value)
{
long long int i, iValueSize, res;
  res = 0;
  iValueSize = static_cast<long long int>(Value.length());
  for(i=iValueSize-1;i>=0;i--)
  {
    if (Value[static_cast<unsigned int>(i)] == '1')
      res = res + (static_cast<long long int>(1) << (static_cast<long long int>(iValueSize)-
                                                     static_cast<long long int>(i)-static_cast<long long int>(1)));
  }
  return res;
}


std::string TNumerical::BinToHex(std::string Value)
{
std::string res, dummy, HexNumb[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};
int i, l, n, q;
  res = "";
  l = 0;
  q = static_cast<int>(Value.length());
  if (q < 4)
  {
    switch (q)
    {
      case 0:
        Value = "0000" + Value;
      break;
      case 1:
        Value = "000" + Value;
      break;
      case 2:
        Value = "00" + Value;
      break;
      case 3:
        Value = "0" + Value;
      break;
    }
    q = static_cast<int>(Value.length());
  }
  //Если входная строка по длине меньше 4-х символов, тогда дополняю её нулями слева до 4-х символов

  n = static_cast<int>(fmod(q, 4));
  if (n != 0)
  {
    switch (n)
    {
      case 1:
        Value = "000" + Value;
      break;
      case 2:
        Value = "00" + Value;
      break;
      case 3:
        Value = "0" + Value;
      break;
    }
    q = static_cast<int>(Value.length());
  }
  //Если длина входной строки не кратна 4-м, тогда дополняю её слева нулями до кратности 4-м

  //На входе в этот цикл длина Value всегда больше или равна 4-м и кратна 4-м
  for(i=1;i<=(q/4);i++)
  {
    dummy = "";
    dummy = dummy + Value[static_cast<unsigned int>(l)]+Value[static_cast<unsigned int>(l+1)]
            +Value[static_cast<unsigned int>(l+2)]+Value[static_cast<unsigned int>(l+3)];
    n = static_cast<int>(TNumerical::BinToInt(dummy));
    res = res + HexNumb[n];
    l = l+4;
  }
beginn:
  if ((res[0] == '0') && (res.length() > 1))
  {
    dummy = "";
    for (i=1;i<static_cast<int>(res.length());i++)
      dummy = dummy + res[static_cast<unsigned int>(i)];

    res = "";
    for (i=0;i<static_cast<int>(dummy.length());i++)
      res = res + dummy[static_cast<unsigned int>(i)];

    goto beginn;
  }
  return res;
}


std::string TNumerical::HexToBin(std::string Value)
{
std::string BCD[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
                       "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
char HexNumb[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int i, j;
std::string res;
  res = "";
  for(i=static_cast<int>(Value.length()-1);i>=0;i--)
  {
    for(j=0;j<16;j++)
    if (HexNumb[j] == Value[static_cast<unsigned int>(i)])
    {
      res = BCD[j] + res;
      break;
    }
  }
  return res;
}


std::string TNumerical::GradToString(double Value)
{
std::string result, SGrad, SMin, SSec;
double ASec;
int Grad, Min, Sec;
  Grad = TNumerical::Trunc(Value);
  Min = TNumerical::Trunc(fabs((Value - Grad)*60.0));
  ASec = fabs((Value - Grad)*60.0);
  Sec = TNumerical::Trunc(fabs((ASec - Min)*60.0));

  SGrad = std::to_string(Grad);
  SMin = std::to_string(Min);
  SSec = std::to_string(Sec);

  if (TNumerical::Sign(Grad) == 0)
  {
    SGrad = " 00";
  }

  if (TNumerical::Sign(Grad) == 1)
  {
    if (Grad < 10) SGrad = " 0" + std::to_string(Grad);
    if (Grad >= 10) SGrad = " " + std::to_string(Grad);
  }

  if (TNumerical::Sign(Grad) == -1)
  {
    if (fabs(Grad) < 10) SGrad = "-0" + std::to_string(TNumerical::Trunc(fabs(Grad)));
    if (fabs(Grad) >= 10) SGrad = "-" + std::to_string(TNumerical::Trunc(fabs(Grad)));
  }

  if (Min < 10) SMin = "0" + SMin;
  if (Sec < 10) SSec = "0" + SSec;

  result = SGrad + "° " + SMin + "' " + SSec + "\"";
  return result;
}


std::string TNumerical::ToString(double Value, char Separator)
{
std::string str1, str2;
unsigned int i, j;
  str1 = std::to_string(Value);

  for(i=0;i<str1.length();i++)
  if ((str1[i] != '0') && (str1[i] != '1') && (str1[i] != '2') && (str1[i] != '3') && (str1[i] != '4') && (str1[i] != '5') &&
      (str1[i] != '6') && (str1[i] != '7') && (str1[i] != '8') && (str1[i] != '9') && (str1[i] != '-'))
    break;

  str2 = "";
  for(j=0;j<str1.length();j++)
  {
    if (j != i)
      str2 = str2 + str1[j];
    else
      str2 = str2 + Separator;
  }
  return str2;
}


unsigned int TNumerical::CRC32(unsigned char *Buf, unsigned int Len)
{
int i;
unsigned int a=0;
unsigned long crc=0xFFFFFFFF;
  while (Len--)
  {
    crc = crc ^ (*Buf++);
    for (i = 0;i < 8;i++)
    {
      crc = crc & 0x00000001 ? ((crc >> 1) ^ 0xEDB88320) : crc >> 1;
    }
  }
  for (i = 0;i < 32;i++)
  {
    a = (a << 1) | ((crc >> i) & 0x1);
  }
  return a;
}


unsigned int TNumerical::CRC32(std::string Value)
{
  return TNumerical::CRC32((unsigned char*)Value.c_str(), Value.size());
}


int TNumerical::FiguresSumRecursive(long int n)
{
  if ((n >= 100000000)&&(n < 1000000000)) return (n+TNumerical::FiguresSum(n/100000000)-(TNumerical::FiguresSum(n/100000000)*100000000));
  if ((n >= 10000000)&&(n < 100000000)) return (n+TNumerical::FiguresSum(n/10000000)-(TNumerical::FiguresSum(n/10000000)*10000000));
  if ((n >= 1000000)&&(n < 10000000)) return (n+TNumerical::FiguresSum(n/1000000)-(TNumerical::FiguresSum(n/1000000)*1000000));
  if ((n >= 100000)&&(n < 1000000)) return (n+TNumerical::FiguresSum(n/100000)-(TNumerical::FiguresSum(n/100000)*100000));
  if ((n >= 10000)&&(n < 100000)) return (n+TNumerical::FiguresSum(n/10000)-(TNumerical::FiguresSum(n/10000)*10000));
  if ((n >= 1000)&&(n < 10000)) return (n+TNumerical::FiguresSum(n/1000)-(TNumerical::FiguresSum(n/1000)*1000));
  if ((n >= 100)&&(n < 1000)) return (n+TNumerical::FiguresSum(n/100)-(TNumerical::FiguresSum(n/100)*100));
  if ((n >= 10)&&(n < 100)) return (n+TNumerical::FiguresSum(n/10)-(TNumerical::FiguresSum(n/10)*10));
  if (n < 10) return n;

return 0;

}


int TNumerical::Trunc(double Value)
{
int res;
  try
  {
    res = 0;
    if (Value < 0.0)
    {
      res = static_cast<int>(floor(fabs(Value)));
      res = res * (-1);
    }
    else
    {
      res = static_cast<int>(floor(Value));
    }
  }
  catch(...)
  {
    res = 0;
  }
return res;
}


int TNumerical::Sign(double Value)
{
int res;
  try
  {
    res = 0;

    if (Value > 0.0)
      res = 1;

    if (Value < 0.0)
      res = -1;
  }
  catch(...)
  {
    res = 0;
  }
  return res;
}


double TNumerical::Factorial(int n)
{
  if (n == 0) return 0.0;
  if (n == 1) return 1.0;
  else return (static_cast<double>(static_cast<double>(n)*TNumerical::Factorial(n-1)));
}


double TNumerical::CnK(int n, int k)
{
double A, B, C;
  A = TNumerical::Factorial(n);
  B = TNumerical::Factorial(k);
  C = TNumerical::Factorial(n-k);
  return (A/(B*C));
}


long int TNumerical::FiguresSum(long int n)
{
long int Result, i;

  Result = n;
  if ((Result < 0) || (Result > 999999999)) return -1;
  for (i=1;i<=10;i++) Result = TNumerical::FiguresSumRecursive(Result);

return Result;
}
