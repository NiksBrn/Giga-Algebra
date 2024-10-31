#include <gtest/gtest.h>
#include "NaturalNumber.h"

TEST(NaturalNumberTests, NZER_N_B) {
    //���� 1: ����������� ���� ��� ���������� �����
    NaturalNumber n1;
    n1.add(12345);
    EXPECT_TRUE(n1.NZER_N_B(), true);

    //���� 2: ����������� ���� ��� �������� �����
    NaturalNumber n1;
    n1.add(0);
    EXPECT_TRUE(n1.NZER_N_B(), false);
}

TEST(NaturalNumberTests, COM_NN_D) {
    //���� 1: ����������� ���� ��� ���� ����� � ���������� ������������, ��� ������ ������ �������
    NaturalNumber n1, n2, n3;
    n1.add(100);
    n2.add(300);
    EXPECT_EQ(n1.COM_NN_D(n2),1);

    //���� 2: ����������� ���� ��� ���� ����� � ���������� ������������, ��� ������ ������ �������
    NaturalNumber n1, n2, n3;
    n1.add(478);
    n2.add(420);
    EXPECT_EQ(n1.COM_NN_D(n2), 2);

    //���� 3: ����������� ���� ��� ���� ������ ����� � ���������� ������������
    NaturalNumber n1, n2, n3;
    n1.add(666000);
    n2.add(666000);
    EXPECT_EQ(n1.COM_NN_D(n2), 0);

    //���� 4: ����������� ���� ��� ���� ����� � ������ ������������, ��� ������ ������ �������
    NaturalNumber n1, n2, n3;
    n1.add(12456666599);
    n2.add(666599);
    EXPECT_EQ(n1.COM_NN_D(n2), 2);

    //���� 4: ����������� ���� ��� ���� ����� � ������ ������������, ��� ������ ������ �������
    NaturalNumber n1, n2, n3;
    n1.add(9);
    n2.add(35409);
    EXPECT_EQ(n1.COM_NN_D(n2), 1);
}

TEST(NaturalNumberTests, ADD_1N_N) {
    ///���� 1: ����������� ���� ��� ����� �� ������ ����������� 
    NaturalNumber n;
    n.add(999);
    n.ADD_1N_N();
    EXPECT_EQ(n.get_value(), 10000);

    ///���� 1: ����������� ���� ��� ����� ��� ����� ����������� 
    NaturalNumber n;
    n.add(777);
    n.ADD_1N_N();
    EXPECT_EQ(n.get_value(), 778);
}

TEST(NaturalNumberTests, ADD_NN_N) {
    ///���� 1: ����������� ���� ��� ���� ����� ��� ����� �����������
    NaturalNumber n1, n2, result;
    n1.add(123);
    n2.add(456);
    result.ADD_NN_N(n2);
    EXPECT_EQ(result.get_value(), 579);

    ///���� 1: ����������� ���� ��� ���� ����� �� ������ �����������
    NaturalNumber n1, n2, result;
    n1.add(4567356);
    n2.add(8955787);
    result.ADD_NN_N(n2);
    EXPECT_EQ(result.get_value(), 579);
}

TEST(NaturalNumberTests, MUL_ND_N) {
    //���� 1: ����������� ������ ��� ����������� ����� ��� ����� �����������
    NaturalNumber n;
    n.add(12);
    n.MUL_ND_N(3);
    EXPECT_EQ(n.get_value(), 36);

    //���� 2: ����������� ������ ��� ����������� ����� �� ������ �����������
    NaturalNumber n;
    n.add(35);
    n.MUL_ND_N(4);
    EXPECT_EQ(n.get_value(), 140);

    //���� 3: ����������� ������ ��� ������������ ����� �� ������ �����������
    NaturalNumber n;
    n.add(3);
    n.MUL_ND_N(4);
    EXPECT_EQ(n.get_value(), 12);

    //���� 4: ����������� ������ ��� ������������ ����� ��� ����� �����������
    NaturalNumber n;
    n.add(3);
    n.MUL_ND_N(3);
    EXPECT_EQ(n.get_value(), 9);

    //���� 5: ��������� �� 0
    NaturalNumber n;
    n.add(12);
    n.MUL_ND_N(0);
    EXPECT_EQ(n.get_value(), 0);
}

TEST(NaturalNumberTests, SUB_NN_N) {
    ///���� 1: ����������� ������ ��� ������ ����� ��� ����� �����������
    NaturalNumber n1, n2, result;
    n1.add(60);
    n2.add(50);
    result.SUB_NN_N(n2);
    EXPECT_EQ(result.get_value(), 10);

    ///���� 2: ����������� ������ ��� ������ ����� �� ������ �����������
    NaturalNumber n1, n2, result;
    n1.add(160);
    n2.add(85);
    result.SUB_NN_N(n2);
    EXPECT_EQ(result.get_value(), 75);

    ///���� 3: ����������� ������ ��� ������ ����� �� ������ �����������
    NaturalNumber n1, n2, result;
    n1.add(160);
    n2.add(85);
    result.SUB_NN_N(n2);
    EXPECT_EQ(result.get_value(), 75);

    ///���� 3: ����������� ������ ��� ������ ����� �� ������ �����������
    NaturalNumber n1, n2, result;
    n1.add(160);
    n2.add(85);
    result.SUB_NN_N(n2);
    EXPECT_EQ(result.get_value(), 75);
}

TEST(NaturalNumberTests, MUL_Nk_N) {
    //���� 1: ����������� ���� ��� ���������� ����� � 10^K, ��� K > 0
    NaturalNumber n1, k;
    n1.add(32);
    k.add(100);
    EXPECT_TRUE(n1.MUL_Nk_N(k), 3200);

    //���� 2: ����������� ���� ��� �������� �����
    NaturalNumber n1, k;
    n1.add(0);
    k.add(100000000000);
    EXPECT_TRUE(n1.MUL_Nk_N(k), 0);

    //���� 3: ����������� ���� ��� ���������� ����� � 10^K, ��� K = 0
    NaturalNumber n1, k;
    n1.add(6987);
    k.add(1);
    EXPECT_TRUE(n1.MUL_Nk_N(k), 6987);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
