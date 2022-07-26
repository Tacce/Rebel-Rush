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
        s->setAttacking(true);
        s->setPosX(200);
        s->setPosY(300);
        s->setScore(0);
    }
    Map* m;
    std::shared_ptr<Swordman> s = std::make_shared<Swordman>();
    Sword w;
    Enemy e;
    std::vector<Enemy> enemies;
};

TEST_F(SwordIntersection, DamageTest){
    s->attack();
    ASSERT_EQ(1,m->getEnemies().size());
    ASSERT_EQ(3,s->getHp());
    m->update();
    //The enemy is dead but the sword is still swinging
    ASSERT_EQ(0,m->getEnemies().size());
    ASSERT_TRUE(s->isAttacking());
    ASSERT_EQ(3,s->getHp());
    ASSERT_FLOAT_EQ(POINTS_MULTIPLIER+ POINTS_FOR_FRAME,s->getScore());
}

