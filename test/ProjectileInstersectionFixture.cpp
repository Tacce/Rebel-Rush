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
        g->setPosY(30);
        g->setProjectiles(projectiles);
        m=new Map(g);
        e.setPosX(240);
        e.setPosY(300);
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
    enemies.push_back(e);
    m->setEnemies(enemies);
    ASSERT_EQ(2,g->getProjectiles().size());
    ASSERT_EQ(1,m->getEnemies().size());
    m->update();
    //The enemy is dead, the projectile that hit him is disappeared and the other projectile moved forward
    ASSERT_EQ(0,m->getEnemies().size());
    ASSERT_EQ(1,g->getProjectiles().size());
    ASSERT_EQ(100 + PROJECTILE_SPEED,g->getProjectiles()[0].getPosX());
    ASSERT_EQ(400,g->getProjectiles()[0].getPosY());
    ASSERT_FLOAT_EQ(POINTS_MULTIPLIER+POINTS_MULTIPLIER/4+ POINTS_FOR_FRAME,g->getScore());
}

TEST_F(ProjectileIntersection, MedicalDamageTest){
    e.setMedical(true);
    enemies.push_back(e);
    m->setEnemies(enemies);
    ASSERT_TRUE(m->getEnemies()[0].isMedical());
    ASSERT_EQ(2,g->getProjectiles().size());
    ASSERT_EQ(1,m->getEnemies().size());
    ASSERT_EQ(3,g->getHp());
    m->update();
    //Player does not get any points and receives damage
    ASSERT_EQ(0,m->getEnemies().size());
    ASSERT_EQ(1,g->getProjectiles().size());
    ASSERT_FLOAT_EQ( POINTS_FOR_FRAME,g->getScore());
    ASSERT_EQ(2,g->getHp());
}

