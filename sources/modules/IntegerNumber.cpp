#include "../../headers/IntegerNumber.h"

// struct start

IntegerNumber::IntegerNumber(char sign, std::string s){
    number = NaturalNumber(s);
    sign == '-' ? isNegative = true : isNegative = false;
}

// struct end
Sign IntegerNumber::POZ_Z_D() const {
  if (isNegative) {
    return NEGATIVE;
  } else
    return POSITIVE;  // TODO ZERO
}

const NaturalNumber& IntegerNumber::get_num() const{
    return number;
}

//NaturalNumber &IntegerNumber::TRANS_Z_N(){
//  return *dynamic_cast<NaturalNumber *>(this);
//}