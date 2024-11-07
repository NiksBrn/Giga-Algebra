#include "../../headers/Overload.h"

#include <sstream>

std::ostream& operator<<(std::ostream& os, const NaturalNumber& num) {
  std::string str;
  Node* tmp = num.get_num().get_first();
  while (tmp != nullptr) {
    str += std::to_string(tmp->value);
    tmp = tmp->next;
  }
  reverse(str.begin(), str.end());
  return os << str;
}

std::ostream& operator<<(std::ostream& os, const IntegerNumber& num) {
  if (num.POZ_Z_D() != POSITIVE) {
    return os << "-" << num.get_num();
  }
  return os << num.get_num();
}

std::ostream& operator<<(std::ostream& os, const RationalNumber& num) {
  return os << num.getNumerator() << "/" << num.getDenominator();
}

std::ostream& operator<<(std::ostream& os, const Polynomial& num) {}