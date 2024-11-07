#include "../../headers/NaturalNumber.h"

// struct start

NaturalNumber::NaturalNumber() { Big_int = new List(); }

NaturalNumber::NaturalNumber(std::string s) {
  Big_int = new List();
  for (int i = s.size() - 1; i >= 0; i--) {
    Big_int->push_back(s[i] - '0');
  }
}

NaturalNumber::NaturalNumber(const NaturalNumber& other) {
  Big_int = new List(other.get_num());
}

NaturalNumber NaturalNumber::operator=(const NaturalNumber& other) {
  Big_int = new List(other.get_num());
  return *this;
}

List& NaturalNumber::get_num() const { return *Big_int; }

void NaturalNumber::clear() {
  Big_int->clear();
  delete Big_int;
}

// struct end
