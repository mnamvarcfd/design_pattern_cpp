#pragma once
#include "Observable.h"

class ConcreteObservable : public Observable {
public:
    ConcreteObservable();
    void changeState();
};