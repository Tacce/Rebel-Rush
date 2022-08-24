//
// Created by Francesco Taccetti on 10/08/2022.
//

#ifndef TACCETTIELABORATO_MENU_H
#define TACCETTIELABORATO_MENU_H
#include "Definitions.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "Game.h"
using namespace sf;
class Menu {
public:
    Menu();
    virtual ~Menu();
    void run();
    void handleEvent();
    void draw();


private:
    std::shared_ptr<RenderWindow> window;
    Event event{};
    std::unique_ptr<Game> game;
    int highscore;
    bool displayingRules;

    RectangleShape gunfighterButton, swordmanButton, rulesButton;
    Sprite gameTitle, rules;

    Texture gunButTexture,sworButTexture,titleTexture,rulesTexture,rulesButTexture,backButTexture;
    Font font;
    Text highscoreText;


};


#endif //TACCETTIELABORATO_MENU_H
