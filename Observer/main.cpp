#include "ConcreteObserver.h"
#include "ConcreteObservable.h"

int main() {
    ConcreteObserver concreteObserver;
    ConcreteObservable concreteObservable;

    concreteObservable.attach(&concreteObserver);

    concreteObservable.changeState();

    return 0;
}
