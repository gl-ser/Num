//----------------------------------------------------------------------------//
//               *** ЦЕЛОЕ ЧИСЛО В РАЗНЫХ СИСТЕМАХ СЧИСЛЕНИЯ ***              //
//                                                                            //
// Файл Number.cpp                                                            //
//                                                                            //
// Автор ГЛУЩЕНКО Сергей                                                      //
//                                                                            //
//                                                                     Москва //
//----------------------------------------------------------------------------//


#include "Number.h"


TNumber::TNumber()
{
  Empty();
}


TNumber::~TNumber()
{
  Size = 0;
  Data = 0;
}


void TNumber::Empty()
{
  Size = 8;
  Data = 0;
}


std::string TNumber::GetSomeBits(int MaxBit, int MinBit)
{
int i;
std::string str1, str2, str3;
bool ok;
  ok = true;

  if (MaxBit < MinBit) ok = false;

  if ((MaxBit < 0) || (MaxBit > Size - 1)) ok = false;

  if ((MinBit < 0) || (MinBit > Size - 1)) ok = false;

  if (!ok)
  {
    return "";
  }

  str1 = GetAsBin();

  str2 = "";
  for(i=static_cast<int>(str1.length()-1);i>=0;i--)
    str2 = str2 + str1[static_cast<unsigned int>(i)];

  str3 = "";
  for(i=MinBit;i<=MaxBit;i++)
    str3 = str3 + str2[static_cast<unsigned int>(i)];

  str2 = "";
  for(i=static_cast<int>(str3.length()-1);i>=0;i--)
    str2 = str2 + str3[static_cast<unsigned int>(i)];

  return str2;
}


void TNumber::SetSize(int Value)
{
  if ((Value >= 1) && (Value <= 64))
  {
    Size = Value;
  }
}


int TNumber::GetSize()
{
  return Size;
}


void TNumber::SetAsInt(long long int Value)
{
  Data = Value;
}


long long int TNumber::GetAsInt()
{
  return Data;
}


void TNumber::SetAsBin(std::string Value)
{
  Data = TNumerical::BinToInt(Value);
}


std::string TNumber::GetAsBin()
{
  return TNumerical::IntToBin(Data, Size);
}


void TNumber::SetAsHex(std::string Value)
{
  Data = TNumerical::BinToInt(TNumerical::HexToBin(Value));
}


std::string TNumber::GetAsHex()
{
  return TNumerical::BinToHex(TNumerical::IntToBin(Data, Size));
}
