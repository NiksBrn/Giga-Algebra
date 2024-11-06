#include "../../headers/IntegerNumber.h"

IntegerNumber::IntegerNumber(char sign, std::string s) : NaturalNumber(s) {
    sign == '-' ? isNegative = true : isNegative = false;
}

Sign IntegerNumber::POZ_Z_D() const {
  if (isNegative) {
    return NEGATIVE;
  } else
    return POSITIVE;  // TODO ZERO
}

NaturalNumber &IntegerNumber::TRANS_Z_N(){
  return *dynamic_cast<NaturalNumber *>(this);
}