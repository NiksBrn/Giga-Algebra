#include "../../headers/Polynomial.h"

Polynomial Polynomial::DIV_PP_P(const Polynomial& other) {
  ListPolynomial* object = new ListPolynomial();
  Polynomial temp_poly = *this;
  Polynomial temp_other = other;
  NodePolynomial* poly = temp_poly.polynomial->get_head();
  NaturalNumber maxDegree = temp_other.polynomial->get_head()->degree;
  RationalNumber coefficient_poly =
      temp_other.polynomial->get_head()->coefficient;
  // пока полином существует и пока его можно поделить
  while (poly != nullptr && poly->degree.COM_NN_D(maxDegree) != Compare::LESS) {
    // получение степени
    NaturalNumber degree = poly->degree.SUB_NN_N(maxDegree);
    // получение коэффициента
    RationalNumber coefficient = poly->coefficient.DIV_QQ_Q(coefficient_poly);
    // добалвение монома в полином
    object->push(coefficient, degree);
    // вычитание из делимого делителя, умноженного на моном
    temp_poly =
        temp_poly.SUB_PP_P(temp_other.MUL_PQ_P(coefficient).MUL_Pxk_P(degree));
    poly = temp_poly.polynomial->get_head();
  }
  // если цикл ни разу не сработал
  if (poly == polynomial->get_head()) {
    object->push(RationalNumber(IntegerNumber('+', "0")), NaturalNumber("0"));
  }
  return Polynomial(object);
}

Polynomial Polynomial::NMR_P_P() {
  Polynomial Der = (*this).DER_P_P();  // Производная многочлена
  Polynomial GCF = (*this).GCF_PP_P(Der);  // НОД многочлена
  Polynomial NMR = *this;
  if (!(GCF.DEG_P_N() == NaturalNumber("0")) ||
      !(GCF.polynomial->get_tail()->coefficient.Trans_Q_Z().POZ_Z_D() ==
        ZERO)) {
    NMR = (*this).DIV_PP_P(GCF);
  } else {
    NMR = GCF;
  }
  return NMR;
}