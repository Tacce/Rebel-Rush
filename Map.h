//
// Created by Francesco Taccetti on 14/07/2022.
//

#ifndef TACCETTIELABORATO_MAP_H
#define TACCETTIELABORATO_MAP_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Definitions.h"
#include "GameCharacter.h"
#include "Gunfighter.h"
#include "Swordman.h"
#include "Enemy.h"
#include "Obstacle.h"
using namespace sf;

class Map {
public:
    explicit Map(std::shared_ptr<GameCharacter> player1);
    void draw(const std::shared_ptr<RenderWindow>& window);
    void update();

    const std::shared_ptr<GameCharacter> &getPlayer() const;
    void setPlayer(const std::shared_ptr<GameCharacter> &player);
    const std::vector<Enemy> &getEnemies() const;
    void setEnemies(const std::vector<Enemy> &enemies);
    int getEnemiesSpawnCoolDown() const;
    void setEnemiesSpawnCoolDown(int enemiesSpawnCoolDown);

private:
    void enemiesUpdate();
    void obstaclesUpdate();


    std::shared_ptr<GameCharacter> player;
    std::vector<Enemy> enemies;
    std::vector<Obstacle> obstacles;
    int enemiesSpawnCoolDown;
    int obstacleSpawnCoolDown;

};


#endif //TACCETTIELABORATO_MAP_H
