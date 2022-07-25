//
// Created by Francesco Taccetti on 13/07/2022.
//

#include "Swordman.h"

Swordman::Swordman() : GameCharacter(), attacking(false), swordCoolDown(0) {
    sprite.setFillColor(Color::Cyan);
}

void Swordman::attack() {
    if(swordCoolDown <= SWORD_COOLDOWN)
        attacking=true;
}

void Swordman::update() {
    movementeUpdate();
    if(attacking) {
        sword.update(posX + PLAYER_DIMENSIONS / 2, posY + PLAYER_DIMENSIONS / 2);
        swordCoolDown++;
    }
    if(swordCoolDown > SWORD_COOLDOWN ){
        attacking=false;
        swordCoolDown=0;
        sword.reset();
    }
    score += POINTS_FOR_FRAME;
}

void Swordman::draw(std::shared_ptr<RenderWindow> &window) {
    characterDraw(const_cast<std::shared_ptr<RenderWindow> &>(window));
    if(attacking && swordCoolDown < SWORD_DRAW_COOLDOWN)
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

bool Swordman::isAttacking() const {
    return attacking;
}

void Swordman::setAttacking(bool isAttacking) {
    Swordman::attacking = isAttacking;
}
