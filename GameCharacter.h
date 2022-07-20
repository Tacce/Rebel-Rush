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
    explicit GameCharacter(float y=0, unsigned int hp=3, float x=PLAYER_POSX);
    virtual ~GameCharacter() = default;
    virtual void attack()=0;
    virtual void jump();
    virtual void draw(std::shared_ptr<RenderWindow> & window)=0;
    virtual void update() = 0;
    virtual void receiveDamage();
    virtual Rect<float> getGlobalBounds() const;
    virtual bool handleEnemyCollision(GameCharacter* enemy)=0;

    bool isShielded1() const;
    void setIsShielded(bool isShielded);
    float getPosY() const;
    void setPosY(float posY);
    float getYVelocity() const;
    void setYVelocity(float yVelocity);
    unsigned int getHp() const;
    void setHp(unsigned int hp);
    unsigned int getMaxHp() const;
    void setMaxHp(unsigned int maxHp);
    const Clock &getMovementClock() const;
    float getPosX() const;
    void setPosX(float posX);
    float getScore() const;
    void setScore(float score);

protected:
    virtual void movementeUpdate();
    virtual void characterDraw(std::shared_ptr<RenderWindow> & window);

    bool isShielded;
    float posY;
    float posX;
    float yVelocity;
    unsigned int hp;
    unsigned int maxHp;
    RectangleShape sprite;
    Clock movementClock;
    float score;

};


#endif //TACCETTIELABORATO_GAMECHARACTER_H
