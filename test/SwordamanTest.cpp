//
// Created by Francesco Taccetti on 13/07/2022.
//
#include "gtest/gtest.h"
#include "../Swordman.h"
#include "../Swordman.cpp"

TEST(Swordman, DefaultConstructor) {
    Swordman s;
    ASSERT_EQ(0, s.getPosY());
    ASSERT_EQ(3,s.getHp());
    ASSERT_FALSE(s.isShielded1());
}

TEST(Swordman, Jump){
    Swordman s;
    s.jump();
    ASSERT_EQ(JUMP_FORCE,s.getYVelocity());
    ASSERT_FLOAT_EQ(0,s.getMovementClock().getElapsedTime().asSeconds());
}