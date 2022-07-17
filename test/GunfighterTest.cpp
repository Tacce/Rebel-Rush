//
// Created by Francesco Taccetti on 13/07/2022.
//
#include "gtest/gtest.h"
#include "../Gunfighter.h"
#include "../Gunfighter.cpp"
#include "../Projectile.cpp"

TEST(Gunfighter, DefaultConstructor) {
    Gunfighter g;
    ASSERT_EQ(0, g.getPosY());
    ASSERT_EQ(3,g.getHp());
    ASSERT_EQ(PROJECTILE_COOLDOWN, g.getShootingCooldown());
    ASSERT_FALSE(g.isShielded1());
}

TEST(Gunfighter, Jump){
    Gunfighter g;
    g.jump();
    ASSERT_EQ(JUMP_FORCE,g.getYVelocity());
    ASSERT_EQ(0,g.getMovementClock().getElapsedTime().asSeconds());
}

TEST(Gunfighter,Attack){
    Gunfighter g;
    g.attack();
    ASSERT_EQ(1,g.getProjectiles().size());
    g.attack();
    ASSERT_EQ(1,g.getProjectiles().size());
}
