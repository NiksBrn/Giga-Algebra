#ifndef GIGA_ALGEBRA_INTEGERNUMBER_H
#define GIGA_ALGEBRA_INTEGERNUMBER_H

#include <string>

#include "NaturalNumber.h"
#include "Struct.h"

enum Sign { ZERO = 0, POSITIVE = 1, NEGATIVE = -1 };

class IntegerNumber {
 public:
  IntegerNumber() = default;

  IntegerNumber(char sign, std::string s);

  IntegerNumber(const IntegerNumber &other);

  IntegerNumber &operator=(const IntegerNumber &other);

  explicit IntegerNumber(const NaturalNumber &n);  // TRANS_Z_N

  NaturalNumber &ABS_Z_Z();  // Absolute value

  Sign POZ_Z_D() const;  // Sign

  IntegerNumber &MUL_ZM_Z();  // Z * (-1)

  static IntegerNumber TRANS_N_Z(const NaturalNumber &n);  // N -> Z

  static NaturalNumber TRANS_Z_N(const IntegerNumber& n);  // Z -> N

  IntegerNumber ADD_ZZ_Z(const IntegerNumber &other);  // Z + Z
  IntegerNumber operator+(const IntegerNumber &other);
  IntegerNumber &operator+=(const IntegerNumber &other);

  IntegerNumber SUB_ZZ_Z(const IntegerNumber &other);  // Z - Z
  IntegerNumber operator-(const IntegerNumber &other);
  IntegerNumber &operator-=(const IntegerNumber &other);

  IntegerNumber MUL_ZZ_Z(const IntegerNumber &other);  // Z * Z
  IntegerNumber operator*(const IntegerNumber &other);
  IntegerNumber &operator*=(const IntegerNumber &other);

  IntegerNumber DIV_ZZ_Z(const IntegerNumber &other);  // Z / Z
  IntegerNumber operator/(const IntegerNumber &other);
  IntegerNumber &operator/=(const IntegerNumber &other);

  IntegerNumber MOD_ZZ_Z(const IntegerNumber &other);  // Z % Z
  IntegerNumber operator%(const IntegerNumber &other);
  IntegerNumber &operator%=(const IntegerNumber &other);

  const NaturalNumber &get_num() const;

  void clear() {
    number->clear();
    delete number;
  }

 protected:
  bool isNegative;  // '+' or '-'
  NaturalNumber *number;
};

constexpr const char* SignToString(Sign sgn) noexcept {
    switch (sgn) {
    case ZERO:
        return "ZERO";
    case POSITIVE:
        return "POSITIVE";
    case NEGATIVE:
        return "NEGATIVE";
    }
    return "ERROR";
}

#endif  // GIGA_ALGEBRA_POLYNOMIAL_H
