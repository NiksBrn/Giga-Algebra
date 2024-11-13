#include <gtest/gtest.h>

#include "../headers/Polynomial.h"


TEST(ADD_PP_P, Subtest_1) { //дефолт сложение
  Polynomial polynom1("x^2+300x^1+100");
  Polynomial polynom2("x^3+10x^2+100x^1");
  ASSERT_EQ(polynom1.ADD_PP_P(polynom2), Polynomial("x^3+11x^2+400x^1+100"));
}

TEST(ADD_PP_P, Subtest_2) { //обнуление одного из коэффициентов
  Polynomial polynom1("x^2+300x^1+100");
  Polynomial polynom2("x^3+10x^2+100x^1-100");
  ASSERT_EQ(polynom1.ADD_PP_P(polynom2), Polynomial("x^3+11x^2+400x^1"));
}

TEST(ADD_PP_P, Subtest_3) { //сложение положительного и отрицательного с отрицательным результатом
  Polynomial polynom1("x^153+300x^1+100");
  Polynomial polynom2("-21x^153+10x^2+100x^1+100");
  ASSERT_EQ(polynom1.ADD_PP_P(polynom2), Polynomial("-20x^153+10x^2+400x^1"));
}

TEST(ADD_PP_P, Subtest_4) { //сложение положительного и отрицательного с положительным результатом
  Polynomial polynom1("x^2+300x^1-100");
  Polynomial polynom2("x^3+10x^2+100x^1-100");
  ASSERT_EQ(polynom1.ADD_PP_P(polynom2), Polynomial("x^3+11x^2+400x^1-200"));
}

TEST(SUB_PP_P, Subtest_5) { //дефолт вычетание
  Polynomial polynom1("x^2+300x^1+100");
  Polynomial polynom2("x^3+10x^2+100x^1");
  ASSERT_EQ(polynom1.SUB_PP_P(polynom2), Polynomial("-x^3-9x^2+200x^1+100"));
}

TEST(SUB_PP_P, Subtest_6) { //обнуление одного из коэффициентов
  Polynomial polynom1("x^2+300x^1+100");
  Polynomial polynom2("x^3+10x^2+100x^1+100");
  ASSERT_EQ(polynom1.SUB_PP_P(polynom2), Polynomial("-x^3-9x^2+200x^1"));
}

TEST(SUB_PP_P, Subtest_7) { //вычетание отрицательного числа из положительного
  Polynomial polynom1("x^153+300x^1+100");
  Polynomial polynom2("-21x^153+10x^2+100x^1");
  ASSERT_EQ(polynom1.SUB_PP_P(polynom2), Polynomial("22x^153-10x^2+200x^1+100"));
}

TEST(SUB_PP_P, Subtest_8) { //вычетание отрицательного числа из отрицательного
  Polynomial polynom1("x^2+300x^1-100");
  Polynomial polynom2("x^3+10x^2+100x^1-101");
  ASSERT_EQ(polynom1.SUB_PP_P(polynom2), Polynomial("-x^3-9x^2+200x^1+1"));
}

TEST(MUL_PP_P, Subtest_9) { //дефолт умножение
  Polynomial polynom1("x^2+300x^1-100");
  Polynomial polynom2("x^3+10x^2+100x^1-101");
  ASSERT_EQ(polynom1.MUL_PP_P(polynom2), Polynomial("x^5+310x^4+28899x^2+3000x^3-40300x+10100"));
}

TEST(MUL_PP_P, Subtest_10) { //Первая проверка с понастоящему рациональным числом, тут же умножение  обратных чисел 
  Polynomial polynom1("x^2+300x^1-1/100");
  Polynomial polynom2("x^3+10x^2+100x^1-100");
  ASSERT_EQ(polynom1.MUL_PP_P(polynom2), Polynomial("x^5+310x^4+309999/10x^3+298999/10x^2-30001x+1"));
}

TEST(MUL_PQ_P, Subtest_11) { //умножение на 0
  Polynomial polynom1("x^2+300x^1-100");
  RationalNumber number('$', "0");
  ASSERT_EQ(polynom1.MUL_PQ_P(number), Polynomial("0"));
}

TEST(MUL_PQ_P, Subtest_12) { //умножение на положительное число
  Polynomial polynom1("x^2+300x^1-100");
  RationalNumber number('$', "2");
  ASSERT_EQ(polynom1.MUL_PQ_P(number), Polynomial("2x^2+600x^1-200"));
}

TEST(MUL_PQ_P, Subtest_13) { //умножение на отрицательное число
  Polynomial polynom1("x^2+300x^1-100");
  RationalNumber number('$', "2");
  ASSERT_EQ(polynom1.MUL_PQ_P(number), Polynomial("-2x^2-600x^1+200"));
}

TEST(MUL_PQ_P, Subtest_14) { //умножение на обратое число
  Polynomial polynom1("2x^2+2x^1+2");
  RationalNumber number('$', "1/2");
  ASSERT_EQ(polynom1.MUL_PQ_P(number), Polynomial("x^2+x^1+1"));
}

TEST(MUL_Pxk_P, Subtest_15) {
  Polynomial polynom1("2x^2+2x^1+2");
  NaturalNumber number("2");
  ASSERT_EQ(polynom1.MUL_Pxk_P(number), Polynomial("2x^4+2x^3+2x^2"));
}

TEST(LED_P_Q, Subtest_16) { //FAC_P_Q
  Polynomial polynom1("2x^2+2x^1+2");
  ASSERT_EQ(polynom1.LED_P_Q(), RationalNumber('-', "2"));
}

TEST(DEG_P_N, Subtest_17) { //FAC_P_Q
  Polynomial polynom1("3x^4+2x^1+2");
  ASSERT_EQ(polynom1.DEG_P_N(), NaturalNumber("4"));
}

TEST(FAC_P_Q, Subtest_18) { //Первая проверка с понастоящему рациональным числом, тут же умножение  обратных чисел 
  Polynomial polynom1("4/5x^2+6/10x^1+14/2");
  ASSERT_EQ(polynom1.FAC_P_Q(), RationalNumber('-', "2/10"));
}

TEST(DER_P_P, Subtest_19) { //Первая проверка с понастоящему рациональным числом, тут же умножение  обратных чисел 
  Polynomial polynom1("x^2+300x^1-1/100");
  ASSERT_EQ(polynom1.DER_P_P(), Polynomial("2x^1+300"));
}

TEST(DER_P_P, Subtest_20) { //Первая проверка с понастоящему рациональным числом, тут же умножение  обратных чисел 
  Polynomial polynom1("0");
  ASSERT_EQ(polynom1.DER_P_P(), Polynomial("0"));
}

