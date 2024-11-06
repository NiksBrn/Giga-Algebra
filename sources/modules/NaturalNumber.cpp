#include "../../headers/NaturalNumber.h"

//struct start

NaturalNumber::NaturalNumber(std::string s) {
    for(int i = s.size() - 1; i >=0; i--) {
        Big_int.push_back(s[i] - '0');
    }
}

List NaturalNumber::get_num() const{
    return Big_int;
}

void NaturalNumber::clear(){
    Big_int.clear();
}

//struct end
