#include <iostream>
#include <gtest/gtest.h>
#include "../headers/NaturalNumber.h"

TEST(COM_NN_D, Subtest_1) {
    NaturalNumber n1("123");
    NaturalNumber n2 ("456");
    ASSERT_EQ(n1.COM_NN_D(n2), LESS);
}
