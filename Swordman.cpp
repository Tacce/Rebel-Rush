//
// Created by Francesco Taccetti on 13/07/2022.
//

#include "Swordman.h"

Swordman::Swordman() : GameCharacter(), attacking(false), swordCoolDown(0) {
    if(texture.loadFromFile(R"(..\Textures\SwordmanSprite.png)"))
        sprite.setTexture(&texture);
    else sprite.setFillColor(Color::Cyan);
}

void Swordman::attack() {
    if (swordCoolDown <= SWORD_COOLDOWN){
        attacking = true;
        sword.reset();
    }
}

void Swordman::update() {
    movementeUpdate();
    if(attacking) {
        sword.update(posX + PLAYER_DIMENSIONS / 2, posY + PLAYER_DIMENSIONS / 2);
        swordCoolDown++;
    }
    if(swordCoolDown > SWORD_DRAW_COOLDOWN)
        sword.retract();
    if(swordCoolDown > SWORD_COOLDOWN ){
        attacking=false;
        swordCoolDown=0;
    }
    if(posY < SCREEN_HEIGHT-PLAYER_DIMENSIONS && posY>1)
        score += POINTS_FOR_FRAME;
    else
        score += POINTS_FOR_FRAME/5;
}

void Swordman::draw(std::shared_ptr<RenderWindow> &window) {
    if(attacking && swordCoolDown < SWORD_DRAW_COOLDOWN)
        sword.draw(window);
    characterDraw(const_cast<std::shared_ptr<RenderWindow> &>(window));
}

bool Swordman::handleEnemyCollision(GameCharacter *enemy) {
    bool killed=false;
    if(enemy->getGlobalBounds().intersects(this->getGlobalBounds())){
        killed=true;
        enemy->inflictDamage(this);
    }
    if(enemy->getGlobalBounds().intersects(sword.getGlobalBounds())){
        enemy->receiveDamage(this);
        killed=true;
        setState();
    }
    return killed;
}

void Swordman::collectEnemyPoints(float multiplier) {
    collectPoints(multiplier);
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


