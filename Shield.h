//
// Created by Francesco Taccetti on 11/08/2022.
//

#ifndef TACCETTIELABORATO_SHIELD_H
#define TACCETTIELABORATO_SHIELD_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Definitions.h"
using namespace sf;

class Shield {
public:
    explicit Shield(float vel=SHIELD_SPEED);
    void update();
    void draw(std::shared_ptr<RenderWindow> & window);
    Rect<float> getGlobalBounds() const;

private:
    CircleShape sprite;
    float posX,posY;
public:
    float getPosX() const;

private:
    float xVelocity;
    Texture texture;

};


#endif //TACCETTIELABORATO_SHIELD_H
