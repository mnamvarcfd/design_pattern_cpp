#include <iostream>

// Abstract State class
class State {
public:
    virtual void handle() = 0;
};

// Concrete State classes
class ConcreteStateA : public State {
public:
    void handle() override {
        std::cout << "Handling state A\n";
        // Additional logic for handling state A
    }
};

class ConcreteStateB : public State {
public:
    void handle() override {
        std::cout << "Handling state B\n";
        // Additional logic for handling state B
    }
};

// Context class that maintains a reference to the current state
class Context {
private:
    State* currentState;

public:
    Context(State* initialState) : currentState(initialState) {}

    void setState(State* newState) {
        currentState = newState;
    }

    void request() {
        currentState->handle();
    }
};

int main() {
    // Create instances of concrete states
    ConcreteStateA stateA;
    ConcreteStateB stateB;

    // Create a context with an initial state
    Context context(&stateA);

    // Perform requests on the context, which will delegate to the current state
    context.request();  // Output: Handling state A

    // Change the state of the context
    context.setState(&stateB);

    // Perform requests again, now with the updated state
    context.request();  // Output: Handling state B

    return 0;
}
