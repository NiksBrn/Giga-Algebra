#ifndef GIGA_ALGEBRA_RATIONALNUMBER_H
#define GIGA_ALGEBRA_RATIONALNUMBER_H

#include <string>

#include "IntegerNumber.h"
#include "NaturalNumber.h"
#include "Struct.h"

class RationalNumber {
 public:
  RationalNumber(char sign, std::string numerator, std::string denominator)
      : numerator(new IntegerNumber(sign, numerator)),
        denominator(new NaturalNumber(denominator)) {};

  RationalNumber(IntegerNumber numerator, NaturalNumber denominator)
      : numerator(new IntegerNumber(numerator)),
        denominator(new NaturalNumber(denominator)) {}

  explicit RationalNumber(IntegerNumber numerator)
      : numerator(new IntegerNumber(numerator)),
        denominator(new NaturalNumber("1")) {}

  RationalNumber(const RationalNumber &other );

  RationalNumber& operator=(const RationalNumber &other);

  RationalNumber &RED_Q_Q();

  bool INT_Q_B();

  RationalNumber &Trans_Z_Q(IntegerNumber &z);

  IntegerNumber &Trans_Q_Z();

  RationalNumber &ADD_QQ_Q(RationalNumber &other);
  RationalNumber &operator+(RationalNumber &other);
  RationalNumber &operator+=(RationalNumber &other);

  RationalNumber &SUB_QQ_Q(RationalNumber &other);
  RationalNumber &operator-(RationalNumber &other);
  RationalNumber &operator-=(RationalNumber &other);

  RationalNumber &MUL_QQ_Q(RationalNumber &other);
  RationalNumber &operator*(RationalNumber &other);
  RationalNumber &operator*=(RationalNumber &other);

  RationalNumber &DIV_QQ_Q(RationalNumber &other);
  RationalNumber &operator/(RationalNumber &other);
  RationalNumber &operator/=(RationalNumber &other);

  IntegerNumber &getNumerator() { return *numerator; }
  NaturalNumber &getDenominator() { return *denominator; }

  const IntegerNumber &getNumerator() const { return *numerator; }
  const NaturalNumber &getDenominator() const { return *denominator; }

 protected:
  IntegerNumber *numerator;
  NaturalNumber *denominator;
};

#endif  // GIGA_ALGEBRA_POLYNOMIAL_H