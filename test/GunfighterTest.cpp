//
// Created by Francesco Taccetti on 13/07/2022.
//
#include "gtest/gtest.h"
#include "../Gunfighter.h"

TEST(Gunfighter, DefaultConstructor) {
    Gunfighter g;
    ASSERT_EQ(0, g.getPosY());
    ASSERT_EQ(3,g.getHp());
    ASSERT_EQ(PROJECTILE_COOLDOWN, g.getShootingCooldown());
    ASSERT_FALSE(g.isShielded());
}

TEST(Gunfighter, Jump){
    Gunfighter g;
    g.jump();
    ASSERT_EQ(JUMP_FORCE,g.getYVelocity());
    EXPECT_NEAR(0,g.getMovementClock().getElapsedTime().asSeconds(), 0.001);
}

TEST(Gunfighter,Attack){
    Gunfighter g;
    g.attack();
    ASSERT_EQ(1,g.getProjectiles().size());
    //Cannot create another projectile because of the cooldown
    g.attack();
    ASSERT_EQ(1,g.getProjectiles().size());
}
