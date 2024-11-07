#include "../../headers/IntegerNumber.h"

IntegerNumber::IntegerNumber(char sign, std::string s) {
  isNegative = sign == '-' ? true : false;
  number = new NaturalNumber(s);
}

IntegerNumber::IntegerNumber(const NaturalNumber &n) {
  isNegative = false;
  number = new NaturalNumber(n);
};

NaturalNumber &IntegerNumber::ABS_Z_Z() { return *number; }

Sign IntegerNumber::POZ_Z_D() const {
  if (*number == NaturalNumber("0")) return Sign::ZERO;
  return isNegative ? Sign::NEGATIVE : Sign::POSITIVE;
}

IntegerNumber &IntegerNumber::MUL_ZM_Z() { isNegative = !isNegative; }

IntegerNumber IntegerNumber::TRANS_N_Z(const NaturalNumber &n) {
  *this = IntegerNumber(n);
  return *this;
}

NaturalNumber IntegerNumber::TRANS_Z_N() { return *number; }

IntegerNumber IntegerNumber::ADD_ZZ_Z(const IntegerNumber &other) {
  // auto object = *this;
  // if (POZ_Z_D() == other.POZ_Z_D()) {
  //   object.number = number->ADD_NN_N(other.number);
  //   return object;
  // }
  // if (number < other.number) {
  //   auto other_number = other.number;
  //   object.number = other_number->SUB_NN_N(number);
  //   isNegative = other.isNegative;
  // } else {
  //   object.number = number->SUB_NN_N(other.number);
  // }
  // return object;
}

IntegerNumber IntegerNumber::operator+(const IntegerNumber &other) {
  auto object = *this;
  return object.ADD_ZZ_Z(other);
}

IntegerNumber &IntegerNumber::operator+=(const IntegerNumber &other) {
  *this = ADD_ZZ_Z(other);
  return *this;
}

IntegerNumber IntegerNumber::SUB_ZZ_Z(const IntegerNumber &other) {
  auto object = other;
  object.isNegative = !object.isNegative;
  return ADD_ZZ_Z(other);
}

IntegerNumber IntegerNumber::operator-(const IntegerNumber &other) {
  auto object = *this;
  return object.SUB_ZZ_Z(other);
}

IntegerNumber &IntegerNumber::operator-=(const IntegerNumber &other) {
  *this = SUB_ZZ_Z(other);
  return *this;
}

// IntegerNumber IntegerNumber::MUL_ZZ_Z(const IntegerNumber &other) {
  // auto object = *this;
  // object.number = number->MUL_NN_N(other.number);
  // object.isNegative == other.isNegative ? object.isNegative = false : true;
  // return object;
// }

// IntegerNumber IntegerNumber::operator*(const IntegerNumber &other) {
//   auto object = *this;
//   return object.MUL_ZZ_Z(other);
// }

// IntegerNumber &IntegerNumber::operator*=(const IntegerNumber &other) {
//   *this = MUL_ZZ_Z(other);
//   return *this;
// }

// IntegerNumber IntegerNumber::DIV_ZZ_Z(const IntegerNumber &other) {
  // auto object = *this;
  // object.number = number.DIV_NN_N(other.number);
  // object.isNegative == other.isNegative ? object.isNegative = false : true;
  // return object;
// }

// IntegerNumber IntegerNumber::operator/(const IntegerNumber &other) {
//   auto object = *this;
//   return object.DIV_ZZ_Z(other);
// }

// IntegerNumber &IntegerNumber::operator/=(const IntegerNumber &other) {
//   *this = DIV_ZZ_Z(other);
//   return *this;
// }

// IntegerNumber IntegerNumber::MOD_ZZ_Z(const IntegerNumber &other) {}

// IntegerNumber IntegerNumber::operator%(const IntegerNumber &other) {}

// IntegerNumber &IntegerNumber::operator%=(const IntegerNumber &other) {}