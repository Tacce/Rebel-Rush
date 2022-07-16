//
// Created by Francesco Taccetti on 13/07/2022.
//
#include "gtest/gtest.h"
#include "../Swordman.h"
#include "../Swordman.cpp"

TEST(Swordman, DefaultConstructor) {
    Swordman c;
    ASSERT_EQ(0, c.getPosY());
    ASSERT_EQ(3,c.getHp());
    ASSERT_FALSE(c.isShielded1());
}
