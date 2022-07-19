//
// Created by Francesco Taccetti on 19/07/2022.
//
#include "gtest/gtest.h"
#include "../Map.h"
class SwordIntersection : public ::testing::Test {
protected:
    void SetUp() override {
        Test::SetUp();
        m=new Map(s);
        e.setPosX(300);
        e.setPosY(300);
        enemies.push_back(e);
        m->setEnemies(enemies);
        m->setEnemiesSpawnCoolDown(0);
        s->setIsAttacking(true);
        s->setPosX(239);
        s->setPosY(300);
    }
    Map* m;
    std::shared_ptr<Swordman> s = std::make_shared<Swordman>();
    Sword w;
    Enemy e;
    std::vector<Enemy> enemies;
};

TEST_F(SwordIntersection, DamageTest){
    ASSERT_EQ(1,m->getEnemies().size());
    ASSERT_EQ(3,s->getHp());
    m->update();
    ASSERT_EQ(0,m->getEnemies().size());
    ASSERT_TRUE(s->isAttacking1());
    ASSERT_EQ(3,s->getHp());
}

