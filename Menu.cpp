//
// Created by Francesco Taccetti on 10/08/2022.
//

#include "Menu.h"

Menu::Menu(): game(nullptr), highscore(0), displayingRules(false) {
    window = std::make_shared<RenderWindow>(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Rebel Rush");
    window->setFramerateLimit(60);

    titleTexture.loadFromFile(R"(..\Textures\TitleMenu.png)");
    gameTitle.setTexture(titleTexture);

    rulesTexture.loadFromFile(R"(..\Textures\RulesTexture.png)");
    rules.setTexture(rulesTexture);

    gunfighterButton.setSize(Vector2f(450,300));
    gunfighterButton.setPosition(100,300);
    if(gunButTexture.loadFromFile(R"(..\Textures\GunfighterButton.png)"))
        gunfighterButton.setTexture(&gunButTexture);
    else gunfighterButton.setFillColor(Color(255,127,0));

    swordmanButton.setSize(Vector2f(450,300));
    swordmanButton.setPosition(650,300);
    if(sworButTexture.loadFromFile(R"(..\Textures\SwordmanButton.png)"))
        swordmanButton.setTexture(&sworButTexture);
    else swordmanButton.setFillColor(Color::Cyan);

    rulesButton.setSize(Vector2f(100,100));
    rulesButton.setPosition(1100,0);
    backButTexture.loadFromFile(R"(..\Textures\BackButton.png)");
    if(rulesButTexture.loadFromFile(R"(..\Textures\RulesButton.png)"))
        rulesButton.setTexture(&rulesButTexture);
    else rulesButton.setFillColor(Color::Magenta);

    font.loadFromFile(R"(..\Font\PublicPixel-0W5Kv.ttf)");
    highscoreText.setFont(font);
    highscoreText.setFillColor(Color::White);
    highscoreText.setOutlineThickness(4);
    highscoreText.setOutlineColor(Color::Black);
    highscoreText.setPosition(Vector2f(10,SCREEN_HEIGHT-40));
}

Menu::~Menu() = default;

void Menu::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed)
            window->close();
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !displayingRules){
            if (gunfighterButton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
                game = std::make_unique<Game>(window,0);
            else if(swordmanButton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
                game = std::make_unique<Game>(window,1);
            else if(rulesButton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))){
                displayingRules = true;
                rulesButton.setTexture(&backButTexture);
            }
        }else if(displayingRules && (  sf::Keyboard::isKeyPressed(Keyboard::Escape) ||( sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
                rulesButton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))) )  )){
            displayingRules = false;
            rulesButton.setTexture(&rulesButTexture);
        }

    }
}

void Menu::run() {
    while (window->isOpen()){
        handleEvent();
        draw();
        if(game != nullptr){
            srand(time(NULL));
            game->run();
            if(game->getPlayer()->getScore() > highscore)
                highscore=game->getPlayer()->getScore();
        }
    }
}

void Menu::draw() {
    window->clear();
    if(!displayingRules) {
        window->draw(gameTitle);
        window->draw(gunfighterButton);
        window->draw(swordmanButton);
        window->draw(rulesButton);
        highscoreText.setString("HIGHSCORE:" + std::to_string(highscore));
        window->draw(highscoreText);
    }else {
        window->draw(rules);
        window->draw(rulesButton);
    }window->display();
}
