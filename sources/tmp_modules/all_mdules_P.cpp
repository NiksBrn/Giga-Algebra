#include "../../headers/Polynomial.h"

Polynomial Polynomial::ADD_PP_P(const Polynomial& other) {
  ListPolynomial* newPol = new ListPolynomial();
  NodePolynomial* tmp1 = polynomial->get_tail();
  NodePolynomial* tmp2 = other.polynomial->get_tail();
  while (tmp1 != nullptr && tmp2 != nullptr) {
    if (tmp1->degree == tmp2->degree) {
      newPol->push(tmp1->coefficient.ADD_QQ_Q(tmp2->coefficient), tmp1->degree);
    } else {
      newPol->push(tmp1->coefficient, tmp1->degree);
      newPol->push(tmp2->coefficient, tmp2->degree);
    }
    tmp1 = tmp1->prev;
    tmp2 = tmp2->prev;
  }
  while (tmp1 != nullptr) {
    newPol->push(tmp1->coefficient, tmp1->degree);
    tmp1 = tmp1->prev;
  }
  while (tmp2 != nullptr) {
    newPol->push(tmp2->coefficient, tmp2->degree);
    tmp2 = tmp2->prev;
  }
  Polynomial newPolynomial(newPol);
  newPolynomial.polynomial->balance();
  return newPolynomial;
}

Polynomial Polynomial::SUB_PP_P(const Polynomial& other) {
  ListPolynomial* newPol = new ListPolynomial();
  NodePolynomial* tmp1 = polynomial->get_tail();
  NodePolynomial* tmp2 = other.polynomial->get_tail();
  RationalNumber reverse('-', "1", "1");
  while (tmp1 != nullptr && tmp2 != nullptr) {
    if (tmp1->degree == tmp2->degree) {
      newPol->push(tmp1->coefficient.SUB_QQ_Q(tmp2->coefficient), tmp1->degree);
    } else {
      // auto neg_coeff1 = tmp1->coefficient.MUL_QQ_Q(reverse);
      newPol->push(tmp1->coefficient, tmp1->degree);
      newPol->push(tmp2->coefficient.MUL_QQ_Q(reverse), tmp2->degree);
    }
    tmp1 = tmp1->prev;
    tmp2 = tmp2->prev;
  }
  while (tmp1 != nullptr) {
    newPol->push(tmp1->coefficient, tmp1->degree);
    tmp1 = tmp1->prev;
  }
  while (tmp2 != nullptr) {
    newPol->push(tmp2->coefficient.MUL_QQ_Q(reverse), tmp2->degree);
    tmp2 = tmp2->prev;
  }
  Polynomial newPolynomial(newPol);
  newPolynomial.polynomial->balance();
  return newPolynomial;
}

Polynomial Polynomial::MUL_PQ_P(const RationalNumber& other) {
  ListPolynomial* newPol = new ListPolynomial();
  NodePolynomial* tmp = polynomial->get_tail();
  while (tmp != nullptr) {
    newPol->push(tmp->coefficient.MUL_QQ_Q((RationalNumber&)other),
                 tmp->degree);
    tmp = tmp->prev;
  }
  Polynomial newPolynomial(newPol);
  newPolynomial.polynomial->balance();
  return newPolynomial;
}

Polynomial Polynomial::MUL_Pxk_P(const NaturalNumber& other) {
  ListPolynomial* newPol = new ListPolynomial();
  NodePolynomial* tmp = polynomial->get_tail();
  while (tmp != nullptr) {
    newPol->push(tmp->coefficient, tmp->degree.ADD_NN_N(other));
    tmp = tmp->prev;
  }
  Polynomial newPolynomial(newPol);
  newPolynomial.polynomial->balance();
  return newPolynomial;
}

RationalNumber Polynomial::LED_P_Q() {
  NodePolynomial* tmp = polynomial->get_head();
  return tmp->coefficient;
}

RationalNumber Polynomial::FAC_P_Q() {
  NodePolynomial* tmp = polynomial->get_tail();
  NaturalNumber nok("1");
  NaturalNumber nod("1");
  if (tmp != nullptr) {
    nok = tmp->coefficient.getDenominator();
    nod = tmp->coefficient.getNumerator().ABS_Z_Z();
    tmp = tmp->prev;
  }
  while (tmp != nullptr) {
    nok = tmp->coefficient.getDenominator().LCM_NN_N(nok);
    nod = tmp->coefficient.getNumerator().ABS_Z_Z().GCF_NN_N(nod);
    tmp = tmp->prev;
  }
  IntegerNumber nok_i(nok);
  RationalNumber answer(nok_i, nod);
  return answer;
}

Polynomial Polynomial::DER_P_P() {
  ListPolynomial* newPol = new ListPolynomial();
  RationalNumber k('+', "0", "1");
  NodePolynomial* tmp = polynomial->get_tail();
  while (tmp != nullptr) {
    if (tmp->degree.COM_NN_D(NaturalNumber("0")) == Compare::EQUAL) {
      tmp = tmp->prev;
      continue;
    }
    k = RationalNumber(IntegerNumber(tmp->degree), NaturalNumber("1"));
    newPol->push(tmp->coefficient.MUL_QQ_Q(k),
                 tmp->degree.SUB_NN_N(NaturalNumber("1")));
    tmp = tmp->prev;
  }
  Polynomial newPolynomial(newPol);
  newPolynomial.polynomial->balance();
  return newPolynomial;
}

Polynomial Polynomial::MUL_PP_P(const Polynomial& other) {
  NodePolynomial* tmp = other.polynomial->get_head();
  ListPolynomial* newPol = new ListPolynomial();
  newPol->push(RationalNumber('+', "0", "1"), NaturalNumber("0"));
  Polynomial poly(newPol);
  Polynomial copy = *this;
  while (tmp != nullptr) {
    Polynomial mul = copy.MUL_PQ_P(tmp->coefficient).MUL_Pxk_P(tmp->degree);
    poly = poly.ADD_PP_P(mul);
    tmp = tmp->next;
  }
  poly.polynomial->balance();
  return poly;
}