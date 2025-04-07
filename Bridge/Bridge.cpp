#include <iostream>

// Implementor interface
class Implementor {
public:
    virtual void performAction() const = 0;
};

// Concrete Implementor A
class ConcreteImplementorA : public Implementor {
public:
    void performAction() const override {
        std::cout << "Concrete Implementor A is performing the action\n";
    }
};

// Concrete Implementor B
class ConcreteImplementorB : public Implementor {
public:
    void performAction() const override {
        std::cout << "Concrete Implementor B is performing the action\n";
    }
};

// Abstraction interface
class Abstraction {
protected:
    Implementor* implementor;

public:
    Abstraction(Implementor* impl) : implementor(impl) {}

    virtual void executeAction() const = 0;
};

// Refined Abstraction
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}

    void executeAction() const override {
        implementor->performAction();
    }
};

int main() {
    // Create instances of concrete implementors
    ConcreteImplementorA implementorA;
    ConcreteImplementorB implementorB;

    // Create instances of refined abstractions with different implementors
    RefinedAbstraction abstractionA(&implementorA);
    RefinedAbstraction abstractionB(&implementorB);

    // Execute actions through the refined abstractions
    abstractionA.executeAction();  // Output: Concrete Implementor A is performing the action
    abstractionB.executeAction();  // Output: Concrete Implementor B is performing the action

    return 0;
}
