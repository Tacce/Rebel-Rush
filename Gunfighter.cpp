//
// Created by Francesco Taccetti on 13/07/2022.
//

#include <iostream>
#include "Gunfighter.h"


Gunfighter::Gunfighter(): GameCharacter() ,shootingCooldown(PROJECTILE_COOLDOWN){
    if(texture.loadFromFile(R"(Textures\GunfighterSprite.png)"))
        sprite.setTexture(&texture);
    else sprite.setFillColor(Color(255,127,0));
}

void Gunfighter::attack() {
    if(shootingCooldown>=PROJECTILE_COOLDOWN) {
        projectiles.emplace_back(posY);
        shootingCooldown=0;
    }
}

void Gunfighter::update() {
    movementeUpdate();
    for (size_t i=0; i<projectiles.size();i++){
        projectiles[i].update();
        if(projectiles[i].getPosX()>SCREEN_WIDTH)
            projectiles.erase(projectiles.begin()+i);
    }
    shootingCooldown++;
}

void Gunfighter::draw(std::shared_ptr<RenderWindow> &window) {
    for(auto & projectile : projectiles)
        projectile.draw(window);
    characterDraw(window);
}


bool Gunfighter::handleEnemyCollision(GameCharacter *enemy) {
    bool killed=false;
    if(enemy->getGlobalBounds().intersects(this->getGlobalBounds())){
        killed=true;
        enemy->inflictDamage(this);
    }
    size_t j=0;
    while(j<projectiles.size() && !killed) {
        if(projectiles[j].getGlobalBounds().intersects(enemy->getGlobalBounds())) {
            projectiles.erase(projectiles.begin() + j);
            enemy->receiveDamage(this);
        }
        if(enemy->getHp()>0)
            j++;
        else{
            killed=true;
            setState();
        }
    }
    return killed;
}

void Gunfighter::collectEnemyPoints(float multiplier){
    score += (POINTS_MULTIPLIER+POINTS_MULTIPLIER/4) * multiplier;
}

void Gunfighter::setProjectiles(const std::vector<Projectile> &projectiles) {
    Gunfighter::projectiles = projectiles;
}

const std::vector<Projectile> &Gunfighter::getProjectiles() const {
    return projectiles;
}

int Gunfighter::getShootingCooldown() const {
    return shootingCooldown;
}


