// project Giga-Algebra
// Developers: Kantserov Artemii

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
//architect Nikita Skobelev
//struct end

// Сокращение дроби
RationalNumber RationalNumber::RED_Q_Q(){
    NaturalNumber gcf_n = denominator->GCF_NN_N(numerator->ABS_Z_Z());
    IntegerNumber gcf_i(gcf_n);
    IntegerNumber reducedNumerator = numerator->DIV_ZZ_Z(gcf_i);
    NaturalNumber reducedDenominator = denominator->DIV_NN_N(gcf_n);
    RationalNumber reducedRationalNumber(reducedNumerator, reducedDenominator);
    return reducedRationalNumber;
}

// Проверка сокращенного дробного на целое, если рациональное число является целым, то «да», иначе «нет»
bool RationalNumber::INT_Q_B(){
    if (denominator->COM_NN_D(NaturalNumber("1")) == Compare::EQUAL) {
        return true;
    }
    return false;
}

// Преобразование целого в дробное
RationalNumber RationalNumber::Trans_Z_Q(IntegerNumber &z){
    RationalNumber rational(z, NaturalNumber("1"));
    return rational;
}

// Преобразование сокращенного дробного в целое (если знаменатель равен 1)
IntegerNumber RationalNumber::Trans_Q_Z(){
    if (denominator->COM_NN_D(NaturalNumber("1")) == Compare::EQUAL) {
        return *numerator;
    }
    throw "not integer";
}

// Сложение дробей
RationalNumber RationalNumber::ADD_QQ_Q(RationalNumber &other) {
    //std:: cout << *numerator << ' '<< *other.numerator << std::endl;
    NaturalNumber commonDenominator = denominator->LCM_NN_N(*other.denominator);
    NaturalNumber kn_1 = commonDenominator.DIV_NN_N(*denominator);
    NaturalNumber kn_2 = commonDenominator.DIV_NN_N(*other.denominator);
    IntegerNumber ki_1(kn_1);
    IntegerNumber ki_2(kn_2);
    IntegerNumber newNumerator = numerator->MUL_ZZ_Z(ki_1).ADD_ZZ_Z(other.numerator->MUL_ZZ_Z(ki_2));
    RationalNumber newRationalNumber(newNumerator, commonDenominator);
    return newRationalNumber;
}

// Вычитание дробей
RationalNumber RationalNumber::SUB_QQ_Q(RationalNumber &other) {
    NaturalNumber commonDenominator = denominator->LCM_NN_N(*other.denominator);
    NaturalNumber kn_1 = commonDenominator.DIV_NN_N(*denominator);
    NaturalNumber kn_2 = commonDenominator.DIV_NN_N(*other.denominator);
    IntegerNumber ki_1(kn_1);
    IntegerNumber ki_2(kn_2);
    IntegerNumber newNumerator = numerator->MUL_ZZ_Z(ki_1).SUB_ZZ_Z(other.numerator->MUL_ZZ_Z(ki_2));
    RationalNumber newRationalNumber(newNumerator, commonDenominator);
    return newRationalNumber;
}

// Умножение дробей
RationalNumber RationalNumber::MUL_QQ_Q(RationalNumber &other){
    IntegerNumber newNumerator = numerator->MUL_ZZ_Z(*other.numerator);
    NaturalNumber newDenominator = denominator->MUL_NN_N(*other.denominator);
    RationalNumber newRationalNumber(newNumerator, newDenominator);
    return newRationalNumber;
}

// Деление дробей
RationalNumber RationalNumber::DIV_QQ_Q(RationalNumber &other){
    IntegerNumber otherDenominator(*other.denominator);
    IntegerNumber newNumerator = numerator->MUL_ZZ_Z(otherDenominator);
    NaturalNumber newDenominator = denominator->MUL_NN_N(other.numerator->ABS_Z_Z());
    if (other.numerator->POZ_Z_D() == Sign::NEGATIVE){
        newNumerator.MUL_ZM_Z();
    }
    RationalNumber newRationalNumber(newNumerator, newDenominator);
    return newRationalNumber;
}