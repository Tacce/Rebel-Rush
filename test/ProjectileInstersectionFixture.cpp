//
// Created by Francesco Taccetti on 18/07/2022.
//
#include "gtest/gtest.h"
#include "../Map.h"

class ProjectileIntersection : public ::testing::Test {
protected:
    void SetUp() override {
        Test::SetUp();
        p1.setPosX(200);
        p1.setPosY(300);
        p2.setPosX(100);
        p2.setPosY(400);
        projectiles.push_back(p1);
        projectiles.push_back(p2);
        g->setProjectiles(projectiles);
        m=new Map(g);
        e.setPosX(240);
        e.setPosY(300);
        enemies.push_back(e);
        m->setEnemies(enemies);
        m->setEnemiesSpawnCoolDown(0);
        g->setScore(0);
    }
    Map* m;
    std::shared_ptr<Gunfighter> g = std::make_shared<Gunfighter>();
    std::vector<Projectile> projectiles;
    Projectile p1,p2;
    Enemy e;
    std::vector<Enemy> enemies;
};

TEST_F(ProjectileIntersection, DamageTest){
    ASSERT_EQ(2,g->getProjectiles().size());
    ASSERT_EQ(1,m->getEnemies().size());
    m->update();
    //The enemy is dead, the projectile that hit him is disappeared and the other projectile moved forward
    ASSERT_EQ(0,m->getEnemies().size());
    ASSERT_EQ(1,g->getProjectiles().size());
    ASSERT_EQ(100 + PROJECTILE_SPEED,g->getProjectiles()[0].getPosX());
    ASSERT_EQ(400,g->getProjectiles()[0].getPosY());
    ASSERT_FLOAT_EQ(POINTS_MULTIPLIER+ POINTS_FOR_FRAME,g->getScore());
}

