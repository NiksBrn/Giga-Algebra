#include "headers/IntegerNumber.h"
#include "headers/NaturalNumber.h"
#include "headers/Polynomial.h"
#include "headers/RationalNumber.h"
#include "headers/overload.h"

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
  std::cout << r;
  n.clear();
  i.clear();
  return 0;
}
// Legion_team_aka_special-unit_GAV