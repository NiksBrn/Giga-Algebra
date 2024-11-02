#include <iostream>
#include <gtest/gtest.h>
#include "../headers/NaturalNumber.h"

// Тесты для проверки NZER_N_B()
TEST(NZER_N_B,Subtest_1) {
    // Тест для ненулевого числа
    NaturalNumber n("12345");
    EXPECT_TRUE(n.NZER_N_B());
}

TEST(NZER_N_B,Subtest_2) {
    // Тест для нулевого числа
    NaturalNumber n("0");
    EXPECT_FALSE(n.NZER_N_B());
}

// Тесты для проверки COM_NN_D()
TEST(COM_NN_D,Subtest_3) {
    // Тест для чисел с одинаковой разрядностью, где второе больше первого
    NaturalNumber n1("100");
    NaturalNumber n2("300");
    EXPECT_EQ(n1.COM_NN_D(n2), LESS);
}

TEST(COM_NN_D,Subtest_4) {
    // Тест для чисел с одинаковой разрядностью, где первое больше второго
    NaturalNumber n1("478");
    NaturalNumber n2("420");
    EXPECT_EQ(n1.COM_NN_D(n2), GREATER);
}

TEST(COM_NN_D,Subtest_5) {
    // Тест для равных чисел с одинаковой разрядностью
    NaturalNumber n1("666000");
    NaturalNumber n2("666000");
    EXPECT_EQ(n1.COM_NN_D(n2), EQUAL);
}

TEST(COM_NN_D,Subtest_6) {
    // Тест для чисел с разной разрядностью, где первое больше второго
    NaturalNumber n1("12456666599");
    NaturalNumber n2("666599");
    EXPECT_EQ(n1.COM_NN_D(n2), GREATER);
}

TEST(COM_NN_D,Subtest_7) {
    // Тест для чисел с разной разрядностью, где второе больше первого
    NaturalNumber n1("9");
    NaturalNumber n2("35409");
    EXPECT_EQ(n1.COM_NN_D(n2), LESS);
}

// Тесты для проверки ADD_1N_N()
TEST(ADD_1N_N,Subtest_8) {
    // Тест для числа без изменения разрядности
    NaturalNumber n("777");
    n.ADD_1N_N();
    EXPECT_EQ(n, "778");
}

TEST(ADD_1N_N,Subtest_9) {
    // Тест для числа со сменой разрядности
    NaturalNumber n("999");
    n.ADD_1N_N();
    EXPECT_EQ(n, "1000");
}

// Тесты для проверки ADD_NN_N()
TEST(ADD_NN_N,Subtest_10) {
    // Тест для чисел без смены разрядности
    NaturalNumber n1("123");
    NaturalNumber n2("456");
    EXPECT_EQ(n1.ADD_NN_N(n2), "579");
}

TEST(ADD_NN_N,Subtest_11) {
    // Тест для чисел со сменой разрядности
    NaturalNumber n1("4567356");
    NaturalNumber n2("8955787");
    EXPECT_EQ(n1.ADD_NN_N(n2), "13523143");
}

// Тесты для проверки MUL_ND_N()
TEST(MUL_ND_N,Subtest_12) {
    // Тест для двухзначного числа без смены разрядности
    NaturalNumber n("12");
    char c;
    c=(3); 
    EXPECT_EQ(n.MUL_ND_N(c), "36");
}

TEST(MUL_ND_N,Subtest_13) {
    // Тест для двухзначного числа со сменой разрядности
    NaturalNumber n("35");
    char c;
    c=(4);
    EXPECT_EQ(n.MUL_ND_N(c), "140");
}

TEST(MUL_ND_N,Subtest_14) {
    // Тест для однозначного числа со сменой разрядности
    NaturalNumber n("3");
    char c;
    c=(4);
    EXPECT_EQ(n.MUL_ND_N(c), "12");
}
TEST(MUL_ND_N,Subtest_15) {
    // Тест для однозначного числа без смены разрядности
    NaturalNumber n("3");
    char c;
    c=(3);
    EXPECT_EQ(n.MUL_ND_N(c), "9");
}
TEST(MUL_ND_N,Subtest_16) {
    // Тест для умножения на 0
    NaturalNumber n("12");
    char c;
    c=(0);
    EXPECT_EQ(n.MUL_ND_N(c), "0");
}

// Тесты для проверки SUB_NN_N()
TEST(SUB_NN_N,Subtest_17) {
    // Тест для разных чисел без смены разрядности
    NaturalNumber n1("60");
    NaturalNumber n2("50");
    EXPECT_EQ(n1.SUB_NN_N(n2), "10");
}

TEST(SUB_NN_N,Subtest_18) {
    // Тест для разных чисел со сменой разрядности
    NaturalNumber n1("160");
    NaturalNumber n2("85");
    EXPECT_EQ(n1.SUB_NN_N(n2), "75");
}

// Тесты для проверки MUL_Nk_N()
TEST(MUL_Nk_N,Subtest_19) {
    // Тест для ненулевого числа и 10^k, где k > 0
    NaturalNumber n1("32");
    NaturalNumber k("10");
    EXPECT_EQ(n1.MUL_Nk_N(k), "320000000000");
}

TEST(MUL_Nk_N,Subtest_20) {
    // Тест для нулевого числа
    NaturalNumber n1("0");
    NaturalNumber k("100000000000");
    EXPECT_EQ(n1.MUL_Nk_N(k), "0");
}

TEST(MUL_Nk_N,Subtest_21) {
    // Тест для ненулевого числа и 10^k, где k = 0
    NaturalNumber n1("6987");
    NaturalNumber k("1");
    EXPECT_EQ(n1.MUL_Nk_N(k), "6987");
}
