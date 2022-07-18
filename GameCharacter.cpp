//
// Created by Francesco Taccetti on 09/07/2022.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter(float y,unsigned int hp, float x): isShielded(false), posY(y), yVelocity(0), hp(hp), posX(x) {
    sprite.setPosition(Vector2f(posX,posY));
    //Rectangular shape is a placeholder
    sprite.setSize(Vector2f(PLAYER_DIMENSIONS,PLAYER_DIMENSIONS));
    sprite.setFillColor(Color::Green);
}

void GameCharacter::jump() {
    if(yVelocity>=0) {
        movementClock.restart();
        yVelocity = JUMP_FORCE;
    }
}

void GameCharacter::receiveDamage() {
    if(isShielded)
        isShielded = false;
    else
        hp--;
}

void GameCharacter::characterDraw(std::shared_ptr<RenderWindow> & window) {
    window->draw(sprite);
}

void GameCharacter::movementeUpdate() {
    if(yVelocity < MAX_YVELOCITY)
        yVelocity += GRAVITY;
    posY += (yVelocity * movementClock.getElapsedTime().asSeconds())/2  ;
    if(posY > (SCREEN_HEIGHT - sprite.getSize().y))
        posY = (SCREEN_HEIGHT - sprite.getSize().y);
    else if(posY < 0) {
        posY = 0;
        yVelocity=0;
    }
    sprite.setPosition(posX, posY);
}

Rect<float> GameCharacter::getGlobalBounds() const{
    return sprite.getGlobalBounds();
}

bool GameCharacter::isShielded1() const {
    return isShielded;
}

void GameCharacter::setIsShielded(bool isShielded) {
    GameCharacter::isShielded = isShielded;
}

float GameCharacter::getPosY() const {
    return posY;
}

void GameCharacter::setPosY(float posY) {
    GameCharacter::posY = posY;
}

float GameCharacter::getYVelocity() const {
    return yVelocity;
}

void GameCharacter::setYVelocity(float yVelocity) {
    GameCharacter::yVelocity = yVelocity;
}

unsigned int GameCharacter::getHp() const {
    return hp;
}

void GameCharacter::setHp(unsigned int hp) {
    GameCharacter::hp = hp;
}

const Clock &GameCharacter::getMovementClock() const {
    return movementClock;
}

float GameCharacter::getPosX() const {
    return posX;
}

void GameCharacter::setPosX(float posX) {
    GameCharacter::posX = posX;
}



