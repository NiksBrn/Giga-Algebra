#include <iostream>
#include <gtest/gtest.h>
#include "../headers/NaturalNumber.h"
#include "../headers/Overload.h"

// MUL_NN_N Testing
TEST(MUL_NN_N, Subtest_1) {
  NaturalNumber n1("125");
  NaturalNumber n2("112");
  NaturalNumber result("14000");
  ASSERT_EQ(n1.MUL_NN_N(n2), result);
}

TEST(MUL_NN_N, Subtest_2) {
  NaturalNumber n1("91");
  NaturalNumber n2("65073");
  NaturalNumber result("5921643");
  ASSERT_EQ(n1.MUL_NN_N(n2), result);
}

TEST(MUL_NN_N, Subtest_3) {
  NaturalNumber n1("726438");
  NaturalNumber n2("40");
  NaturalNumber result("29057520");
  ASSERT_EQ(n1.MUL_NN_N(n2), result);
}

TEST(MUL_NN_N, Subtest_4) {
  NaturalNumber n1("9321356423");
  NaturalNumber n2("0");
  NaturalNumber result("0");
  ASSERT_EQ(n1.MUL_NN_N(n2), result);
}

TEST(MUL_NN_N, Subtest_5) {
  NaturalNumber n1("56754");
  NaturalNumber n2("70763");
  NaturalNumber result("4016083302");
  ASSERT_EQ(n1.MUL_NN_N(n2), result);
}

// SUB_NDN_N Testing
TEST(SUB_NDN_N, Subtest_1) {
  NaturalNumber n1("312412473");
  NaturalNumber n2("9372");
  NaturalNumber result("312393729");
  ASSERT_EQ(n1.SUB_NDN_N(n2, 2), result);
}

// DIV_NN_Dk Testing
TEST(DIV_NN_Dk, Subtest_1) {
  NaturalNumber n1("25667");
  NaturalNumber n2("6");
  std::pair<char, unsigned long long> DIV_NN_Dk_result = n1.DIV_NN_Dk(n2);
  std::pair<char, unsigned long long> result = {4, 3};
  ASSERT_EQ(DIV_NN_Dk_result.first, result.first);
  ASSERT_EQ(DIV_NN_Dk_result.second, result.second);
}

TEST(DIV_NN_Dk, Subtest_2) {
  NaturalNumber n1("12000");
  NaturalNumber n2("120");
  std::pair<char, unsigned long long> DIV_NN_Dk_result = n1.DIV_NN_Dk(n2);
  std::pair<char, unsigned long long> result = {1, 2};
  ASSERT_EQ(DIV_NN_Dk_result.first, result.first);
  ASSERT_EQ(DIV_NN_Dk_result.second, result.second);
}

TEST(DIV_NN_Dk, Subtest_3) {
  NaturalNumber n1("43553");
  NaturalNumber n2("12441243");
  std::pair<char, unsigned long long> DIV_NN_Dk_result = n1.DIV_NN_Dk(n2);
  std::pair<char, unsigned long long> result = {0, 0};
  ASSERT_EQ(DIV_NN_Dk_result.first, result.first);
  ASSERT_EQ(DIV_NN_Dk_result.second, result.second);
}

// DIV_NN_N Testing
TEST(DIV_NN_N, Subtest_1) {
  NaturalNumber n1("853423");
  NaturalNumber n2("523");
  NaturalNumber result = NaturalNumber("1631");
  ASSERT_EQ(n1.DIV_NN_N(n2), result);
}

TEST(DIV_NN_N, Subtest_2) {
  NaturalNumber n1("23472819");
  NaturalNumber n2("663");
  NaturalNumber result = NaturalNumber("35403");
  ASSERT_EQ(n1.DIV_NN_N(n2), result);
}

// MOD_NN_N Testing
TEST(MOD_NN_N, Subtest_1) {
  NaturalNumber n1("23472819");
  NaturalNumber n2("663");
  NaturalNumber result = NaturalNumber("630");
  ASSERT_EQ(n1.MOD_NN_N(n2), result);
}

TEST(MOD_NN_N, Subtest_2) {
NaturalNumber n1("663");
NaturalNumber n2("23472819");
NaturalNumber result = NaturalNumber("663");
ASSERT_EQ(n1.MOD_NN_N(n2), result);
}

// GCF_NN_N Testing
TEST(GCF_NN_N, Subtest_1) {
  NaturalNumber n1("6226814");
  NaturalNumber n2("306685");
  NaturalNumber result = NaturalNumber("739");
  ASSERT_EQ(n1.GCF_NN_N(n2), result);
}

TEST(GCF_NN_N, Subtest_2) {
  NaturalNumber n1("21314");
  NaturalNumber n2("306685");
  NaturalNumber result = NaturalNumber("1");
  ASSERT_EQ(n1.GCF_NN_N(n2), result);
}

// LCM_NN_N Testing
TEST(LCM_NN_N, Subtest_1) {
  NaturalNumber n1("56754");
  NaturalNumber n2("424578");
  NaturalNumber result = NaturalNumber("4016083302");
  ASSERT_EQ(n1.LCM_NN_N(n2), result);
}