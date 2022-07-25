//
// Created by Francesco Taccetti on 13/07/2022.
//
#include "gtest/gtest.h"
#include "../Swordman.h"
#include "../Swordman.cpp"
#include "../Sword.cpp"

TEST(Swordman, DefaultConstructor) {
    Swordman s;
    ASSERT_EQ(0, s.getPosY());
    ASSERT_EQ(3,s.getHp());
    ASSERT_FALSE(s.isShielded());
}

TEST(Swordman, Jump){
    Swordman s;
    s.jump();
    ASSERT_EQ(JUMP_FORCE,s.getYVelocity());
    EXPECT_NEAR(0,s.getMovementClock().getElapsedTime().asSeconds(),0.001);
}

TEST(Swordman,Attack){
    Swordman s;
    s.attack();
    ASSERT_TRUE(s.isAttacking());
    s.setSwordCoolDown(SWORD_COOLDOWN);
    //After the attack cooldown, the player can attack again
    s.update();
    ASSERT_FALSE(s.isAttacking());
}