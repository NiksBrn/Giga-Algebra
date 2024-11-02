#ifndef GIGA_ALGEBRA_NATURALNUMBER_H
#define GIGA_ALGEBRA_NATURALNUMBER_H

#include <algorithm>

#include "Struct.h"
#include "string"

enum Compare { EQUAL, LESS, GREATER };
// enum для сравнения EQUAL(0) - равно, LESS(1) - меньше, GREATER(2) - больше

class NaturalNumber {
 public:
  NaturalNumber() = default;
  
  explicit NaturalNumber(std::string s);

  Compare COM_NN_D(const NaturalNumber& other) const;
  // COM_NN_D - сравнение натуральных чисел

  bool operator==(const NaturalNumber& other) const;
  // COM_NN_D - сравнение натуральных чисел

  bool operator!=(const NaturalNumber& other) const;
  // COM_NN_D - сравнение натуральных чисел

  bool operator>=(const NaturalNumber& other) const;
  // COM_NN_D - сравнение натуральных чисел

  bool operator<=(const NaturalNumber& other) const;
  // COM_NN_D - сравнение натуральных чисел

  bool operator>(const NaturalNumber& other) const;
  // COM_NN_D - сравнение натуральных чисел

  bool operator<(const NaturalNumber& other) const;
  // COM_NN_D - сравнение натуральных чисел

  bool NZER_N_B();
  //    NZER_N_B - проверка на ноль

  void ADD_1N_N();
  //    ADD_1N_N - инкремент

  NaturalNumber& operator++();
  //    ADD_1N_N - инкремент

  NaturalNumber operator++(int);
  //    ADD_1N_N - инкремент

  NaturalNumber& ADD_NN_N(const NaturalNumber& other);
  //    ADD_NN_N - сложение

  NaturalNumber& operator+(const NaturalNumber& second);
  //    ADD_NN_N - переопределенный оператор

  NaturalNumber& operator+=(const NaturalNumber& other);
  //    ADD_NN_N - переопределенный оператор

  NaturalNumber& SUB_NN_N(const NaturalNumber& num);
  //    SUB_NN_N - вычитание

  NaturalNumber& operator-(const NaturalNumber& num);
  //    SUB_NN_N - переопределенный оператор

  NaturalNumber& MUL_ND_N(const char c);
  //    MUL_ND_N - умножение на цифру

  NaturalNumber& operator*(const char c);
  //    MUL_ND_N - переопределенный оператор

  NaturalNumber& operator*=(const char c);
  //    MUL_ND_N - переопределенный оператор

  NaturalNumber& MUL_Nk_N(const NaturalNumber& k);
  //    MUL_Nk_N - умножение на 10^k

  NaturalNumber& MUL_NN_N(const NaturalNumber& other);
  //    MUL_NN_N - умножение на число

  NaturalNumber& operator*(const NaturalNumber& other);
  //    MUL_NN_N - оператор умножения

  NaturalNumber& operator*=(const NaturalNumber& other);
  //    MUL_NN_N - оператор умножения

  void SUB_NDN_N(NaturalNumber& num, char c);
  //    SUB_NDN_N - Вычитание из натурального другого натурального, умноженного
  //    на цифру для случая с неотрицательным результатом

  char DIV_NN_Dk(NaturalNumber& num, int k);
  //    DIV_NN_Dk - Вычисление первой цифры деления большего натурального на
  //    меньшее, домноженное на 10^k,где k - номер позиции этой цифры (номер
  //    считается с нуля)

  NaturalNumber& DIV_NN_N(NaturalNumber& num);
  //    DIV_NN_N - Неполное частное от деления первого натурального числа на
  //    второе с остатком (делитель отличен от нуля)

  NaturalNumber& operator/(NaturalNumber& other);
  //    DIV_NN_N - переопределенный оператор

  NaturalNumber& operator/=(NaturalNumber& other);
  //    DIV_NN_N - переопределенный оператор

  NaturalNumber& MOD_NN_N(NaturalNumber& num);
  //    MOD_NN_N - остаток от деления

  NaturalNumber& operator%(NaturalNumber& other);
  //    MOD_NN_N - оператор остатка

  NaturalNumber& operator%=(NaturalNumber& other);
  //    MOD_NN_N - оператор остатка

  NaturalNumber& GCF_NN_N(NaturalNumber* arr_num);
  //  GCF_NN_N - НОД натуральных чисел

  NaturalNumber& LCM_NN_N(NaturalNumber* arr_num);
  //  LCM_NN_N - НОК натуральных чисел

  List get_num() const;

  void clear();

 protected:
  List Big_int;
};

#endif  // GIGA_ALGEBRA_NATURALNUMBER_H
