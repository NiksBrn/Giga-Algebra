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
  if (num.POZ_Z_D() != POSITIVE && num.POZ_Z_D() != ZERO) {
    return os << "-" << num.get_num();
  }
  return os << num.get_num();
}

std::ostream& operator<<(std::ostream& os, const RationalNumber& num) {
  return os << num.getNumerator() << "/" << num.getDenominator();
}

std::ostream& operator<<(std::ostream& os, const Polynomial& num) {
    std::string str;
    NodePolynomial* tmp = num.getPolynomial().get_head();
    while (tmp != nullptr) {
        if(tmp->next != nullptr)
        os << '(' <<tmp->coefficient << "x^" << tmp->degree << ')' << " + ";
        else os << '(' << tmp->coefficient << "x^" << tmp->degree << ')';
        tmp = tmp->next;
    }
    return os;
}

void WriteMD(const Polynomial &num){
    std::ofstream file("answer.md");
    NodePolynomial* tmp = num.getPolynomial().get_head();
    file << "$";
    while (tmp != nullptr) {
        if(tmp->next != nullptr)
            file << "(\\frac{" <<tmp->coefficient.getNumerator() <<"}{"<< tmp->coefficient.getDenominator()<< "}"<<"x^" << tmp->degree << ')' << " + ";
        else file << "(\\frac{" <<tmp->coefficient.getNumerator() <<"}{"<< tmp->coefficient.getDenominator()<< "}"<<"x^" << tmp->degree << ')';
        tmp = tmp->next;
    }
    file << "$";
    file.close();
}
























