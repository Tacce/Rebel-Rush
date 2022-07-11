#include <SFML/Graphics.hpp>
#include <iostream>
#include "Definitions.h"
#include "GameCharacter.h"

int main(){
    using namespace sf;
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Escape from Hazotic City");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
}