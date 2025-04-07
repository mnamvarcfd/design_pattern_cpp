#include <iostream>
#include <string>
#include <vector>

// Memento class
class Memento {
private:
    std::string state;

public:
    Memento(const std::string& state) : state(state) {}

    std::string getState() const {
        return state;
    }
};

// Originator class
class Originator {
private:
    std::string state;

public:
    void setState(const std::string& state) {
        this->state = state;
    }

    std::string getState() const {
        return state;
    }

    Memento createMemento() const {
        return Memento(state);
    }

    void restoreFromMemento(const Memento& memento) {
        state = memento.getState();
    }
};

// Caretaker class
class Caretaker {
private:
    std::vector<Memento> mementoList;

public:
    void addMemento(const Memento& memento) {
        mementoList.push_back(memento);
    }

    Memento getMemento(int index) const {
        if (index >= 0 && index < mementoList.size()) {
            return mementoList[index];
        }
        return Memento("");
    }
};

int main() {
    // Create instances of Originator and Caretaker
    Originator originator;
    Caretaker caretaker;

    // Set the state of the originator and save the state in the caretaker
    originator.setState("State 1");
    caretaker.addMemento(originator.createMemento());

    // Set a new state of the originator and save the state in the caretaker
    originator.setState("State 2");
    caretaker.addMemento(originator.createMemento());

    // Restore the originator's state from the first memento
    originator.restoreFromMemento(caretaker.getMemento(0));
    std::cout << "Current state of the originator: " << originator.getState() << std::endl;

    return 0;
}
