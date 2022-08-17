//
// Created by Francesco Taccetti on 16/07/2022.
//

#include <iostream>
#include "Projectile.h"

Projectile::Projectile(float y):posX(PLAYER_POSX),posY(y+35){
    sprite.setPosition(Vector2f(posX,posY));
    sprite.setSize(Vector2f(60,5));
    sprite.setFillColor(Color(255,127,0));
}

void Projectile::update() {
    posX += PROJECTILE_SPEED;
    sprite.setPosition(Vector2f(posX,posY));
}

void Projectile::draw(std::shared_ptr<RenderWindow> &window) {
    window->draw(sprite);
}

Rect<float> Projectile::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

float Projectile::getPosX() const {
    return posX;
}

void Projectile::setPosX(float posX) {
    Projectile::posX = posX;
}

float Projectile::getPosY() const {
    return posY;
}

void Projectile::setPosY(float posY) {
    Projectile::posY = posY;
}
