//
// Created by Francesco Taccetti on 13/07/2022.
//

#ifndef TACCETTIELABORATO_GUNFIGHTER_H
#define TACCETTIELABORATO_GUNFIGHTER_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include <memory>
#include "GameCharacter.h"
#include "Projectile.h"
using namespace sf;

class Gunfighter: public GameCharacter{
public:
    Gunfighter();
    ~Gunfighter() override = default;
    void attack() override;
    void update() override;
    void draw(std::shared_ptr<RenderWindow> & window) override;
    bool handleEnemyCollision(GameCharacter *enemy) override;
    void collectPoints(unsigned int multiplier) override;
    void setProjectiles(const std::vector<Projectile> &projectiles);
    const std::vector<Projectile> &getProjectiles() const;
    int getShootingCooldown() const;
private:
    std::vector<Projectile> projectiles;
    int shootingCooldown;
};


#endif //TACCETTIELABORATO_GUNFIGHTER_H
