//
// Created by Francesco Taccetti on 14/07/2022.
//

#include "Map.h"


Map::Map(std::shared_ptr<GameCharacter> player1):player(std::move(player1)) {
}

void Map::draw(const std::shared_ptr<RenderWindow>& window) {
    player->draw(const_cast<std::shared_ptr<RenderWindow> &>(window));
}

void Map::update() {
    player->update();
}
