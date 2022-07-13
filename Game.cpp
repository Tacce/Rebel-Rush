//
// Created by Francesco Taccetti on 12/07/2022.
//

#include "Game.h"
#include <memory>

Game::Game(const int role) : score(0), isGameOvered(false), phase(0){
    window = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Escape from Hazotic City");
    if(role==0)
        player = std::make_unique<Gunfigther>();
    else if(role==1)
        player = std::make_unique<Swordman>();
}

Game::~Game() {
    delete window;
}

void Game::run() {
    while (window->isOpen()){
        handleEvent();
        update();
        draw();
    }
}

void Game::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed)
            window->close();
        if(Keyboard::isKeyPressed(Keyboard::W))
            player->jump();
        if(Keyboard::isKeyPressed(Keyboard::D))
            player->attack();
    }
}

void Game::update() {
    if(player->getHp() < 0)
        isGameOvered= true;
    if(!isGameOvered)
        player->update();
}

void Game::draw() {
    window->clear();
    player->draw(& window);
    window->display();
}


