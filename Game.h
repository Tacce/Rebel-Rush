//
// Created by Francesco Taccetti on 12/07/2022.
//

#ifndef TACCETTIELABORATO_GAME_H
#define TACCETTIELABORATO_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Definitions.h"
#include "GameCharacter.h"
#include "Gunfigther.h"
#include "Swordman.h"
using namespace sf;

class Game {
public:
    explicit Game(int role=0);
    virtual ~Game();
    virtual void run();

private:
    virtual void handleEvent();
    virtual void draw();
    virtual void update();


    RenderWindow*  window;
    Event event{};
    std::unique_ptr<GameCharacter> player;
    int score;
    int phase;
    bool isGameOvered;
};


#endif //TACCETTIELABORATO_GAME_H
