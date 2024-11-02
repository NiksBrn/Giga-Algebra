#include <gtest/gtest.h>
#include "NaturalNumber.h"

// ����� ��� �������� NZER_N_B()
TEST(NaturalNumberTests, NZER_N_B) {
    NaturalNumber n1;

    // ���� ��� ���������� �����
    n1.get_num(12345);
    EXPECT_TRUE(n1.NZER_N_B());

    // ���� ��� �������� �����
    n1.get_num(0);
    EXPECT_FALSE(n1.NZER_N_B());
}

// ����� ��� �������� COM_NN_D()
TEST(NaturalNumberTests, COM_NN_D) {
    NaturalNumber n1, n2;

    // ���� ��� ����� � ���������� ������������, ��� ������ ������ �������
    n1.get_num(100);
    n2.get_num(300);
    EXPECT_EQ(n1.COM_NN_D(n2), LESS);

    // ���� ��� ����� � ���������� ������������, ��� ������ ������ �������
    n1.get_num(478);
    n2.get_num(420);
    EXPECT_EQ(n1.COM_NN_D(n2), GREATER);

    // ���� ��� ������ ����� � ���������� ������������
    n1.get_num(666000);
    n2.get_num(666000);
    EXPECT_EQ(n1.COM_NN_D(n2), EQUAL);

    // ���� ��� ����� � ������ ������������, ��� ������ ������ �������
    n1.get_num(12456666599);
    n2.get_num(666599);
    EXPECT_EQ(n1.COM_NN_D(n2), GREATER);

    // ���� ��� ����� � ������ ������������, ��� ������ ������ �������
    n1.get_num(9);
    n2.get_num(35409);
    EXPECT_EQ(n1.COM_NN_D(n2), LESS);
}

// ����� ��� �������� ADD_1N_N()
TEST(NaturalNumberTests, ADD_1N_N) {
    NaturalNumber n;

    // ���� ��� ����� ��� ��������� �����������
    n.get_num(777);
    n.ADD_1N_N();
    EXPECT_EQ(n.ADD_1N_N(), 778);

    // ���� ��� ����� �� ������ �����������
    n.get_num(999);
    n.ADD_1N_N();
    EXPECT_EQ(n.ADD_1N_N(), 1000);
}

// ����� ��� �������� ADD_NN_N()
TEST(NaturalNumberTests, ADD_NN_N) {
    NaturalNumber n1, n2, result;

    // ���� ��� ����� ��� ����� �����������
    n1.get_num(123);
    n2.get_num(456);
    result.ADD_NN_N(n2);
    EXPECT_EQ(result.ADD_1N_N(), 579);

    // ���� ��� ����� �� ������ �����������
    n1.get_num(4567356);
    n2.get_num(8955787);
    result.ADD_NN_N(n2);
    EXPECT_EQ(result.ADD_1N_N(), 13523143);
}

// ����� ��� �������� MUL_ND_N()
TEST(NaturalNumberTests, MUL_ND_N) {
    NaturalNumber n;

    // ���� ��� ������������ ����� ��� ����� �����������
    n.get_num(12);
    n.MUL_ND_N(3);
    EXPECT_EQ(n.MUL_ND_N(), 36);

    // ���� ��� ������������ ����� �� ������ �����������
    n.get_num(35);
    n.MUL_ND_N(4);
    EXPECT_EQ(n.MUL_ND_N(), 140);

    // ���� ��� ������������ ����� �� ������ �����������
    n.get_num(3);
    n.MUL_ND_N(4);
    EXPECT_EQ(n.MUL_ND_N(), 12);

    // ���� ��� ������������ ����� ��� ����� �����������
    n.get_num(3);
    n.MUL_ND_N(3);
    EXPECT_EQ(n.MUL_ND_N(), 9);

    // ���� ��� ��������� �� 0
    n.get_num(12);
    n.MUL_ND_N(0);
    EXPECT_EQ(n.MUL_ND_N(), 0);
}

// ����� ��� �������� SUB_NN_N()
TEST(NaturalNumberTests, SUB_NN_N) {
    NaturalNumber n1, n2, result;

    // ���� ��� ������ ����� ��� ����� �����������
    n1.get_num(60);
    n2.get_num(50);
    result.SUB_NN_N(n2);
    EXPECT_EQ(result.SUB_NN_N(), 10);

    // ���� ��� ������ ����� �� ������ �����������
    n1.get_num(160);
    n2.get_num(85);
    result.SUB_NN_N(n2);
    EXPECT_EQ(result.SUB_NN_N(), 75);
}

// ����� ��� �������� MUL_Nk_N()
TEST(NaturalNumberTests, MUL_Nk_N) {
    NaturalNumber n1, k;

    // ���� ��� ���������� ����� � 10^k, ��� k > 0
    n1.get_num(32);
    k.get_num(10);
    EXPECT_TRUE(n1.MUL_Nk_N(k), 320000000000);

    // ���� ��� �������� �����
    n1.get_num(0);
    k.get_num(100000000000);
    EXPECT_TRUE(n1.MUL_Nk_N(k), 0);

    // ���� ��� ���������� ����� � 10^k, ��� k = 0
    n1.get_num(6987);
    k.get_num(1);
    EXPECT_TRUE(n1.MUL_Nk_N(k), 6987);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
