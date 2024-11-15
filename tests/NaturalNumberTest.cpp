#include <iostream>
#include <gtest/gtest.h>
#include "../headers/NaturalNumber.h"
#include "../headers/Overload.h"

// Òåñòû äëÿ ïðîâåðêè NZER_N_B()
TEST(NZER_N_B, Subtest_1) {
  // Òåñò äëÿ íåíóëåâîãî ÷èñëà
  NaturalNumber n("12345");
  EXPECT_TRUE(n.NZER_N_B());
}

TEST(NZER_N_B, Subtest_2) {
  // Òåñò äëÿ íóëåâîãî ÷èñëà
  NaturalNumber n("0");
  EXPECT_FALSE(n.NZER_N_B());
}

// Òåñòû äëÿ ïðîâåðêè COM_NN_D()
TEST(COM_NN_D, Subtest_1) {
  // Òåñò äëÿ ÷èñåë ñ îäèíàêîâîé ðàçðÿäíîñòüþ, ãäå âòîðîå áîëüøå ïåðâîãî
  NaturalNumber n1("100");
  NaturalNumber n2("310");
  ASSERT_EQ(n1.COM_NN_D(n2), LESS);
}

TEST(COM_NN_D, Subtest_2) {
  // Òåñò äëÿ ÷èñåë ñ îäèíàêîâîé ðàçðÿäíîñòüþ, ãäå ïåðâîå áîëüøå âòîðîãî
  NaturalNumber n1("478");
  NaturalNumber n2("420");
  ASSERT_EQ(n1.COM_NN_D(n2), GREATER);
}

TEST(COM_NN_D, Subtest_3) {
  // Òåñò äëÿ ðàâíûõ ÷èñåë ñ îäèíàêîâîé ðàçðÿäíîñòüþ
  NaturalNumber n1("666000");
  NaturalNumber n2("666000");
  ASSERT_EQ(n1.COM_NN_D(n2), EQUAL);
}

TEST(COM_NN_D, Subtest_4) {
  // Òåñò äëÿ ÷èñåë ñ ðàçíîé ðàçðÿäíîñòüþ, ãäå ïåðâîå áîëüøå âòîðîãî
  NaturalNumber n1("12456666599");
  NaturalNumber n2("666599");
  ASSERT_EQ(n1.COM_NN_D(n2), GREATER);
}

TEST(COM_NN_D, Subtest_5) {
  // Òåñò äëÿ ÷èñåë ñ ðàçíîé ðàçðÿäíîñòüþ, ãäå âòîðîå áîëüøå ïåðâîãî
  NaturalNumber n1("9");
  NaturalNumber n2("35409");
  ASSERT_EQ(n1.COM_NN_D(n2), LESS);
}

// Òåñòû äëÿ ïðîâåðêè ADD_1N_N()
TEST(ADD_1N_N, Subtest_1) {
  // Òåñò äëÿ ÷èñëà áåç èçìåíåíèÿ ðàçðÿäíîñòè
  NaturalNumber n1("777");
  NaturalNumber n2("778");
  ASSERT_EQ(n1.ADD_1N_N(), n2);
}

TEST(ADD_1N_N, Subtest_2) {
  // Òåñò äëÿ ÷èñëà ñî ñìåíîé ðàçðÿäíîñòè
  NaturalNumber n1("999");
  NaturalNumber n2("1000");
  ASSERT_EQ(n1.ADD_1N_N(), n2);
}

// Òåñòû äëÿ ïðîâåðêè ADD_NN_N()
TEST(ADD_NN_N, Subtest_1) {
  // Òåñò äëÿ ÷èñåë áåç ñìåíû ðàçðÿäíîñòè
  NaturalNumber n1("123");
  NaturalNumber n2("456");
  NaturalNumber result("579");
  ASSERT_EQ(n1.ADD_NN_N(n2), result);
}

TEST(ADD_NN_N, Subtest_2) {
  // Òåñò äëÿ ÷èñåë ñî ñìåíîé ðàçðÿäíîñòè
  NaturalNumber n1("4567356");
  NaturalNumber n2("8955787");
  NaturalNumber result("13523143");
  ASSERT_EQ(n1.ADD_NN_N(n2), result);
}

TEST(ADD_NN_N, Subtest_3) {
  NaturalNumber n1("99");
  NaturalNumber n2("99");
  NaturalNumber result("198");
  ASSERT_EQ(n1.ADD_NN_N(n2), result);
}

TEST(ADD_NN_N, Subtest_4) {
  NaturalNumber n1("100");
  NaturalNumber n2("1");
  NaturalNumber result("101");
  ASSERT_EQ(n1.ADD_NN_N(n2), result);
}

TEST(ADD_NN_N, Subtest_5) {
  NaturalNumber n1("119");
  NaturalNumber n2("1");
  NaturalNumber result("120");
  ASSERT_EQ(n1.ADD_NN_N(n2), result);
}

TEST(ADD_NN_N, Subtest_6) {
NaturalNumber n1("43303302");
NaturalNumber n2("3972780000");
NaturalNumber result("4016083302");
ASSERT_EQ(n1.ADD_NN_N(n2), result);
}

