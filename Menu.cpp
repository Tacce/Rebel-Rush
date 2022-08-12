//
// Created by Francesco Taccetti on 10/08/2022.
//

#include "Menu.h"

Menu::Menu(): game(nullptr), highscore(0) {
    window = std::make_shared<RenderWindow>(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Rebel Rush");
    window->setFramerateLimit(60);

    titleTexture.loadFromFile(R"(..\Textures\TitleMenu.png)");
    gunButTexture.loadFromFile(R"(..\Textures\GunfighterButton.png)");
    sworButTexture.loadFromFile(R"(..\Textures\SwordmanButton.png)");

    gameTitle.setTexture(titleTexture);

    gunfighterButton.setSize(Vector2f(450,300));
    gunfighterButton.setPosition(100,300);
    gunfighterButton.setTexture(&gunButTexture);
    //gunfighterButton.setFillColor(Color(255,127,0));

    swordmanButton.setSize(Vector2f(450,300));
    swordmanButton.setPosition(650,300);
    //swordmanButton.setFillColor(Color::Cyan);
    swordmanButton.setTexture(&sworButTexture);

    font.loadFromFile(R"(..\Font\PublicPixel-0W5Kv.ttf)");
    highscoreText.setFont(font);
    highscoreText.setFillColor(Color::White);
    highscoreText.setOutlineThickness(4);
    highscoreText.setOutlineColor(Color::Black);
    highscoreText.setPosition(Vector2f(10,SCREEN_HEIGHT-40));
}

void Menu::handleEvent() {
    while (window->pollEvent(event)) {
        if (event.type == Event::Closed)
            window->close();
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if (gunfighterButton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
                game = std::make_unique<Game>(window,0);
            else if(swordmanButton.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window))))
                game = std::make_unique<Game>(window,1);
        }
    }
}

Menu::~Menu() = default;

void Menu::run() {
    while (window->isOpen()){
        handleEvent();
        draw();
        if(game!=nullptr){
            srand(time(NULL));
            game->run();
            if(game->getPlayer()->getScore() > highscore)
                highscore=game->getPlayer()->getScore();
        }
    }
}

void Menu::draw() {
    window->clear();
    window->draw(gameTitle);
    window->draw(gunfighterButton);
    window->draw(swordmanButton);
    highscoreText.setString("HIGHSCORE:" + std::to_string(highscore));
    window->draw(highscoreText);
    window->display();
}
