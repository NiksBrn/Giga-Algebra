#include "../../headers/IntegerNumber.h"

IntegerNumber::IntegerNumber(char sign, std::string s) : NaturalNumber(s) {
  sign == '-' ? isNegative = true : isNegative = false;
}