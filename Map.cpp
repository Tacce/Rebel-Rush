//
// Created by Francesco Taccetti on 14/07/2022.
//

#include <iostream>
#include "Map.h"


Map::Map(std::shared_ptr<GameCharacter> player1):player(std::move(player1)), shield(nullptr), enemiesSpawnCoolDown(ENEMY_COOLDOWN),
obstacleSpawnCoolDown(OBSTACLE_COOLDOWN), level(0) {}

void Map::draw(const std::shared_ptr<RenderWindow>& window) {
    player->draw(const_cast<std::shared_ptr<RenderWindow> &>(window));
    for(auto & enemy : enemies)
        enemy.draw(const_cast<std::shared_ptr<RenderWindow> &>(window));
    for(auto & obstacle : obstacles)
        obstacle.draw(const_cast<std::shared_ptr<RenderWindow> &>(window));
    if(shield!= nullptr)
        shield->draw(const_cast<std::shared_ptr<RenderWindow> &>(window));
}

void Map::update() {
    player->update();
    level=player->getScore()/1000;
    enemiesUpdate();
    obstaclesUpdate();
    shieldUpdate();
}


void Map::enemiesUpdate() {
    if(enemiesSpawnCoolDown>=ENEMY_COOLDOWN){
        enemiesSpawnCoolDown=0;
        enemies.emplace_back(Enemy(ENEMY_SPEED + level ));
    }
    for (size_t i=0; i < enemies.size(); i++) {
        enemies[i].update();
        if(player->handleEnemyCollision(&(enemies[i])) || enemies[i].getPosX() < -ENEMY_DIMENSIONS)
            enemies.erase(enemies.begin() + i);
    }
    enemiesSpawnCoolDown += 1 + level/5;
}

void Map::obstaclesUpdate() {
    if(obstacleSpawnCoolDown>=OBSTACLE_COOLDOWN && player->getScore()>1000) {
        obstacleSpawnCoolDown = 0;
        obstacles.emplace_back(Obstacle(OBSTACLE_SPEED + level - 1 ));
    }
    for (size_t i=0; i < obstacles.size(); i++) {
        obstacles[i].update();
        player->handleObstacleCollision(obstacles[i]);
        if(obstacles[i].getPosX() < -OBSTACLE_DIMENSION)
            obstacles.erase(obstacles.begin() + i);
    }
    obstacleSpawnCoolDown += 1+ (level-1)/2;
}

void Map::shieldUpdate() {
    if (!player->isShielded() && player->getHp()!=0 && shield == nullptr && !(rand() % (1000 * player->getHp())))
        shield = std::make_shared<Shield>();
    if (shield != nullptr) {
        shield->update();
        if(shield->getPosX() < -SHIELD_RADIUS*2 || player->handleShieldCollision(shield))
            shield= nullptr;
    }
}
const std::shared_ptr<GameCharacter> &Map::getPlayer() const {
    return player;
}

void Map::setPlayer(const std::shared_ptr<GameCharacter> &player) {
    Map::player = player;
}

const std::vector<Enemy> &Map::getEnemies() const {
    return enemies;
}

void Map::setEnemies(const std::vector<Enemy> &enemies) {
    Map::enemies = enemies;
}

int Map::getEnemiesSpawnCoolDown() const {
    return enemiesSpawnCoolDown;
}

void Map::setEnemiesSpawnCoolDown(int enemiesSpawnCoolDown) {
    Map::enemiesSpawnCoolDown = enemiesSpawnCoolDown;
}

void Map::setObstacleSpawnCoolDown(int obstacleSpawnCoolDown) {
    Map::obstacleSpawnCoolDown = obstacleSpawnCoolDown;
}

void Map::setObstacles(const std::vector<Obstacle> &obstacles) {
    Map::obstacles = obstacles;
}

const std::vector<Obstacle> &Map::getObstacles() const {
    return obstacles;
}


