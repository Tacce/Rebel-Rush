//
// Created by Francesco Taccetti on 11/08/2022.
//

#include "Shield.h"

Shield::Shield(float vel): posX(SCREEN_WIDTH), posY(rand()%(SCREEN_HEIGHT-SHIELD_RADIUS*2)), xVelocity(vel) {
    sprite.setRadius(SHIELD_RADIUS);
    sprite.setFillColor(Color::Blue);
    sprite.setPosition(Vector2f(posX,posY));
}

void Shield::update() {
    posX-=xVelocity;
    sprite.setPosition(Vector2f(posX,posY));
}

void Shield::draw(std::shared_ptr<RenderWindow> &window) {
    window->draw(sprite);
}

Rect<float> Shield::getGlobalBounds() const{
    return sprite.getGlobalBounds();
}

float Shield::getPosX() const {
    return posX;
}


