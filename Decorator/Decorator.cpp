#include <iostream>
#include <string>

// Abstract base class
class IComponent {
public:
    virtual std::string operation() const = 0;
};

// ConcreteComponent class
class ConcreteComponent : public IComponent {
public:
    std::string operation() const override {
        return "Operation in the ConcreteComponent done.";
    }
};

// Decorator class
class Decorator : public IComponent {
public:
    IComponent* concreteComponent;

public:
    Decorator() : concreteComponent(new ConcreteComponent()) {}

    std::string operation() const override {
        return concreteComponent->operation();
    }

    ~Decorator() {
        delete concreteComponent;
    }

};

// FirstDecorator class
class FirstDecorator : public Decorator {
public:
    std::string operation() const override {
        std::string operation_description = Decorator::operation();
        return operation_description + " Operation in the FirstDecorator done.";
    }
};

// SecondDecorator class
class SecondDecorator : public Decorator {
public:
    std::string operation() const override {
        std::string operation_description = Decorator::operation();
        return operation_description + " Operation in the SecondDecorator done.";
    }
};

int main() {
    ConcreteComponent* component = new ConcreteComponent();

    std::string result = component->operation();
    std::cout << result << std::endl;


    // Decorate the component with firstDecorator
    FirstDecorator* firstDecorator = new FirstDecorator();
    firstDecorator->concreteComponent = component;
    result = firstDecorator->operation();
    std::cout << result << std::endl;


    // Decorate the component with secondDecorator
    SecondDecorator* secondDecorator = new SecondDecorator();
    secondDecorator->concreteComponent = component;
    result = secondDecorator->operation();
    std::cout << result << std::endl;


    // Decorate the component with firstDecorator and secondDecorator
    FirstDecorator* firstSecondDecorator = new FirstDecorator();
    firstSecondDecorator->concreteComponent = component;
    SecondDecorator* decorator2 = new SecondDecorator();
    firstSecondDecorator->concreteComponent = decorator2;
    result = firstSecondDecorator->operation();
    std::cout << result << std::endl;


    return 0;
}
