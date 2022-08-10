//
// Created by Francesco Taccetti on 10/08/2022.
//

#include "Menu.h"

Menu::Menu(): game(nullptr) {
    window = std::make_shared<RenderWindow>(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Escape from Hazotic City");
    window->setFramerateLimit(60);

    gunfighterButton.setSize(Vector2f(450,300));
    gunfighterButton.setPosition(100,300);
    gunfighterButton.setFillColor(Color(255,127,0));
    swordmanButton.setSize(Vector2f(450,300));
    swordmanButton.setPosition(650,300);
    swordmanButton.setFillColor(Color::Cyan);
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
        if(game!=nullptr)
            game->run();
    }
}

void Menu::draw() {
    window->clear();
    window->draw(gunfighterButton);
    window->draw(swordmanButton);
    window->display();
}
