#include "../../headers/Polynomial.h"

Polynomial &Polynomial::ADD_PP_P(const Polynomial &other){
  ListPolynomial* newPol = new ListPolynomial();
  NodePolynomial* tmp1 = polynomial->get_tail();
  NodePolynomial* tmp2 = other.polynomial->get_tail();
  while (tmp1 != nullptr && tmp2 != nullptr){
    newPol->push(tmp1->coefficient.ADD_QQ_Q(tmp2->coefficient), tmp1->degree);
    tmp1 = tmp1->prev;
    tmp2 = tmp2->prev;
  }
  while(tmp1 != nullptr) {
    newPol->push(tmp1->coefficient, tmp1->degree);
  }
  while(tmp2 != nullptr) {
    newPol->push(tmp2->coefficient, tmp2->degree);
  }
  Polynomial newPolynomial(newPol);
  return newPolynomial;
}

Polynomial &Polynomial::SUB_PP_P(const Polynomial &other){
  ListPolynomial* newPol = new ListPolynomial();
  NodePolynomial* tmp1 = polynomial->get_tail();
  NodePolynomial* tmp2 = other.polynomial->get_tail();
  while (tmp1 != nullptr && tmp2 != nullptr){
    newPol->push(tmp1->coefficient.SUB_QQ_Q(tmp2->coefficient), tmp1->degree);
    tmp1 = tmp1->prev;
    tmp2 = tmp2->prev;
  }
  while(tmp1 != nullptr) {
    newPol->push(tmp1->coefficient, tmp1->degree);
  }
  while(tmp2 != nullptr) {
    newPol->push(tmp2->coefficient, tmp2->degree);
  }
  Polynomial newPolynomial(newPol);
  return newPolynomial;
}

Polynomial &Polynomial::MUL_PQ_P(const RationalNumber &other){
  ListPolynomial* newPol = new ListPolynomial();
  NodePolynomial* tmp = polynomial->get_tail();
  while (tmp != nullptr){
    newPol->push(tmp->coefficient.MUL_QQ_Q((RationalNumber &)other), tmp->degree);
    tmp = tmp->prev;
  }
  Polynomial newPolynomial(newPol);
  return newPolynomial;
}

Polynomial &Polynomial::MUL_Pxk_P(const NaturalNumber &other){
  ListPolynomial* newPol = new ListPolynomial();
  NodePolynomial* tmp = polynomial->get_tail();
  while (tmp != nullptr){
    newPol->push(tmp->coefficient, tmp->degree.ADD_NN_N(other));
    tmp = tmp->prev;
  }
  Polynomial newPolynomial(newPol);
  return newPolynomial;
}

RationalNumber &Polynomial::LED_P_Q(){
  NodePolynomial* tmp = polynomial->get_head();
  return tmp->coefficient;
}

NaturalNumber &Polynomial::DEG_P_N(){
  NodePolynomial* tmp = polynomial->get_head();
  return tmp->degree;
}

RationalNumber &Polynomial::FAC_P_Q(){
  NodePolynomial* tmp = polynomial->get_tail();
  NaturalNumber nok("1");
  NaturalNumber nod("1");
  while (tmp != nullptr){
    nok = tmp->coefficient.getDenominator().LCM_NN_N(nok);
    nod = tmp->coefficient.getNumerator().ABS_Z_Z().LCM_NN_N(nod);
    tmp = tmp->prev;
  }
  IntegerNumber nok_i(nok);
  RationalNumber answer(nok_i, nod);
  return answer;
}

Polynomial &Polynomial::DER_P_P(){
  ListPolynomial* newPol = new ListPolynomial();
  RationalNumber k('+', "0", "1");
  NodePolynomial* tmp = polynomial->get_tail();
  while(tmp != nullptr) {
    if (tmp->degree.COM_NN_D(NaturalNumber("0")) == Compare::EQUAL) {
      continue;
    }
    k = RationalNumber(IntegerNumber(tmp->degree), NaturalNumber("1"));
    newPol->push(tmp->coefficient.MUL_QQ_Q(k), tmp->degree.SUB_NN_N(NaturalNumber("1")));
  }
  Polynomial newPolynomial(newPol);
  return newPolynomial;
}

Polynomial &Polynomial::MUL_PP_P(const Polynomial &other){
  ListPolynomial* intermediate = new ListPolynomial();
  NaturalNumber maxDegree("0");
  NodePolynomial* tmp1 = polynomial->get_tail();
  NodePolynomial* tmp2 = other.polynomial->get_tail();
  while (tmp1 != nullptr){
    while(tmp2 != nullptr){
      intermediate->push(tmp1->coefficient.MUL_QQ_Q(tmp2->coefficient), tmp1->degree.ADD_NN_N(tmp2->degree));
      if (maxDegree.COM_NN_D(tmp1->degree.ADD_NN_N(tmp2->degree)) == Compare::LESS) {
        maxDegree = NaturalNumber(tmp1->degree.ADD_NN_N(tmp2->degree));
      }
      tmp2 = tmp2->prev;
    }
    tmp2 = other.polynomial->get_tail();
    tmp1 = tmp1->prev;
  }
  IntegerNumber newco_i('+', "0");
  RationalNumber newCo(newco_i);
  NodePolynomial* tmp3 = intermediate->get_tail();
  ListPolynomial* newPol;
  while (maxDegree.COM_NN_D(NaturalNumber("0"))){
    while(tmp3 != nullptr) {
      if (tmp3->degree.COM_NN_D(maxDegree) == Compare::EQUAL) {
        newCo = newCo.ADD_QQ_Q(tmp3->coefficient);
      }
    }
    newPol->push(newCo, maxDegree);
    newCo = RationalNumber(newco_i);
    maxDegree.SUB_NN_N(NaturalNumber("1"));
  }
  while(tmp3 != nullptr) {
    if (tmp3->degree.COM_NN_D(maxDegree) == Compare::EQUAL) {
      newCo = newCo.ADD_QQ_Q(tmp3->coefficient);
    }
  }
  newPol->push(newCo, maxDegree);
  newCo = RationalNumber(newco_i);
  maxDegree.SUB_NN_N(NaturalNumber("1"));
  Polynomial newPolynomial(newPol);
  return newPolynomial;
}