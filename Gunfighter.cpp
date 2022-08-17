//
// Created by Francesco Taccetti on 13/07/2022.
//

#include <iostream>
#include "Gunfighter.h"


Gunfighter::Gunfighter(): GameCharacter() ,shootingCooldown(PROJECTILE_COOLDOWN){
    if(texture.loadFromFile(R"(..\Textures\GunfighterSprite.png)"))
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
    if(posY < SCREEN_HEIGHT-PLAYER_DIMENSIONS && posY>1)
        score += POINTS_FOR_FRAME;
    else
        score += POINTS_FOR_FRAME/5;
}

void Gunfighter::draw(std::shared_ptr<RenderWindow> &window) {
    characterDraw(window);
    for(auto & projectile : projectiles)
        projectile.draw(window);
}


bool Gunfighter::handleEnemyCollision(GameCharacter *enemy) {
    bool killed=false;
    if(enemy->getGlobalBounds().intersects(this->getGlobalBounds())){
        killed=true;
        this->receiveDamage();
    }
    size_t j=0;
    while(j<projectiles.size() && !killed) {
        if(projectiles[j].getGlobalBounds().intersects(enemy->getGlobalBounds())) {
            projectiles.erase(projectiles.begin() + j);
            enemy->receiveDamage();
        }
        if(enemy->getHp()>0)
            j++;
        else{
            killed=true;
            score += (POINTS_MULTIPLIER+POINTS_MULTIPLIER/4) * (enemy->getMaxHp());
        }
    }

    return killed;
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

