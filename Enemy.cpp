//
// Created by Francesco Taccetti on 17/07/2022.
//

#include "Enemy.h"

Enemy::Enemy(float vel,bool med, unsigned int hp): GameCharacter((rand()%(SCREEN_HEIGHT-ENEMY_DIMENSIONS)),hp,SCREEN_WIDTH),
                                                   xVelocity(vel), medical(med){
    if(!medical){
        if(texture.loadFromFile(R"(Textures\EnemyTexture.png)"))
            sprite.setTexture(&texture);
        else sprite.setFillColor(Color::Red);
    }else{
        if(texture.loadFromFile(R"(Textures\MedicalSupportTexture.png)"))
            sprite.setTexture(&texture);
        else sprite.setFillColor(Color::Green);
    }
}

void Enemy::draw(std::shared_ptr<RenderWindow> &window) {
    sprite.setTexture(&texture);
    characterDraw(window);
}

void Enemy::update() {
    posX-=xVelocity;
    sprite.setPosition(Vector2f(posX,posY));
}

void Enemy::inflictDamage(GameCharacter *target) {
    if(!medical)
        target->receiveDamage(this);
    else
        target->heal();
}

void Enemy::receiveDamage(GameCharacter *attacker){
    hp--;
    if(medical)
        attacker->receiveDamage(this);
    else if(hp==0)
        attacker->collectEnemyPoints(maxHp);
}

bool Enemy::isMedical() const {
    return medical;
}

void Enemy::setMedical(bool medical) {
    Enemy::medical = medical;
}
