//
// Created by Francesco Taccetti on 05/09/2022.
//

#include <memory>
#include "KillCounterObserver.h"

KillCounterObserver::KillCounterObserver(const std::shared_ptr <GameCharacter>& subject, std::shared_ptr<RectangleShape> badge): subject(subject), badge(std::move(badge)){
    subject->registerObserver(this);
    goldTexture.loadFromFile(R"(Textures\GoldBadge.png)");
    silverTexture.loadFromFile(R"(Textures\SilverBadge.png)");
    bronzeTexture.loadFromFile(R"(Textures\BronzeBadge.png)");
}

KillCounterObserver::~KillCounterObserver() {
    subject->removeObserver(this);
}

void KillCounterObserver::update() {
    int killCount= subject->getKillCounter();
    if(killCount >= 30)
        badge->setTexture(&goldTexture);
    else if(killCount >= 22)
        badge->setTexture(&silverTexture);
    else if(killCount >= 15) {
        badge->setFillColor(Color::White);
        badge->setTexture(&bronzeTexture);
    }
}

