#include "ConcreteObservable.h"

ConcreteObservable::ConcreteObservable()
{
}

void ConcreteObservable::changeState()
{
    state = "I changed";
    notifyObservers();
}

