//
// Created by Francesco Taccetti on 13/07/2022.
//

#include "Swordman.h"

Swordman::Swordman() : GameCharacter() {
    sprite.setFillColor(Color::Cyan);
}

void Swordman::attack() {

}

void Swordman::update() {
    movementeUpdate();
}

void Swordman::draw(std::shared_ptr<RenderWindow> &window) {
    characterDraw(const_cast<std::shared_ptr<RenderWindow> &>(window));
}

bool Swordman::handleEnemyCollision(GameCharacter *enemy) {
    return false;
}
