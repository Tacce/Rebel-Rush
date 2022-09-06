//
// Created by Francesco Taccetti on 12/07/2022.
//

#include "Game.h"
#include <memory>

Game::Game(std::shared_ptr<RenderWindow>  window1, const int role) : gameOvered(false),window(std::move(window1)),
    backToMenu(false), gameOverCooldown(GAMEOVER_COOLDOWN) {

    if(role==0)
        player = std::make_shared<Gunfighter>();
    else if(role==1)
        player = std::make_shared<Swordman>();
    map = std::make_unique<Map>(player);

    badge = std::make_shared<RectangleShape>();
    badge->setPosition(Vector2f(10,110));
    badge->setSize(Vector2f(30,46));
    badge->setFillColor(Color::Transparent);
    badgeDisplayer = std::make_unique<KillCounterObserver>(player,badge);

    backgroundTexture.loadFromFile(R"(Textures\BackgroundTexture.png)");
    background.setTexture(backgroundTexture);

    font.loadFromFile(R"(Font\PublicPixel-0W5Kv.ttf)");
    scoreText.setFont(font);
    scoreText.setFillColor(Color::White);
    scoreText.setOutlineThickness(4);
    scoreText.setOutlineColor(Color::Black);

    hpText.setFont(font);
    hpText.setPosition(0,70);
    hpText.setOutlineThickness(4);
    hpText.setOutlineColor(Color::Black);

    gameOverText.setFont(font);
    gameOverText.setFillColor(Color::Red);
    gameOverText.setPosition(SCREEN_WIDTH/2.7,SCREEN_HEIGHT/2.7);
    gameOverText.setString("GAME OVER");
    gameOverText.setOutlineThickness(4);
    gameOverText.setOutlineColor(Color::Black);
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
        if((Mouse::isButtonPressed(sf::Mouse::Left) && gameOvered && gameOverCooldown>GAMEOVER_COOLDOWN) ||
            Keyboard::isKeyPressed(Keyboard::Escape))
            backToMenu=true;
    }
}

void Game::update() {
    if(player->getHp() <= 0 && !gameOvered) {
        gameOvered = true;
        gameOverCooldown = 0;
    }
    if(!gameOvered)
        map->update();
    scoreText.setString("SCORE:\n"+std::to_string(static_cast<int>(player->getScore())));
    hpText.setString("HP:" + std::to_string(player->getHp()));
    if(gameOvered)
        gameOverCooldown++;
}

void Game::draw() {
    window->clear();
    window->draw(background);
    map->draw(window);
    window->draw(scoreText);
    window->draw(hpText);
    window->draw(*badge);
    if(gameOvered)
        window->draw(gameOverText);
    window->display();
}

const std::shared_ptr<GameCharacter> &Game::getPlayer() const {
    return player;
}

bool Game::isGameOvered() const {
    return gameOvered;
}


