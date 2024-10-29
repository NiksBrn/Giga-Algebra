#ifndef GIGA_ALGEBRA_NATURALNUMBER_H
#define GIGA_ALGEBRA_NATURALNUMBER_H

#include "Struct.h"
#include "string"
#include <algorithm>
class NaturalNumber{
public:
    explicit NaturalNumber(std::string s);
    bool operator==(const NaturalNumber& rhs) const; //COM_NN_D
    std::string NZER_N_B();//    NZER_N_B
    void ADD_1N_N();//    ADD_1N_N
    NaturalNumber operator+(const NaturalNumber& rhs) const;//    ADD_NN_N
    void SUB_NN_N(const NaturalNumber& num);//    SUB_NN_N
    NaturalNumber MUL_NN_N(char c);//    MUL_NN_N//    MUL_ND_N
    NaturalNumber MUL_Nk_N(int k);//    MUL_Nk_N
    NaturalNumber operator*(const NaturalNumber& rhs) const;//    MUL_NN_N
    void SUB_NDN_N(NaturalNumber& num, char c);//    SUB_NDN_N
    char DIV_NN_Dk(NaturalNumber& num, int k);//    DIV_NN_Dk
    NaturalNumber DIV_NN_N(NaturalNumber& num);//    DIV_NN_N
    NaturalNumber MOD_NN_N(NaturalNumber& num);//    MOD_NN_N
    NaturalNumber GCF_NN_N(NaturalNumber* arr_num);//  GCF_NN_N
    NaturalNumber LCM_NN_N(NaturalNumber* arr_num);//  LCM_NN_N
    List get_num() const;
    void clear();
private:
    List Big_int;
};


#endif //GIGA_ALGEBRA_NATURALNUMBER_H
