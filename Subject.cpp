//
// Created by Francesco Taccetti on 05/09/2022.
//

#include "Subject.h"

void Subject::registerObserver(Observer *observer) {
    observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer) {
    auto iterator = std::find(observers.begin(), observers.end(), observer);
    if (iterator != observers.end()) {
        observers.erase(iterator);
    }
}
