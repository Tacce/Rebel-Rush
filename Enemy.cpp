//
// Created by Francesco Taccetti on 17/07/2022.
//

#include "Enemy.h"

Enemy::Enemy(unsigned int hp, float vel): GameCharacter((rand()%(SCREEN_HEIGHT-ENEMY_DIMENSIONS)),hp,SCREEN_WIDTH),xVelocity(vel){
    sprite.setFillColor(Color::Red);
}

void Enemy::draw(std::shared_ptr<RenderWindow> &window) {
    characterDraw(window);
}

void Enemy::update() {
    posX-=xVelocity;
    sprite.setPosition(Vector2f(posX,posY));
}
