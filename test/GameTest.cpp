//
// Created by Francesco Taccetti on 16/07/2022.
//

#include "gtest/gtest.h"
#include "../Game.h"
#include "../Game.cpp"
#include "../Map.cpp"
#include "../Enemy.cpp"

TEST(Game,GameOver){
    Game g;
    g.getPlayer()->setHp(3);
    ASSERT_FALSE(g.isGameOvered());
    g.getPlayer()->setHp(0);
    g.update();
    ASSERT_TRUE(g.isGameOvered());
}