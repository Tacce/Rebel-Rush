//
// Created by Francesco Taccetti on 09/07/2022.
//

#ifndef TACCETTIELABORATO_GAMECHARACTER_H
#define TACCETTIELABORATO_GAMECHARACTER_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
using namespace sf;

class GameCharacter {
public:
    explicit GameCharacter(float y=0);
    virtual ~GameCharacter()=0;
    virtual void attack()=0;
    virtual void jump();
    virtual void receiveDamage();
    virtual void draw(RenderWindow* window);
    virtual void update();

    bool isShielded1() const;
    void setIsShielded(bool isShielded);
    float getPosY() const;
    void setPosY(float posY);
    float getYVelocity() const;
    void setYVelocity(float yVelocity);


protected:
    bool isShielded;
    float posY;
    float yVelocity;
    RectangleShape sprite;
    Clock movementClock;
};


#endif //TACCETTIELABORATO_GAMECHARACTER_H
