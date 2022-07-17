//
// Created by Francesco Taccetti on 16/07/2022.
//

#ifndef TACCETTIELABORATO_PROJECTILE_H
#define TACCETTIELABORATO_PROJECTILE_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Definitions.h"
using namespace sf;


class Projectile {
public:
    explicit Projectile(float posY=0);
    void update();
    void draw(std::shared_ptr<RenderWindow> & window);
    float getPosX() const;

private:
    RectangleShape sprite;
    float posX,posY;

};


#endif //TACCETTIELABORATO_PROJECTILE_H
