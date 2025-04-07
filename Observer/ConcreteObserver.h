#pragma once
#include <iostream>

#include "Observer.h"

class ConcreteObserver : public Observer {
public:
    void update() override;
};