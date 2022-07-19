//
// Created by Francesco Taccetti on 19/07/2022.
//

#ifndef TACCETTIELABORATO_SWORD_H
#define TACCETTIELABORATO_SWORD_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "Definitions.h"
using namespace sf;


class Sword {
public:
    Sword();
    void update(float x,float y);
    void draw(std::shared_ptr<RenderWindow> &window);
    void reset();
    Rect<float> getGlobalBounds() const;



private:
    RectangleShape sprite;

};


#endif //TACCETTIELABORATO_SWORD_H
