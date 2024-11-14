#include <gtest/gtest.h>

#include "../headers/Polynomial.h"
#include "../headers/Overload.h"

TEST(DIV_PP_P, Subtest_1) {
  Polynomial polynom1("2x^12+3x^2");
  Polynomial polynom2("2x^12+3x");
  std::string expected = "(2/2x^0)";
  std::stringstream got;
  got << polynom1.DIV_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(DIV_PP_P, Subtest_2) {
  Polynomial polynom1("x^3-12x^2-42");
  Polynomial polynom2("x-3");
  std::string expected = "(1/1x^2) + (-9/1x^1) + (-27/1x^0)";
  std::stringstream got;
  got << polynom1.DIV_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(DIV_PP_P, Subtest_3) {
  Polynomial polynom1("x^3-12x^2-42");
  Polynomial polynom2("x^100-3");
  std::string expected = "0";
  std::stringstream got;
  got << polynom1.DIV_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(DIV_PP_P, Subtest_4) {
  Polynomial polynom1("x^4-1");
  Polynomial polynom2("x-1");
  std::string expected = "(1/1x^3) + (1/1x^2) + (1/1x^1) + (1/1x^0)";
  std::stringstream got;
  got << polynom1.DIV_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(DIV_PP_P, Subtest_5) {
  Polynomial polynom1("2x^12+6x^2");
  Polynomial polynom2("1x^12+6x^2");
  std::string expected = "(2/1x^0)";
  std::stringstream got;
  got << polynom1.DIV_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}