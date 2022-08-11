//
// Created by Francesco Taccetti on 25/07/2022.
//

#include "Obstacle.h"

Obstacle::Obstacle(float vel, int sp): posX(SCREEN_WIDTH), span(sp), scored(false), alreadyHit(false), xVelocity(vel) {
    height = rand() % (SCREEN_HEIGHT - span);
    upSprite.setSize(Vector2f(OBSTACLE_DIMENSION, height));
    downSprite.setSize(Vector2f(OBSTACLE_DIMENSION,SCREEN_HEIGHT- height - span));
}

void Obstacle::update() {
    posX-=xVelocity;
    upSprite.setPosition(Vector2f(posX,0));
    downSprite.setPosition(Vector2f(posX,height + span));
}

void Obstacle::draw(std::shared_ptr<RenderWindow> &window) {
    window->draw(upSprite);
    window->draw(downSprite);
}

Rect<float> Obstacle::getUpGlobalBounds() const {
    return upSprite.getGlobalBounds();
}

Rect<float> Obstacle::getDownGlobalBounds() const {
    return downSprite.getGlobalBounds();
}

float Obstacle::getPosX() const {
    return posX;
}

void Obstacle::setPosX(float posX) {
    Obstacle::posX = posX;
}

bool Obstacle::isScored() const {
    return scored;
}

void Obstacle::setScored(bool scored) {
    Obstacle::scored = scored;
}

bool Obstacle::isAlreadyHit() const {
    return alreadyHit;
}

void Obstacle::setAlreadyHit(bool alreadyHit) {
    Obstacle::alreadyHit = alreadyHit;
}

void Obstacle::setHeight(float height) {
    Obstacle::height = height;
}
