//
// Created by Francesco Taccetti on 25/07/2022.
//

#include "Obstacle.h"

Obstacle::Obstacle(float vel, int sp): posX(SCREEN_WIDTH), span(sp), scored(false), alreadyHit(false), xVelocity(vel) {
    height = rand() % (SCREEN_HEIGHT - span);
    upSprite.setSize(Vector2f(OBSTACLE_DIMENSION, height));
    downSprite.setSize(Vector2f(OBSTACLE_DIMENSION,SCREEN_HEIGHT- height - span));

    upTexture.loadFromFile(R"(Textures\ObstacleTexture2.png)");
    upSprite.setTextureRect(IntRect (0,SCREEN_HEIGHT - span - height,OBSTACLE_DIMENSION, height));
    upSprite.setTexture(&upTexture);

    downTexture.loadFromFile(R"(Textures\ObstacleTexture.png)");
    downSprite.setTextureRect(IntRect (0,0,OBSTACLE_DIMENSION, SCREEN_HEIGHT - height - span));
    downSprite.setTexture(&downTexture);
}

void Obstacle::update() {
    posX-=xVelocity;
    upSprite.setPosition(Vector2f(posX,0));
    downSprite.setPosition(Vector2f(posX,height + span));
}

void Obstacle::draw(std::shared_ptr<RenderWindow> &window) {
    upSprite.setTexture(&upTexture);
    window->draw(upSprite);
    downSprite.setTexture(&downTexture);
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
