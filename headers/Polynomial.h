#ifndef GIGA_ALGEBRA_POLYNOMIAL_H
#define GIGA_ALGEBRA_POLYNOMIAL_H

#include <string>
#include <vector>

#include "RationalNumber.h"
#include "Struct.h"

class Polynomial {
 public:
  Polynomial(NaturalNumber degree, std::vector<RationalNumber> coeffs)
      : degree(degree), coeffs(coeffs) {}

  Polynomial &ADD_PP_P(const Polynomial &other);
  Polynomial &operator+(const Polynomial &other);
  Polynomial &operator+=(const Polynomial &other);

  Polynomial &SUB_PP_P(const Polynomial &other);
  Polynomial &operator-(const Polynomial &other);
  Polynomial &operator-=(const Polynomial &other);

  Polynomial &MUL_PQ_P(const RationalNumber &other);
  Polynomial operator*(const RationalNumber &other);
  Polynomial &operator*=(const RationalNumber &other);

  Polynomial &MUL_Pxk_P(const NaturalNumber &other);  // умножение на x^k
  Polynomial operator*(const NaturalNumber &other);
  Polynomial &operator*=(const NaturalNumber &other);

  RationalNumber &LED_P_Q();

  NaturalNumber &DEG_P_N() { return degree; }

  RationalNumber &FAC_P_Q();

  Polynomial &MUL_PP_P(const Polynomial &other);
  Polynomial &operator*(const Polynomial &other);
  Polynomial &operator*=(const Polynomial &other);

  Polynomial &DIV_PP_P(const Polynomial &other);
  Polynomial operator/(const Polynomial &other);
  Polynomial &operator/=(const Polynomial &other);

  Polynomial &MOD_PP_P(const Polynomial &other);
  Polynomial &operator%(const Polynomial &other);
  Polynomial &operator%=(const Polynomial &other);

  Polynomial &GCF_PP_P(const Polynomial &other);

  Polynomial &DER_P_P();

  Polynomial &NMR_P_P();

 private:
  std::vector<RationalNumber> coeffs;
  NaturalNumber degree;
};

#endif  // GIGA_ALGEBRA_POLYNOMIAL_H
