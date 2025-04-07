#include <vector>
#include <string>
#include "Observable.h"

void Observable::attach(Observer* observer) {
    observers.push_back(observer);
}

void Observable::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Observable::notifyObservers() {
    for (Observer* observer : observers) {
        observer->update();
    }
}