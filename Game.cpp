//
// Created by Francesco Taccetti on 12/07/2022.
//

#include "Game.h"
#include <memory>
#include <utility>

Game::Game(std::shared_ptr<RenderWindow>  window1, const int role) : gameOvered(false), phase(0),window(std::move(window1)),
    backToMenu(false){

    if(role==0)
        player = std::make_shared<Gunfighter>();
    else if(role==1)
        player = std::make_shared<Swordman>();
    map = std::make_unique<Map>(player);

    font.loadFromFile(R"(..\Font\PublicPixel-0W5Kv.ttf)");
    scoreText.setFont(font);
    scoreText.setFillColor(Color::White);
    hpText.setFont(font);
    hpText.setPosition(0,70);
    gameOverText.setFont(font);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(SCREEN_WIDTH/2.7,SCREEN_HEIGHT/2.7);
    gameOverText.setString("GAME OVER");
}

Game::~Game() = default;

void Game::run() {
    while (window->isOpen() && !backToMenu){
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
        if((Mouse::isButtonPressed(sf::Mouse::Left) || Keyboard::isKeyPressed(Keyboard::D)) && !gameOvered)
            player->attack();
        if(Mouse::isButtonPressed(sf::Mouse::Left) && gameOvered)
            backToMenu=true;
    }
}

void Game::update() {
    if(player->getHp() <= 0)
        gameOvered= true;
    if(!gameOvered)
        map->update();
    scoreText.setString("SCORE:\n"+std::to_string(static_cast<int>(player->getScore())));
    hpText.setString("HP:" + std::to_string(player->getHp()));
}

void Game::draw() {
    window->clear();
    map->draw(window);
    window->draw(scoreText);
    window->draw(hpText);
    if(gameOvered)
        window->draw(gameOverText);
    window->display();
}

const std::shared_ptr<GameCharacter> &Game::getPlayer() const {
    return player;
}

const std::shared_ptr<RenderWindow> &Game::getWindow() const {
    return window;
}

bool Game::isGameOvered() const {
    return gameOvered;
}


