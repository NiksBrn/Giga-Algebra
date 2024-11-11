// project Giga-Algebra
// Developers: Kantserov Artemii
// Debuggers: Alexander Galkin, Nikita Skobelev

#include "../../headers/RationalNumber.h"

//struct start

RationalNumber::RationalNumber(const RationalNumber &other){
    numerator = new IntegerNumber(*other.numerator);
    denominator = new NaturalNumber(*other.denominator);
}

RationalNumber& RationalNumber::operator=(const RationalNumber& other){
    numerator = new IntegerNumber(*other.numerator);
    denominator = new NaturalNumber(*other.denominator);
    return *this;
}

//struct end