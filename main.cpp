#include "Definitions.h"
#include "GameCharacter.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

int main(){
    srand(time(NULL));
    int a=1;
    //std::cout << "PRESS 0 PLAY AS GUNFIGHTER OR PRESS 1 PLAY AS SWORDMAN" << std::endl;
    //std::cin >> a;
    Game game(a);
    game.run();
}


