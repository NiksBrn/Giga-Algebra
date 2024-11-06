#ifndef GIGA_ALGEBRA_INTEGERNUMBER_H
#define GIGA_ALGEBRA_INTEGERNUMBER_H

#include <string>

#include "NaturalNumber.h"
#include "Struct.h"

enum Sign { ZERO = 0, POSITIVE = 1, NEGATIVE = -1 };

class IntegerNumber{
 public:
  IntegerNumber(char sign, std::string s);

  explicit IntegerNumber(const NaturalNumber &n);  // TRANS_Z_N

  NaturalNumber &ABS_Z_Z();  // Absolute value

  Sign POZ_Z_D() const;  // Sign

  IntegerNumber &MUL_ZM_Z();  // Z * (-1)

  IntegerNumber &TRANS_N_Z();  // N -> Z

  NaturalNumber &TRANS_Z_N();  // Z -> N

  IntegerNumber &ADD_ZZ_Z(const IntegerNumber &other);  // Z + Z
  IntegerNumber &operator+(const IntegerNumber &other) const;
  IntegerNumber &operator+=(const IntegerNumber &other) const;

  IntegerNumber &SUB_ZZ_Z(const IntegerNumber &other);  // Z - Z
  IntegerNumber &operator-(const IntegerNumber &other) const;
  IntegerNumber &operator-=(const IntegerNumber &other) const;

  IntegerNumber &MUL_ZZ_Z(const IntegerNumber &other);  // Z * Z
  IntegerNumber &operator*(const IntegerNumber &other) const;
  IntegerNumber &operator*=(const IntegerNumber &other) const;

  IntegerNumber &DIV_ZZ_Z(const IntegerNumber &other);  // Z / Z
  IntegerNumber &operator/(const IntegerNumber &other) const;
  IntegerNumber &operator/=(const IntegerNumber &other) const;

  IntegerNumber &MOD_ZZ_Z(const IntegerNumber &other);  // Z % Z
  IntegerNumber &operator%(const IntegerNumber &other) const;
  IntegerNumber &operator%=(const IntegerNumber &other) const;

  const NaturalNumber& get_num() const;

  void clear(){number.clear();};

 protected:
  bool isNegative;  // '+' or '-'
  NaturalNumber number;
};

#endif  // GIGA_ALGEBRA_POLYNOMIAL_H