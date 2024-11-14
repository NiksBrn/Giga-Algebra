#include <gtest/gtest.h>

#include "../headers/Polynomial.h"
#include "../headers/Overload.h"


TEST(ADD_PP_P, Subtest_1) { //дефолт сложение
  Polynomial polynom1("1x^2+300x^1+100");
  Polynomial polynom2("1x^3+10x^2+100x^1");
  std::string expected = "(1/1x^3) + (11/1x^2) + (400/1x^1) + (100/1x^0)";
  std::stringstream got;
  got << polynom1.ADD_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(ADD_PP_P, Subtest_2) { //обнуление одного из коэффициентов
  Polynomial polynom1("x^2+300x^1+100");
  Polynomial polynom2("x^3+10x^2+100x^1-100");
  std::string expected = "(1/1x^3) + (11/1x^2) + (400/1x^1)";
  std::stringstream got;
  got << polynom1.ADD_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(ADD_PP_P, Subtest_3) { //сложение положительного и отрицательного с отрицательным результатом
  Polynomial polynom1("x^153+300x^1+100");
  Polynomial polynom2("-21x^153+10x^2+100x^1+100");
  std::string expected = "(-20/1x^153) + (10/1x^2) + (400/1x^1) + (200/1x^0)";
  std::stringstream got;
  got << polynom1.ADD_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(ADD_PP_P, Subtest_4) { //сложение положительного и отрицательного с положительным результатом
  Polynomial polynom1("-x^3+x^2+300x^1-100");
  Polynomial polynom2("3x^3+10x^2+100x^1-100");
  std::string expected = "(2/1x^3) + (11/1x^2) + (400/1x^1) + (-200/1x^0)";
  std::stringstream got;
  got << polynom1.ADD_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(SUB_PP_P, Subtest_1) { //дефолт вычетание
  Polynomial polynom1("x^2+300x^1+100");
  Polynomial polynom2("x^3+10x^2+100x^1");
  std::string expected = "(-1/1x^3) + (-9/1x^2) + (200/1x^1) + (100/1x^0)";
  std::stringstream got;
  got << polynom1.SUB_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(SUB_PP_P, Subtest_2) { //обнуление одного из коэффициентов
  Polynomial polynom1("x^2+300x^1+100");
  Polynomial polynom2("x^3+10x^2+100x^1+100");
  std::string expected = "(-1/1x^3) + (-9/1x^2) + (200/1x^1)";
  std::stringstream got;
  got << polynom1.SUB_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(SUB_PP_P, Subtest_3) { //вычетание отрицательного числа из положительного
  Polynomial polynom1("x^153+300x^1+100");
  Polynomial polynom2("-21x^153+10x^2+100x^1");
  std::string expected = "(22/1x^153) + (-10/1x^2) + (200/1x^1) + (100/1x^0)";
  std::stringstream got;
  got << polynom1.SUB_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(SUB_PP_P, Subtest_4) { //вычетание отрицательного числа из отрицательного
  Polynomial polynom1("x^2+300x^1-100");
  Polynomial polynom2("x^3+10x^2+100x^1-101");
  std::string expected = "(-1/1x^3) + (-9/1x^2) + (200/1x^1) + (1/1x^0)";
  std::stringstream got;
  got << polynom1.SUB_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PP_P, Subtest_1) { //дефолт умножение
  Polynomial polynom1("x^2+300x^1-100");
  Polynomial polynom2("x^3+10x^2+100x^1-101");
  std::string expected = "(1/1x^5) + (310/1x^4) + (3000/1x^3) + (28899/1x^2) + (-40300/1x^1) + (10100/1x^0)";
  std::stringstream got;
  got << polynom1.MUL_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PP_P, Subtest_10) { //Первая проверка с понастоящему рациональным числом, тут же умножение  обратных чисел 
  Polynomial polynom1("x^2+300x^1-1/100");
  Polynomial polynom2("x^3+10x^2+100x^1-100");
  std::string expected = "(1/1x^5) + (310/1x^4) + (309999/100x^3) + (2989990/100x^2) + (-3000100/100x^1) + (100/100x^0)";
  std::stringstream got;
  got << polynom1.MUL_PP_P(polynom2);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PQ_P, Subtest_11) { //умножение на 0
  Polynomial polynom1("x^2+300x^1-100");
  RationalNumber number('+', "0", "1");
  std::string expected = "0";
  std::stringstream got;
  got << polynom1.MUL_PQ_P(number);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PQ_P, Subtest_12) { //умножение на положительное число
  Polynomial polynom1("x^2+300x^1-100");
  RationalNumber number('+', "2", "1");
  std::string expected = "(2/1x^2) + (600/1x^1) + (-200/1x^0)";
  std::stringstream got;
  got << polynom1.MUL_PQ_P(number);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PQ_P, Subtest_13) { //умножение на отрицательное число
  Polynomial polynom1("x^2+300x^1-100");
  RationalNumber number('-', "2", "1");
  std::string expected = "(-2/1x^2) + (-600/1x^1) + (200/1x^0)";
  std::stringstream got;
  got << polynom1.MUL_PQ_P(number);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_PQ_P, Subtest_14) { //умножение на обратое число
  Polynomial polynom1("2x^2+2x^1+2");
  RationalNumber number('+', "1", "2");
  std::string expected = "(2/2x^2) + (2/2x^1) + (2/2x^0)";
  std::stringstream got;
  got << polynom1.MUL_PQ_P(number);
  ASSERT_EQ(got.str(), expected);
}

TEST(MUL_Pxk_P, Subtest_15) {
  Polynomial polynom1("2x^2+2x^1+2");
  NaturalNumber number("2");
  std::string expected = "(2/1x^4) + (2/1x^3) + (2/1x^2)";
  std::stringstream got;
  got << polynom1.MUL_Pxk_P(number);
  ASSERT_EQ(got.str(), expected);
}

TEST(LED_P_Q, Subtest_16) { //FAC_P_Q
  Polynomial polynom1("2x^2+2x^1+2");
  std::string expected = "2/1";
  std::stringstream got;
  got << polynom1.LED_P_Q();
  ASSERT_EQ(got.str(), expected);
}

TEST(DEG_P_N, Subtest_17) { //FAC_P_Q
  Polynomial polynom1("3x^4+2x^1+2");
  ASSERT_EQ(polynom1.DEG_P_N(), NaturalNumber("4"));
}

TEST(FAC_P_Q, Subtest_18) { //Первая проверка с понастоящему рациональным числом, тут же умножение  обратных чисел 
  Polynomial polynom1("4/5x^2+6/10x^1+14/2");
  std::string expected = "10/2";
  std::stringstream got;
  got << polynom1.FAC_P_Q();
  ASSERT_EQ(got.str(), expected);
}

TEST(DER_P_P, Subtest_19) { //Первая проверка с понастоящему рациональным числом, тут же умножение  обратных чисел 
  Polynomial polynom1("x^2+300x^1-1/100");
  std::string expected = "(2/1x^1) + (300/1x^0)";
  std::stringstream got;
  got << polynom1.DER_P_P();
  ASSERT_EQ(got.str(), expected);
}

TEST(DER_P_P, Subtest_20) { //Первая проверка с понастоящему рациональным числом, тут же умножение  обратных чисел 
  Polynomial polynom1("0");
  std::string expected = "0";
  std::stringstream got;
  got << polynom1.DER_P_P();
  ASSERT_EQ(got.str(), expected);
}