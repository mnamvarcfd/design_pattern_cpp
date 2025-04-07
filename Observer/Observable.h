#pragma once
#include <vector>
#include <string>
#include "Observer.h"

class Observable {
private:
    std::vector<Observer*> observers;

public:
    std::string state = "";

    void attach(Observer* observer);
    void detach(Observer* observer);
    void notifyObservers();
};