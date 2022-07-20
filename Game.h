//
// Created by Francesco Taccetti on 12/07/2022.
//

#ifndef TACCETTIELABORATO_GAME_H
#define TACCETTIELABORATO_GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "Definitions.h"
#include "Map.h"
#include "GameCharacter.h"
#include "Gunfighter.h"
#include "Swordman.h"
using namespace sf;

class Game {
public:
    explicit Game(int role=0);
    virtual ~Game();
    virtual void run();
    virtual void update();

    const std::shared_ptr<GameCharacter> &getPlayer() const;
    const std::shared_ptr<RenderWindow> &getWindow() const;
    bool isGameOvered1() const;


private:
    virtual void handleEvent();
    virtual void draw();


    std::shared_ptr<RenderWindow> window;
    Event event{};
    std::shared_ptr<GameCharacter> player;
    std::unique_ptr<Map> map;
    unsigned int phase;
    bool isGameOvered;

    Font font;
    Text scoreText;
};


#endif //TACCETTIELABORATO_GAME_H
