#include "headers/IntegerNumber.h"
#include "headers/NaturalNumber.h"
#include "headers/Polynomial.h"
#include "headers/RationalNumber.h"
#include "headers/Overload.h"

int main() {
  NaturalNumber n(
      "123123213211231176253768125436723154678553256747562134675236541762354765"
      "21376452673547625376457263547625137645236754761253674523142344");
  std::cout << n << "\n";
  IntegerNumber i('+', "1234453446");
  std::cout << i << "\n";
  i = IntegerNumber('-', "1234453446");
  std::cout << i << "\n";
  RationalNumber r('-', "1245232424242", "1352342562356453567724");
  std::cout << r << "\n";
  r = RationalNumber(i, n);
  std::cout << r << "\n";
  n.clear();
  i.clear();
  Polynomial p("2x^12+3x^2");
  Polynomial p1("2x^12+3x");
  Polynomial p2("2x");
  Polynomial p3("2x");
  std::cout << p2.DIV_PP_P(p3) << "\n";
  std::cout << p.DIV_PP_P(p1) << "\n";
  std::cout << p.MOD_PP_P(p1) << "\n";
  std::cout << p.GCF_PP_P(p1) << "\n";
  return 0;
}
// Legion_team_aka_special-unit_GAV