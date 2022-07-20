//
// Created by Francesco Taccetti on 13/07/2022.
//

#include "Swordman.h"

Swordman::Swordman() : GameCharacter(), isAttacking(false), swordCoolDown(0) {
    sprite.setFillColor(Color::Cyan);
}

void Swordman::attack() {
    if(swordCoolDown <= SWORD_COOLDOWN)
        isAttacking=true;
}

void Swordman::update() {
    movementeUpdate();
    if(isAttacking) {
        sword.update(posX + PLAYER_DIMENSIONS / 2, posY + PLAYER_DIMENSIONS / 2);
        swordCoolDown++;
    }
    if(swordCoolDown > SWORD_COOLDOWN ){
        isAttacking=false;
        swordCoolDown=0;
        sword.reset();
    }
    score += POINTS_FOR_FRAME;
}

void Swordman::draw(std::shared_ptr<RenderWindow> &window) {
    characterDraw(const_cast<std::shared_ptr<RenderWindow> &>(window));
    if(isAttacking && swordCoolDown < 200)
        sword.draw(window);
}

bool Swordman::handleEnemyCollision(GameCharacter *enemy) {
    bool killed=false;
    if(enemy->getGlobalBounds().intersects(this->getGlobalBounds())){
        killed=true;
        this->receiveDamage();
    }
    if(enemy->getGlobalBounds().intersects(sword.getGlobalBounds())){
        killed=true;
        score += POINTS_MULTIPLIER * (enemy->getMaxHp());
    }
    return killed;
}

int Swordman::getSwordCoolDown() const {
    return swordCoolDown;
}

void Swordman::setSwordCoolDown(int swordCoolDown) {
    Swordman::swordCoolDown = swordCoolDown;
}

bool Swordman::isAttacking1() const {
    return isAttacking;
}

void Swordman::setIsAttacking(bool isAttacking) {
    Swordman::isAttacking = isAttacking;
}
