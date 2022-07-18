//
// Created by Francesco Taccetti on 13/07/2022.
//

#ifndef TACCETTIELABORATO_SWORDMAN_H
#define TACCETTIELABORATO_SWORDMAN_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include <memory>
#include "GameCharacter.h"
using namespace sf;

class Swordman: public GameCharacter{
public:
    Swordman();
    virtual ~Swordman(){};
    void attack() override;
    void update() override;
    void draw(std::shared_ptr<RenderWindow> & window) override;
    bool handleEnemyCollision(GameCharacter *enemy) override;


private:

};


#endif //TACCETTIELABORATO_SWORDMAN_H
