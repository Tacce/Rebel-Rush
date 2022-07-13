//
// Created by Francesco Taccetti on 13/07/2022.
//

#ifndef TACCETTIELABORATO_GUNFIGTHER_H
#define TACCETTIELABORATO_GUNFIGTHER_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include <memory>
#include "GameCharacter.h"
using namespace sf;

class Gunfigther: public GameCharacter{
public:
    Gunfigther();
    ~Gunfigther() override = default;;
    void attack() override;


private:



};


#endif //TACCETTIELABORATO_GUNFIGTHER_H
