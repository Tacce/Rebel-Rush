#include "Definitions.h"
#include "GameCharacter.h"
#include "Game.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main(){
    srand(time(NULL));
    Menu menu;
    menu.run();
}


