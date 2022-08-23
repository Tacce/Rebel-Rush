//
// Created by Francesco Taccetti on 13/07/2022.
//

#ifndef TACCETTIELABORATO_SWORDMAN_H
#define TACCETTIELABORATO_SWORDMAN_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include <memory>
#include "GameCharacter.h"
#include "Sword.h"
using namespace sf;

class Swordman: public GameCharacter{
public:
    Swordman();
    virtual ~Swordman(){};
    void attack() override;
    void update() override;
    void draw(std::shared_ptr<RenderWindow> & window) override;
    bool handleEnemyCollision(GameCharacter *enemy) override;
    void collectEnemyPoints(float multiplier) override;
    int getSwordCoolDown() const;
    void setSwordCoolDown(int swordCoolDown);
    bool isAttacking() const;
    void setAttacking(bool isAttacking);

private:
    Sword sword;
    bool attacking;
    int swordCoolDown;
};


#endif //TACCETTIELABORATO_SWORDMAN_H
