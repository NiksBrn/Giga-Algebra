#include "../../headers/IntegerNumber.h"

Sign IntegerNumber::POZ_Z_D() const {
  if (isNegative) {
    return NEGATIVE;
  } else
    return POSITIVE;  // TODO ZERO
}

NaturalNumber &IntegerNumber::TRANS_Z_N(){
  return *dynamic_cast<NaturalNumber *>(this);
}