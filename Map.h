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
using namespace sf;

class Map {
public:
    explicit Map(std::shared_ptr<GameCharacter> player1);
    void draw(const std::shared_ptr<RenderWindow>& window);
    void update();

private:
    std::shared_ptr<GameCharacter> player;
};


#endif //TACCETTIELABORATO_MAP_H
