//
// Created by Francesco Taccetti on 25/07/2022.
//

#ifndef TACCETTIELABORATO_OBSTACLE_H
#define TACCETTIELABORATO_OBSTACLE_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Definitions.h"
using namespace sf;

class Obstacle {
public:
    explicit Obstacle(int sp=OBSTACLE_SPAN,float vel=OBSTACLE_SPEED);
    void update();
    void draw(std::shared_ptr<RenderWindow> & window);
    Rect<float> getUpGlobalBounds() const;
    Rect<float> getDownGlobalBounds() const;

    float getPosX() const;
    void setPosX(float posX);


private:
    bool scored;
    int span;
    float posX,height;
    float xVelocity;
    RectangleShape upSprite;
    RectangleShape downSprite;

};


#endif //TACCETTIELABORATO_OBSTACLE_H
