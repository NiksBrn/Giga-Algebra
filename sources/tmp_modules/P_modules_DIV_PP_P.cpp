#include "../../headers/Polynomial.h"

Polynomial Polynomial::DIV_PP_P(const Polynomial& other) {
  ListPolynomial* object = new ListPolynomial();
  NaturalNumber maxDegree("0");
  Polynomial temp_poly = *this;
  NodePolynomial* tmp = other.polynomial->get_head();
  NodePolynomial* poly = temp_poly.polynomial->get_head();
  while (tmp != nullptr) {
    if (poly->degree.COM_NN_D(tmp->degree) == Compare::LESS) {
      if (poly == polynomial->get_head()) {
        object->push(RationalNumber(IntegerNumber('+', "0")),
                     NaturalNumber("0"));
      }
      return Polynomial(object);
    }
    NaturalNumber degree = poly->degree.SUB_NN_N(tmp->degree);
    RationalNumber coefficient = poly->coefficient.DIV_QQ_Q(tmp->coefficient);
    object->push(coefficient, degree);
    temp_poly = temp_poly.SUB_PP_P(
        const_cast<Polynomial&>(other).MUL_PQ_P(coefficient));
    poly = temp_poly.polynomial->get_head();
    tmp = tmp->next;
  }
  return Polynomial(object);
}