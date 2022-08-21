//
// Created by Francesco Taccetti on 09/07/2022.
//

#include "GameCharacter.h"

GameCharacter::GameCharacter(float y,unsigned int hp, float x): shielded(false), posY(y), yVelocity(0), hp(hp), maxHp(hp),
                                                                posX(x), score(0), fireCooldown(FIRE_COOLDOWN) {
    sprite.setPosition(Vector2f(posX,posY));
    sprite.setSize(Vector2f(PLAYER_DIMENSIONS,PLAYER_DIMENSIONS));

    shieldSprite.setRadius(SHIELD_SPRITE_RADIUS);
    shieldSprite.setFillColor(Color::Transparent);
    shieldSprite.setOutlineThickness(5);
    shieldSprite.setOutlineColor(Color::Blue);

    fireTexture.loadFromFile(R"(..\Textures\FireTexture.png)");
    fireSprite.setTexture(fireTexture);
    fireSprite.setPosition(posX,posY + PLAYER_DIMENSIONS);
}

void GameCharacter::jump() {
    if(yVelocity>=0 && hp>0) {
        movementClock.restart();
        yVelocity = JUMP_FORCE;
        fireCooldown=0;
    }
}

void GameCharacter::receiveDamage(GameCharacter * attacker) {
    if(shielded)
        shielded = false;
    else
        hp--;
}

void GameCharacter::characterDraw(std::shared_ptr<RenderWindow> & window) {
    window->draw(sprite);
    if(shielded)
        window->draw(shieldSprite);
    if(fireCooldown<FIRE_COOLDOWN)
        window->draw(fireSprite);
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
    sprite.setPosition(Vector2f(posX, posY));
    if(shielded)
        shieldSprite.setPosition(posX-(SHIELD_SPRITE_RADIUS-PLAYER_DIMENSIONS/2), posY-(SHIELD_SPRITE_RADIUS-PLAYER_DIMENSIONS/2));
    if(fireCooldown<FIRE_COOLDOWN){
        fireCooldown++;
        fireSprite.setPosition(posX,posY + PLAYER_DIMENSIONS);
    }
}

void GameCharacter::handleObstacleCollision(Obstacle &obstacle) {
    if(!obstacle.isAlreadyHit()){
        if(obstacle.getUpGlobalBounds().intersects(this->getGlobalBounds()) ||
           obstacle.getDownGlobalBounds().intersects(this->getGlobalBounds())){
            obstacle.setAlreadyHit(true);
            if(shielded)
                shielded=false;
            else
                hp=0;
        }
        if(obstacle.getPosX() + OBSTACLE_DIMENSION < PLAYER_POSX  && !obstacle.isScored()){
            obstacle.setScored(true);
            score += POINTS_MULTIPLIER;
        }
    }
}

bool GameCharacter::handleShieldCollision(std::shared_ptr<Shield> shield) {
    if(shield->getGlobalBounds().intersects(this->getGlobalBounds())){
        shielded=true;
        hp=maxHp;
        shieldSprite.setPosition(posX-(SHIELD_SPRITE_RADIUS-PLAYER_DIMENSIONS/2), posY-(SHIELD_SPRITE_RADIUS-PLAYER_DIMENSIONS/2));
        return true;
    }else
        return false;
}

Rect<float> GameCharacter::getGlobalBounds() const{
    return sprite.getGlobalBounds();
}

bool GameCharacter::isShielded() const {
    return shielded;
}

void GameCharacter::setShielded(bool isShielded) {
    GameCharacter::shielded = isShielded;
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

float GameCharacter::getScore() const {
    return score;
}

void GameCharacter::setScore(float score) {
    GameCharacter::score = score;
}

unsigned int GameCharacter::getMaxHp() const {
    return maxHp;
}

void GameCharacter::setMaxHp(unsigned int maxHp) {
    GameCharacter::maxHp = maxHp;
}

void GameCharacter::inflictDamage(GameCharacter *target) {
    target->receiveDamage(this);
}

void GameCharacter::heal() {
    if(hp < maxHp)
        hp++;
}