// Òåñòû äëÿ ïðîâåðêè MUL_ND_N()
TEST(MUL_ND_N, Subtest_1) {
  // Òåñò äëÿ äâóõçíà÷íîãî ÷èñëà áåç ñìåíû ðàçðÿäíîñòè
  NaturalNumber n("12");
  char c;
  c = (3);
  NaturalNumber result("36");
  ASSERT_EQ(n.MUL_ND_N(c), result);
}

TEST(MUL_ND_N, Subtest_2) {
  // Òåñò äëÿ äâóõçíà÷íîãî ÷èñëà ñî ñìåíîé ðàçðÿäíîñòè
  NaturalNumber n("35");
  char c;
  c = (4);
  NaturalNumber result("140");
  ASSERT_EQ(n.MUL_ND_N(c), result);
}

TEST(MUL_ND_N, Subtest_3) {
  // Òåñò äëÿ îäíîçíà÷íîãî ÷èñëà ñî ñìåíîé ðàçðÿäíîñòè
  NaturalNumber n("3");
  char c;
  c = (4);
  NaturalNumber result("12");
  ASSERT_EQ(n.MUL_ND_N(c), result);
}
TEST(MUL_ND_N, Subtest_4) {
  // Òåñò äëÿ îäíîçíà÷íîãî ÷èñëà áåç ñìåíû ðàçðÿäíîñòè
  NaturalNumber n("3");
  char c;
  c = (3);
  NaturalNumber result("9");
  ASSERT_EQ(n.MUL_ND_N(c), result);
}
TEST(MUL_ND_N, Subtest_5) {
  // Òåñò äëÿ óìíîæåíèÿ íà 0
  NaturalNumber n("12");
  char c;
  c = (0);
  NaturalNumber result("0");
  ASSERT_EQ(n.MUL_ND_N(c), result);
}

TEST(MUL_ND_N, Subtest_6) {
  NaturalNumber n("56754");
  char c;
  c = (7);
  NaturalNumber result("397278");
  ASSERT_EQ(n.MUL_ND_N(c), result);
}

// Òåñòû äëÿ ïðîâåðêè SUB_NN_N()
TEST(SUB_NN_N, Subtest_1) {
  // Òåñò äëÿ ðàçíûõ ÷èñåë áåç ñìåíû ðàçðÿäíîñòè
  NaturalNumber n1("60");
  NaturalNumber n2("50");
  NaturalNumber result("10");
  ASSERT_EQ(n1.SUB_NN_N(n2), result);
}

TEST(SUB_NN_N, Subtest_2) {
  // Òåñò äëÿ ðàçíûõ ÷èñåë ñî ñìåíîé ðàçðÿäíîñòè
  NaturalNumber n1("160");
  NaturalNumber n2("85");
  NaturalNumber result("75");
  ASSERT_EQ(n1.SUB_NN_N(n2), result);
}

TEST(SUB_NN_N, Subtest_3) {
  NaturalNumber n1("1000000");
  NaturalNumber n2("1");
  NaturalNumber result("999999");
  ASSERT_EQ(n1.SUB_NN_N(n2), result);
}

TEST(SUB_NN_N, Subtest_4) {
  NaturalNumber n1("1000000");
  NaturalNumber n2("999999");
  NaturalNumber result("1");
  ASSERT_EQ(n1.SUB_NN_N(n2), result);
}

TEST(SUB_NN_N, Subtest_5) {
  NaturalNumber n1("1");
  NaturalNumber n2("999999");
  NaturalNumber result("999998");
  ASSERT_EQ(n1.SUB_NN_N(n2), result);
}

// Òåñòû äëÿ ïðîâåðêè MUL_Nk_N()
TEST(MUL_Nk_N, Subtest_1) {
  // Òåñò äëÿ íåíóëåâîãî ÷èñëà è 10^k, ãäå k > 0
  NaturalNumber n1("32");
  unsigned long long k = 19;
  NaturalNumber result("320000000000000000000");
  ASSERT_EQ(n1.MUL_Nk_N(k), result);
}

TEST(MUL_Nk_N, Subtest_2) {
  // Òåñò äëÿ íóëåâîãî ÷èñëà
  NaturalNumber n1("0");
  unsigned long long k = 1000;
  std::cout << n1.MUL_Nk_N(k);
  NaturalNumber result("0");
  ASSERT_EQ(n1.MUL_Nk_N(k), result);
}

TEST(MUL_Nk_N, Subtest_3) {
  // Òåñò äëÿ íåíóëåâîãî ÷èñëà è 10^k, ãäå k = 0
  NaturalNumber n1("6987");
  unsigned long long k = 0;
  NaturalNumber result("6987");
  ASSERT_EQ(n1.MUL_Nk_N(k), result);
}

TEST(MUL_Nk_N, Subtest_4) {
  // Òåñò äëÿ íåíóëåâîãî ÷èñëà è 10^k, ãäå k = 1
  NaturalNumber n1("43291");
  unsigned long long k = 1;
  NaturalNumber result("432910");
  ASSERT_EQ(n1.MUL_Nk_N(k), result);
}

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