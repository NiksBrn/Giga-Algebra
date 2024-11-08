#include <iostream>
#include <gtest/gtest.h>
#include "../headers/NaturalNumber.h"

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
TEST(COM_NN_D, Subtest_3) {
    // Òåñò äëÿ ÷èñåë ñ îäèíàêîâîé ðàçðÿäíîñòüþ, ãäå âòîðîå áîëüøå ïåðâîãî
    NaturalNumber n1("100");
    NaturalNumber n2("310");
    
    ASSERT_EQ(n1.COM_NN_D(n2), LESS);
}

TEST(COM_NN_D, Subtest_4) {
    // Òåñò äëÿ ÷èñåë ñ îäèíàêîâîé ðàçðÿäíîñòüþ, ãäå ïåðâîå áîëüøå âòîðîãî
    NaturalNumber n1("478");
    NaturalNumber n2("420");
    ASSERT_EQ(n1.COM_NN_D(n2), GREATER);
}

TEST(COM_NN_D, Subtest_5) {
    // Òåñò äëÿ ðàâíûõ ÷èñåë ñ îäèíàêîâîé ðàçðÿäíîñòüþ
    NaturalNumber n1("666000");
    NaturalNumber n2("666000");
    ASSERT_EQ(n1.COM_NN_D(n2), EQUAL);
}

TEST(COM_NN_D, Subtest_6) {
    // Òåñò äëÿ ÷èñåë ñ ðàçíîé ðàçðÿäíîñòüþ, ãäå ïåðâîå áîëüøå âòîðîãî
    NaturalNumber n1("12456666599");
    NaturalNumber n2("666599");
    ASSERT_EQ(n1.COM_NN_D(n2), GREATER);
}

TEST(COM_NN_D, Subtest_7) {
    // Òåñò äëÿ ÷èñåë ñ ðàçíîé ðàçðÿäíîñòüþ, ãäå âòîðîå áîëüøå ïåðâîãî
    NaturalNumber n1("9");
    NaturalNumber n2("35409");
    ASSERT_EQ(n1.COM_NN_D(n2), LESS);
}

TEST(COM_NN_D, new_1) {
// Òåñò äëÿ ÷èñåë ñ ðàçíîé ðàçðÿäíîñòüþ, ãäå âòîðîå áîëüøå ïåðâîãî
NaturalNumber n1("0");
NaturalNumber n2("9");
ASSERT_EQ(n1.COM_NN_D(n2), LESS);
}


// Òåñòû äëÿ ïðîâåðêè ADD_1N_N()
TEST(ADD_1N_N, Subtest_8) {
    // Òåñò äëÿ ÷èñëà áåç èçìåíåíèÿ ðàçðÿäíîñòè
    NaturalNumber n1("777");
    NaturalNumber n2("778");
    n1.ADD_1N_N();
    ASSERT_EQ(n1.ADD_1N_N(), n2);
}

TEST(ADD_1N_N, Subtest_9) {
    // Òåñò äëÿ ÷èñëà ñî ñìåíîé ðàçðÿäíîñòè
    NaturalNumber n1("999");
    NaturalNumber n2("1000");
    n1.ADD_1N_N();
    ASSERT_EQ(n1, n2);
}

// Òåñòû äëÿ ïðîâåðêè ADD_NN_N()
TEST(ADD_NN_N, Subtest_10) {
    // Òåñò äëÿ ÷èñåë áåç ñìåíû ðàçðÿäíîñòè
    NaturalNumber n1("123");
    NaturalNumber n2("456");
    NaturalNumber result("579");
    ASSERT_EQ(n1.ADD_NN_N(n2), result);
}

TEST(ADD_NN_N, Subtest_11) {
    // Òåñò äëÿ ÷èñåë ñî ñìåíîé ðàçðÿäíîñòè
    NaturalNumber n1("4567356");
    NaturalNumber n2("8955787");
    NaturalNumber result("13523143");
    ASSERT_EQ(n1.ADD_NN_N(n2), result);
}

// Òåñòû äëÿ ïðîâåðêè MUL_ND_N()
TEST(MUL_ND_N, Subtest_12) {
    // Òåñò äëÿ äâóõçíà÷íîãî ÷èñëà áåç ñìåíû ðàçðÿäíîñòè
    NaturalNumber n("12");
    char c;
    c = (3);
    NaturalNumber result("36");
    ASSERT_EQ(n.MUL_ND_N(c), result);
}

TEST(MUL_ND_N, Subtest_13) {
    // Òåñò äëÿ äâóõçíà÷íîãî ÷èñëà ñî ñìåíîé ðàçðÿäíîñòè
    NaturalNumber n("35");
    char c;
    c = (4);
    NaturalNumber result("140");
    ASSERT_EQ(n.MUL_ND_N(c), result);
}

TEST(MUL_ND_N, Subtest_14) {
    // Òåñò äëÿ îäíîçíà÷íîãî ÷èñëà ñî ñìåíîé ðàçðÿäíîñòè
    NaturalNumber n("3");
    char c;
    c = (4);
    NaturalNumber result("12");
    ASSERT_EQ(n.MUL_ND_N(c), result);
}
TEST(MUL_ND_N, Subtest_15) {
    // Òåñò äëÿ îäíîçíà÷íîãî ÷èñëà áåç ñìåíû ðàçðÿäíîñòè
    NaturalNumber n("3");
    char c;
    c = (3);
    NaturalNumber result("9");
    ASSERT_EQ(n.MUL_ND_N(c), result);
}
TEST(MUL_ND_N, Subtest_16) {
    // Òåñò äëÿ óìíîæåíèÿ íà 0
    NaturalNumber n("12");
    char c;
    c = (0);
    NaturalNumber result("0");
    ASSERT_EQ(n.MUL_ND_N(c), result);
}

// Òåñòû äëÿ ïðîâåðêè SUB_NN_N()
TEST(SUB_NN_N, Subtest_17) {
    // Òåñò äëÿ ðàçíûõ ÷èñåë áåç ñìåíû ðàçðÿäíîñòè
    NaturalNumber n1("60");
    NaturalNumber n2("50");
    NaturalNumber result("10");
    ASSERT_EQ(n1.SUB_NN_N(n2), result);
}

TEST(SUB_NN_N, Subtest_18) {
    // Òåñò äëÿ ðàçíûõ ÷èñåë ñî ñìåíîé ðàçðÿäíîñòè
    NaturalNumber n1("160");
    NaturalNumber n2("85");
    NaturalNumber result("075");
    ASSERT_EQ(n1.SUB_NN_N(n2), result);
}

// Òåñòû äëÿ ïðîâåðêè MUL_Nk_N()
TEST(MUL_Nk_N, Subtest_19) {
    // Òåñò äëÿ íåíóëåâîãî ÷èñëà è 10^k, ãäå k > 0
    NaturalNumber n1("32");
    NaturalNumber k("19");
    NaturalNumber result("320000000000000000000");
    ASSERT_EQ(n1.MUL_Nk_N(k), result);
}

TEST(MUL_Nk_N, Subtest_20) {
    // Òåñò äëÿ íóëåâîãî ÷èñëà
    NaturalNumber n1("0");
    NaturalNumber k("1000");
    NaturalNumber result("0");
    ASSERT_EQ(n1.MUL_Nk_N(k), result);
}

TEST(MUL_Nk_N, Subtest_21) {
    // Òåñò äëÿ íåíóëåâîãî ÷èñëà è 10^k, ãäå k = 0
    NaturalNumber n1("6987");
    NaturalNumber k("1");
    NaturalNumber result("69870");
    ASSERT_EQ(n1.MUL_Nk_N(k), result);
}
