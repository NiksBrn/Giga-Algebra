#include <iostream>
#include <gtest/gtest.h>
#include "../headers/RationalNumber.h"
#include "../headers/Overload.h"

// RED_Q_Q Testing
TEST(RED_Q_Q, Subtest_1) {
  IntegerNumber n1('-',"78");
  NaturalNumber n2("2");
  RationalNumber n3(n1,n2);
  std::string result = "-39";
  std::stringstream got;
  got<<n3.RED_Q_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(RED_Q_Q, Subtest_2) {
  IntegerNumber n1('$',"15");
  NaturalNumber n2("5");
  RationalNumber n3(n1,n2);
  std::string result = "3";
  std::stringstream got;
  got<<n3.RED_Q_Q(n3);
  ASSERT_EQ(result, got.str());
}

// INT_Q_B Testing
TEST(INT_Q_B, Subtest_1) {
  IntegerNumber n1('-',"8");
  NaturalNumber n2("2");
  RationalNumber n3(n1,n2);
  ASSERT_EQ(n3.INT_Q_B(n3), false);
}

TEST(INT_Q_B, Subtest_2) {
  IntegerNumber n1('$',"8");
  NaturalNumber n2("1");
  RationalNumber n3(n1,n2);
  ASSERT_EQ(n3.INT_Q_B(n3), true);
}


// Trans_Z_Q Testing
TEST(Trans_Z_Q, Subtest_1) {
  IntegerNumber n1('-',"123456");
  std::string result = "-123456/1";
  std::stringstream got;
  got<<n1.TRANS_Z_Q(n1);
  ASSERT_EQ(result, got.str());
}

TEST(Trans_Z_Q, Subtest_2) {
  IntegerNumber n1('$',"123456");
  std::string result = "123456/1";
  std::stringstream got;
  got<<n1.TRANS_Z_Q(n1);
  ASSERT_EQ(result, got.str());
}

// Trans_Q_Z Testing
TEST(Trans_Q_Z, Subtest_1) {
  IntegerNumber n1('-',"23475");
  NaturalNumber n2("1");
  RationalNumber n3(n1,n2);
  std::string result = "-23475";
  std::stringstream got;
  got<<n3.TRANS_Q_Z(n3);
  ASSERT_EQ(result, got.str());
}

TEST(Trans_Q_Z, Subtest_2) {
  IntegerNumber n1('$',"896");
  NaturalNumber n2("1");
  RationalNumber n3(n1,n2);
  std::string result = "896";
  std::stringstream got;
  got<<n3.TRANS_Q_Z(n3);
  
// ADD_QQ_Q Testing
TEST(ADD_QQ_Q, Subtest_1) {
  IntegerNumber n1_1('$',"100");
  NaturalNumber n2_1("7");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"200");
  NaturalNumber n2_2("7");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "300/7";
  std::stringstream got;
  got<<n3.ADD_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(ADD_QQ_Q, Subtest_2) {
  IntegerNumber n1_1('-',"200");
  NaturalNumber n2_1("7");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"300");
  NaturalNumber n2_2("7");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "100/7";
  std::stringstream got;
  got<<n3.ADD_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(ADD_QQ_Q, Subtest_3) {
  IntegerNumber n1_1('-',"200");
  NaturalNumber n2_1("7");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"200");
  NaturalNumber n2_2("7");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "0/7";
  std::stringstream got;
  got<<n3.ADD_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(ADD_QQ_Q, Subtest_4) {
  IntegerNumber n1_1('$',"10");
  NaturalNumber n2_1("7");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"6");
  NaturalNumber n2_2("3");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "72/21";
  std::stringstream got;
  got<<n3.ADD_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(ADD_QQ_Q, Subtest_5) {
  IntegerNumber n1_1('-',"10");
  NaturalNumber n2_1("10");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"23");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "140/90";
  std::stringstream got;
  got<<n3.ADD_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

// SUB_QQ_Q Testing
TEST(SUB_QQ_Q, Subtest_1) {
  IntegerNumber n1_1('$',"678");
  NaturalNumber n2_1("9");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"120");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "558/9";
  std::stringstream got;
  got<<n3.SUB_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(SUB_QQ_Q, Subtest_2) {
  IntegerNumber n1_1('-',"789");
  NaturalNumber n2_1("9");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"120");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "-909/9";
  std::stringstream got;
  got<<n3.SUB_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(SUB_QQ_Q, Subtest_3) {
  IntegerNumber n1_1('-',"789");
  NaturalNumber n2_1("9");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('-',"300");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "-489/9";
  std::stringstream got;
  got<<n3.SUB_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(SUB_QQ_Q, Subtest_4) {
  IntegerNumber n1_1('$',"50");
  NaturalNumber n2_1("9");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"50");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "0/9";
  std::stringstream got;
  got<<n3.SUB_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(SUB_QQ_Q, Subtest_5) {
  IntegerNumber n1_1('$',"50");
  NaturalNumber n2_1("9");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"90");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "-40/9";
  std::stringstream got;
  got<<n3.SUB_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(SUB_QQ_Q, Subtest_6) {
  IntegerNumber n1_1('$',"5");
  NaturalNumber n2_1("9");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"9");
  NaturalNumber n2_2("2");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "-71/18";
  std::stringstream got;
  got<<n3.SUB_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}
  ASSERT_EQ(result, got.str());
}

// MUL_QQ_Q Testing
TEST(MUL_QQ_Q, Subtest_1) {
  IntegerNumber n1_1('$',"5");
  NaturalNumber n2_1("5");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"6");
  NaturalNumber n2_2("6");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "30/30";
  std::stringstream got;
  got<<n3.MUL_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(MUL_QQ_Q, Subtest_2) {
  IntegerNumber n1_1('$',"12");
  NaturalNumber n2_1("5");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"0");
  NaturalNumber n2_2("6");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "0/30";
  std::stringstream got;
  got<<n3.MUL_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(MUL_QQ_Q, Subtest_3) {
  IntegerNumber n1_1('-',"4");
  NaturalNumber n2_1("5");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('-',"10");
  NaturalNumber n2_2("8");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "40/40";
  std::stringstream got;
  got<<n3.MUL_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(MUL_QQ_Q, Subtest_4) {
  IntegerNumber n1_1('-',"4");
  NaturalNumber n2_1("9");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"10");
  NaturalNumber n2_2("8");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "-40/72";
  std::stringstream got;
  got<<n3.MUL_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

// DIV_QQ_Q Testing
TEST(DIV_QQ_Q, Subtest_1) {
  IntegerNumber n1_1('$',"5");
  NaturalNumber n2_1("15");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"1");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "45/15";
  std::stringstream got;
  got<<n3.DIV_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(DIV_QQ_Q, Subtest_2) {
  IntegerNumber n1_1('-',"5");
  NaturalNumber n2_1("15");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('-',"1");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "45/15";
  std::stringstream got;
  got<<n3.DIV_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(DIV_QQ_Q, Subtest_3) {
  IntegerNumber n1_1('-',"0");
  NaturalNumber n2_1("5");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('$',"1");
  NaturalNumber n2_2("9");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "-0/5";
  std::stringstream got;
  got<<n3.DIV_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}

TEST(DIV_QQ_Q, Subtest_4) {
  IntegerNumber n1_1('$',"100");
  NaturalNumber n2_1("45");
  RationalNumber n3_1(n1_1,n2_1);
  IntegerNumber n1_2('-',"1");
  NaturalNumber n2_2("1");
  RationalNumber n3_2(n1_2,n2_2);
  std::string result = "-100/45";
  std::stringstream got;
  got<<n3.DIV_QQ_Q(n3);
  ASSERT_EQ(result, got.str());
}


