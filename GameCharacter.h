//
// Created by Francesco Taccetti on 09/07/2022.
//

#ifndef TACCETTIELABORATO_GAMECHARACTER_H
#define TACCETTIELABORATO_GAMECHARACTER_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include <memory>
using namespace sf;

class GameCharacter {
public:
    explicit GameCharacter(float y=0);
    virtual ~GameCharacter() = default;
    virtual void attack()=0;
    virtual void jump();
    virtual void receiveDamage();
    virtual void draw(std::shared_ptr<RenderWindow> & window);
    virtual void update();
    virtual Rect<float> getGlobalBounds() const;

    bool isShielded1() const;
    void setIsShielded(bool isShielded);
    float getPosY() const;
    void setPosY(float posY);
    float getYVelocity() const;
    void setYVelocity(float yVelocity);
    unsigned int getHp() const;
    void setHp(unsigned int hp);



protected:
    bool isShielded;
    float posY;
    float yVelocity;
    unsigned int hp;
    RectangleShape sprite;
    Clock movementClock;
};


#endif //TACCETTIELABORATO_GAMECHARACTER_H
