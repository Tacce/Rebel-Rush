//
// Created by Francesco Taccetti on 14/07/2022.
//

#include <iostream>
#include "Map.h"


Map::Map(std::shared_ptr<GameCharacter> player1):player(std::move(player1)),enemiesSpawnCoolDown(ENEMY_COOLDOWN) {}

void Map::draw(const std::shared_ptr<RenderWindow>& window) {
    player->draw(const_cast<std::shared_ptr<RenderWindow> &>(window));
    for(auto & enemy : enemies)
        enemy.draw(const_cast<std::shared_ptr<RenderWindow> &>(window));
}

void Map::update() {
    player->update();
    if(enemiesSpawnCoolDown>=ENEMY_COOLDOWN){
        enemiesSpawnCoolDown=0;
        enemies.emplace_back();
    }
    for (size_t j=0; j<enemies.size();j++){
        enemies[j].update();
        if(enemies[j].getPosX()<-ENEMY_DIMENSIONS)
            enemies.erase(enemies.begin()+j);
    }
    enemiesSpawnCoolDown++;
}
