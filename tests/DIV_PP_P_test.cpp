#include <gtest/gtest.h>

#include "../headers/Polynomial.h"
#include "../headers/Overload.h"

TEST(ADD_PP_P, Subtest_1) {
  Polynomial polynom1("2x^12+3x^2");
  Polynomial polynom2("2x^12+3x");
  std::string expected = "(4/1x^12)+(3/1x^2)+(3/1x^1)";
  std::stringstream got;
  got << polynom1.ADD_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(SUB_PP_P, Subtest_1) {
  Polynomial polynom1("2x^12+3x^2");
  Polynomial polynom2("2x^12+3x^2");
  std::string expected = "0";
  std::stringstream got;
  got << polynom1.SUB_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(SUB_PP_P, Subtest_2) {
  Polynomial polynom1("2x^12+3x^2");
  Polynomial polynom2("2x^12+3x");
  std::string expected = "(3/1x^2)-(3/1x^1)";
  std::stringstream got;
  got << polynom1.SUB_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PQ_P, Subtest_1) {
  Polynomial polynom1("2x^12+3x^2");
  RationalNumber num1 "1";
  std::string expected = "(2x^12)+(3x^2)";
  std::stringstream got;
  got << polynom1.MUL_PQ_P(num1);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PQ_P, Subtest_2) {
  Polynomial polynom1("2x^12+3x^2");
  RationalNumber num1 "2";
  std::string expected = "(4x^12)+(6x^2)";
  std::stringstream got;
  got << polynom1.MUL_PQ_P(num1);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PQ_P, Subtest_3) {
  Polynomial polynom1("2x^12+3x^2");
  RationalNumber num1 "0";
  std::string expected = "0";
  std::stringstream got;
  got << polynom1.MUL_PQ_P(num1);
  ASSERT_EQ(got.str(), expected);
}

TEST(LED_P_Q, Subtest_1) {
  Polynomial polynom1("2x^12+3x^2");
  std::string expected = "3";
  std::stringstream got;
  got << polynom1.LED_P_Q();
  ASSERT_EQ(got.str(), expected);
}

TEST(DEG_P_N, Subtest_1) {
  Polynomial polynom1("2x^12+3x^2");
  std::string expected = "12";
  std::stringstream got;
  got << polynom1.DEG_P_N();
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PP_P, Subtest_1) {
  Polynomial polynom1("2x^2+3x");
  Polynomial polynom2("x+1");
  std::string expected = "(2/1x^3)+(5/1x^2)+(3/1x^1)";
  std::stringstream got;
  got << polynom1.MUL_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

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

TEST(MOD_PP_P, Subtest_1) {
  Polynomial polynom1("x^5+x^4");
  Polynomial polynom2("x^3+x");
  std::string expected = "(-1/1x^2)+(x^1)";
  std::stringstream got;
  got << polynom1.MOD_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(MOD_PP_P, Subtest_2) {
  Polynomial polynom1("x^5+x^4");
  Polynomial polynom2("x^5+x^4");
  std::string expected = "0";
  std::stringstream got;
  got << polynom1.MOD_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(GCF_PP_P, Subtest_1) {
  Polynomial polynom1("2x^12+6x^2");
  Polynomial polynom2("x^12+x^2");
  std::string expected = "(1/1x^12)+(1/1x^2)";
  std::stringstream got;
  got << polynom1.MOD_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(DER_P_P, Subtest_1) {
  Polynomial polynom1("2x^12+3x^2+4");
  std::string expected = "(24/1x^11)+(6/1x^1)";
  std::stringstream got;
  got << polynom1.DER_P_P();
  ASSERT_EQ(got.str(), expected);
}
