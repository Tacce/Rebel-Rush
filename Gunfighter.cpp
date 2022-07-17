//
// Created by Francesco Taccetti on 13/07/2022.
//

#include <iostream>
#include "Gunfighter.h"


Gunfighter::Gunfighter(): GameCharacter() ,shootingCooldown(PROJECTILE_COOLDOWN){
    sprite.setFillColor(Color(255,127,0));
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
    characterDraw(window);
    for(auto & projectile : projectiles)
        projectile.draw(window);
}

int Gunfighter::getShootingCooldown() const {
    return shootingCooldown;
}

const std::vector<Projectile> &Gunfighter::getProjectiles() const {
    return projectiles;
}

