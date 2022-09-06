//
// Created by Francesco Taccetti on 05/09/2022.
//

#ifndef TACCETTIELABORATO_SUBJECT_H
#define TACCETTIELABORATO_SUBJECT_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "Observer.h"


class Subject {
public:
    virtual void registerObserver(Observer *observer) ;
    virtual void removeObserver(Observer *observer);
    virtual void notifyObservers() = 0;

protected:
    std::vector<Observer *> observers;

};


#endif //TACCETTIELABORATO_SUBJECT_H
