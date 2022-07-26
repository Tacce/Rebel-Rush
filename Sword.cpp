//
// Created by Francesco Taccetti on 19/07/2022.
//

#include "Sword.h"

Sword::Sword(){
    sprite.setSize(Vector2f(0, 0));
    sprite.setFillColor(Color::Cyan);
}

void Sword::update(float x, float y) {
    sprite.setPosition(Vector2f (x,y));
    sprite.rotate(-SWORD_ROTATION);
}

void Sword::draw(std::shared_ptr<RenderWindow> &window) {
    window->draw(sprite);
}

void Sword::reset() {
    sprite.setSize(Vector2f(110, 10));
    sprite.setRotation(50);
}

Rect<float> Sword::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}

void Sword::retract() {
    sprite.setSize(Vector2f(0,0));
}
