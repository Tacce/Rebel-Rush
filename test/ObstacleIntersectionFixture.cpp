//
// Created by Francesco Taccetti on 11/08/2022.
//
#include "gtest/gtest.h"
#include "../Map.h"

class ObstacleIntersection : public ::testing::Test {
protected:
    void SetUp() override {
        Test::SetUp();
        g->setPosY(30);
        s->setPosY(30);
        s->setShielded(true);
        ob.setPosX(PLAYER_POSX);
        obstacles.push_back(ob);
        m=new Map(g);
        m->setObstacleSpawnCoolDown(0);
        m->setObstacles(obstacles);
    }
    Map* m;
    std::shared_ptr<Gunfighter> g = std::make_shared<Gunfighter>();
    std::shared_ptr<Swordman> s = std::make_shared<Swordman>();
    std::vector<Obstacle> obstacles;
    Obstacle ob;
};

TEST_F(ObstacleIntersection, DamageTest){
    ASSERT_EQ(1,m->getObstacles().size());
    ASSERT_EQ(3,g->getHp());
    m->update();
    ASSERT_EQ(1,m->getObstacles().size());
    ASSERT_EQ(0,g->getHp());
}

TEST_F(ObstacleIntersection, ShieldTest){
    m->setPlayer(s);
    ASSERT_EQ(1,m->getObstacles().size());
    ASSERT_EQ(3,s->getHp());
    m->update();
    ASSERT_TRUE(m->getObstacles()[0].isAlreadyHit());
    ASSERT_EQ(1,m->getObstacles().size());
    ASSERT_EQ(3,s->getHp());
}

