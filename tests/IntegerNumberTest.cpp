#include <gtest/gtest.h>

#include "../headers/IntegerNumber.h"

TEST(ABS_Z_N, Subtest_1) {
  IntegerNumber number('+', "123");
  ASSERT_EQ(number.ABS_Z_Z(), NaturalNumber("123"));
}
TEST(ABS_Z_N, Subtest_2) {
  IntegerNumber number('+', "0");
  ASSERT_EQ(number.ABS_Z_Z(), NaturalNumber("0"));
}
TEST(ABS_Z_N, Subtest_3) {
  IntegerNumber number('-', "123");
  ASSERT_EQ(number.ABS_Z_Z(), NaturalNumber("123"));
}

TEST(POZ_Z_D, Subtest_1) {
  IntegerNumber number('+', "123");
  ASSERT_EQ(number.POZ_Z_D(), Sign::POSITIVE);
}

TEST(POZ_Z_D, Subtest_2) {
  IntegerNumber number('-', "123");
  ASSERT_EQ(number.POZ_Z_D(), Sign::NEGATIVE);
}

TEST(POZ_Z_D, Subtest_3) {
  IntegerNumber number('+', "0");
  ASSERT_EQ(number.POZ_Z_D(), Sign::ZERO);
}

TEST(MUL_ZM_Z, Subtest_1) {
  IntegerNumber number('+', "123");
  number.MUL_ZM_Z();
  ASSERT_EQ(number.POZ_Z_D(), Sign::NEGATIVE);
}

TEST(MUL_ZM_Z, Subtest_2) {
  IntegerNumber number('-', "123");
  number.MUL_ZM_Z();
  ASSERT_EQ(number.POZ_Z_D(), Sign::POSITIVE);
}

TEST(TRANS_N_Z, Subtest_1) {
  NaturalNumber number("123");
  IntegerNumber number2 = IntegerNumber::TRANS_N_Z(number);
  ASSERT_EQ(number2.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(number2.ABS_Z_Z(), number);
}

TEST(TRANS_Z_N, Subtest_1) {
  IntegerNumber number('+', "123");
  ASSERT_EQ(IntegerNumber::TRANS_Z_N(number), NaturalNumber("123"));
}

TEST(TRANS_Z_N, Subtest_2) {
  IntegerNumber number('-', "123");
  ASSERT_EQ(number.TRANS_Z_N(number), NaturalNumber("123"));
}

TEST(ADD_ZZ_Z, Subtest_1) {
  IntegerNumber number('+', "123");
  IntegerNumber number2('+', "123");
  auto result = number.ADD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("246"));
}

TEST(ADD_ZZ_Z, Subtest_2) {
  IntegerNumber number('+', "123");
  IntegerNumber number2('-', "123");
  auto result = number.ADD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::ZERO);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("0"));
}

TEST(ADD_ZZ_Z, Subtest_3) {
  IntegerNumber number('-', "123");
  IntegerNumber number2('-', "123");
  auto result = number.ADD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("246"));
}

TEST(ADD_ZZ_Z, Subtest_4) {
  IntegerNumber number('-', "246");
  IntegerNumber number2('+', "124");
  auto result = number.ADD_ZZ_Z(number2);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("122"));
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
}

TEST(ADD_ZZ_Z, Subtest_5) {
  IntegerNumber number('-', "124");
  IntegerNumber number2('+', "246");
  auto result = number.ADD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("122"));
}

TEST(ADD_ZZ_Z, Subtest_6) {
  IntegerNumber number('+', "124");
  IntegerNumber number2('-', "246");
  auto result = number.ADD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("122"));
}

TEST(SUB_ZZ_Z, Subtest_1) {
  IntegerNumber number('-', "123");
  IntegerNumber number2('+', "123");
  auto result = number.SUB_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("246"));
}

TEST(SUB_ZZ_Z, Subtest_2) {
  IntegerNumber number('+', "123");
  IntegerNumber number2('+', "123");
  auto result = number.SUB_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::ZERO);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("0"));
}

TEST(SUB_ZZ_Z, Subtest_3) {
  IntegerNumber number('+', "100");
  IntegerNumber number2('+', "300");
  auto result = number.SUB_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("200"));
}

TEST(MUL_ZZ_Z, Subtest_1) {
  IntegerNumber number('+', "20");
  IntegerNumber number2('+', "5");
  auto result = number.MUL_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("100"));
}

TEST(MUL_ZZ_Z, Subtest_2) {
  IntegerNumber number('-', "20");
  IntegerNumber number2('-', "5");
  auto result = number.MUL_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("100"));
}

TEST(MUL_ZZ_Z, Subtest_3) {
  IntegerNumber number('+', "20");
  IntegerNumber number2('-', "5");
  auto result = number.MUL_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("100"));
}

TEST(MUL_ZZ_Z, Subtest_4) {
  IntegerNumber number('-', "20");
  IntegerNumber number2('+', "5");
  auto result = number.MUL_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("100"));
}

TEST(DIV_ZZ_Z, Subtest_1) {
  IntegerNumber number('+', "100");
  IntegerNumber number2('+', "5");
  auto result = number.DIV_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("20"));
}

TEST(DIV_ZZ_Z, Subtest_2) {
  IntegerNumber number('-', "100");
  IntegerNumber number2('-', "5");
  auto result = number.DIV_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("20"));
}

TEST(DIV_ZZ_Z, Subtest_3) {
  IntegerNumber number('-', "100");
  IntegerNumber number2('+', "5");
  auto result = number.DIV_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("20"));
}

TEST(DIV_ZZ_Z, Subtest_4) {
  IntegerNumber number('+', "100");
  IntegerNumber number2('-', "5");
  auto result = number.DIV_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::NEGATIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("20"));
}

TEST(MOD_ZZ_Z, Subtest_1) {
  IntegerNumber number('+', "21");
  IntegerNumber number2('+', "4");
  auto result = number.MOD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("1"));
}

TEST(MOD_ZZ_Z, Subtest_2) {
  IntegerNumber number('+', "21");
  IntegerNumber number2('-', "4");
  auto result = number.MOD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("1"));
}

TEST(MOD_ZZ_Z, Subtest_3) {
  IntegerNumber number('-', "21");
  IntegerNumber number2('-', "4");
  auto result = number.MOD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("3"));
}

TEST(MOD_ZZ_Z, Subtest_4) {
  IntegerNumber number('-', "21");
  IntegerNumber number2('+', "4");
  auto result = number.MOD_ZZ_Z(number2);
  ASSERT_EQ(result.POZ_Z_D(), Sign::POSITIVE);
  ASSERT_EQ(result.ABS_Z_Z(), NaturalNumber("3"));
}