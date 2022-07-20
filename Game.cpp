//
// Created by Francesco Taccetti on 12/07/2022.
//

#include "Game.h"
#include <memory>

Game::Game(const int role) : isGameOvered(false), phase(0){
    window = std::make_shared<RenderWindow>(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Escape from Hazotic City");
    if(role==0)
        player = std::make_shared<Gunfighter>();
    else if(role==1)
        player = std::make_shared<Swordman>();
    map = std::make_unique<Map>(player);
    font.loadFromFile(R"(..\Font\PublicPixel-0W5Kv.ttf)");
    scoreText.setFont(font);
    scoreText.setFillColor(Color::White);
}

Game::~Game() = default;

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
        if(Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space))
            player->jump();
        if((Mouse::isButtonPressed(sf::Mouse::Left) || Keyboard::isKeyPressed(Keyboard::D)) && !isGameOvered)
            player->attack();
    }
}

void Game::update() {
    if(player->getHp() <= 0)
        isGameOvered= true;
    if(!isGameOvered)
        map->update();
    scoreText.setString("SCORE:\n"+std::to_string(static_cast<int>(player->getScore())));
}

void Game::draw() {
    window->clear();
    map->draw(window);
    window->draw(scoreText);
    window->display();
}

const std::shared_ptr<GameCharacter> &Game::getPlayer() const {
    return player;
}

const std::shared_ptr<RenderWindow> &Game::getWindow() const {
    return window;
}

bool Game::isGameOvered1() const {
    return isGameOvered;
}


