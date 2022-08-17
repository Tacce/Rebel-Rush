//
// Created by Francesco Taccetti on 17/07/2022.
//

#include "Enemy.h"

Enemy::Enemy(float vel, unsigned int hp): GameCharacter((rand()%(SCREEN_HEIGHT-ENEMY_DIMENSIONS)),hp,SCREEN_WIDTH),xVelocity(vel){
    if(texture.loadFromFile(R"(..\Textures\EnemyTexture.png)"))
        sprite.setTexture(&texture);
    else sprite.setFillColor(Color::Red);
}

void Enemy::draw(std::shared_ptr<RenderWindow> &window) {
    sprite.setTexture(&texture);
    characterDraw(window);
}

void Enemy::update() {
    posX-=xVelocity;
    sprite.setPosition(Vector2f(posX,posY));
}
