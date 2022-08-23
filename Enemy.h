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
    explicit Enemy(float vel=ENEMY_SPEED, bool med=false, unsigned int hp=1);
    void update() override;
    void draw(std::shared_ptr<RenderWindow> &window) override;
    void attack() override{};
    bool handleEnemyCollision(GameCharacter *enemy) override{return false;};
    void inflictDamage(GameCharacter *target) override;
    void receiveDamage(GameCharacter *attacker) override;
    void collectEnemyPoints(float multiplier) override{};
    bool isMedical() const;
    void setMedical(bool medical);


private:
    float xVelocity;
    bool medical;
};


#endif //TACCETTIELABORATO_ENEMY_H
