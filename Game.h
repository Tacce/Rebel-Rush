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
#include "KillCounterObserver.h"
using namespace sf;

class Game {
public:
    explicit Game(std::shared_ptr<RenderWindow>  window1=std::make_shared<RenderWindow>(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),
            "GAME"), int role=0);
    virtual ~Game();
    virtual void run();
    virtual void update();

    const std::shared_ptr<GameCharacter> &getPlayer() const;
    bool isGameOvered() const;


private:
    virtual void handleEvent();
    virtual void draw();


    std::shared_ptr<RenderWindow> window;
    Event event{};
    std::shared_ptr<GameCharacter> player;
    std::unique_ptr<Map> map;
    std::unique_ptr<KillCounterObserver> badgeDisplayer;
    bool gameOvered;
    bool backToMenu;
    int gameOverCooldown;


    Font font;
    Text scoreText;
    Text gameOverText;
    Text hpText;
    Sprite background;
    Texture backgroundTexture;
    std::shared_ptr<RectangleShape> badge;

};


#endif //TACCETTIELABORATO_GAME_H
