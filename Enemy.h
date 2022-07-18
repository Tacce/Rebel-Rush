//
// Created by Francesco Taccetti on 17/07/2022.
//

#ifndef TACCETTIELABORATO_ENEMY_H
#define TACCETTIELABORATO_ENEMY_H
#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include <memory>
#include "GameCharacter.h"
using namespace sf;

class Enemy: public GameCharacter {
public:
    explicit Enemy(unsigned int hp=1,float vel=ENEMY_SPEED);
    void update() override;
    void draw(std::shared_ptr<RenderWindow> &window) override;
    void attack() override{};


private:
    float xVelocity;

};


#endif //TACCETTIELABORATO_ENEMY_H
