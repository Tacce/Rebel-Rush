//
// Created by Francesco Taccetti on 05/09/2022.
//

#ifndef TACCETTIELABORATO_KILLCOUNTEROBSERVER_H
#define TACCETTIELABORATO_KILLCOUNTEROBSERVER_H

#include "GameCharacter.h"
class KillCounterObserver :public Observer{
public:
    KillCounterObserver(const std::shared_ptr<GameCharacter>& subject, std::shared_ptr<RectangleShape> badge);
    virtual ~KillCounterObserver();
    void update() override;

private:
    std::shared_ptr<GameCharacter> subject;
    std::shared_ptr<RectangleShape> badge;
    Texture goldTexture, silverTexture, bronzeTexture;

};


#endif //TACCETTIELABORATO_KILLCOUNTEROBSERVER_H
