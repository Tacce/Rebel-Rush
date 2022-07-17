//
// Created by Francesco Taccetti on 16/07/2022.
//

#include <iostream>
#include "Projectile.h"

Projectile::Projectile(float y):posX(PLAYER_POSX),posY(y+PLAYER_DIMENSIONS/3.0){
    sprite.setPosition(Vector2f(posX,posY));
    sprite.setSize(Vector2f(60,5));
    sprite.setFillColor(Color(255,127,0));
}

void Projectile::update() {
    posX = posX + PROJECTILE_SPEED;
}

void Projectile::draw(std::shared_ptr<RenderWindow> &window) {
    sprite.setPosition(Vector2f(posX,posY));
    window->draw(sprite);
}

float Projectile::getPosX() const {
    return posX;
}
