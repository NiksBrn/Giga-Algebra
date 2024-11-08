#include "../../headers/IntegerNumber.h"

// struct start

// IntegerNumber::IntegerNumber(char sign, std::string s){
//     number = new NaturalNumber(s);
//     sign == '-' ? isNegative = true : isNegative = false;
// }

// struct end
// Sign IntegerNumber::POZ_Z_D() const {
//   if (isNegative) {
//     return NEGATIVE;
//   } else
//     return POSITIVE;  // TODO ZERO
// }

const NaturalNumber& IntegerNumber::get_num() const{
    return *number;
}

IntegerNumber IntegerNumber::TRANS_N_Z(const NaturalNumber &n) {
    return IntegerNumber(n);
}

NaturalNumber IntegerNumber::TRANS_Z_N(const IntegerNumber &n) {
    return *n.number;
}

//NaturalNumber &IntegerNumber::TRANS_Z_N(){
//  return *dynamic_cast<NaturalNumber *>(this);
//}