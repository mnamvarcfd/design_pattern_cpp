#include <iostream>
#include <string>

class Colleague;

// Mediator interface
class Mediator {
public:
    virtual void sendMessage(const Colleague* sender, const std::string& message) const = 0;
};

// Concrete Mediator
class ConcreteMediator : public Mediator {
private:
    Colleague* colleagueA;
    Colleague* colleagueB;

public:
    void setColleagues(Colleague* colleagueA, Colleague* colleagueB) {
        this->colleagueA = colleagueA;
        this->colleagueB = colleagueB;
    }

    void sendMessage(const Colleague* sender, const std::string& message) const override {
        if (sender == colleagueA) {
            colleagueB->receiveMessage(message);
        }
        else if (sender == colleagueB) {
            colleagueA->receiveMessage(message);
        }
    }
};

// Colleague interface
class Colleague {
protected:
    Mediator* mediator;

public:
    Colleague(Mediator* mediator) : mediator(mediator) {}

    virtual void sendMessage(const std::string& message) const {
        mediator->sendMessage(this, message);
    }

    virtual void receiveMessage(const std::string& message) const = 0;
};

// Concrete Colleague A
class ConcreteColleagueA : public Colleague {
public:
    ConcreteColleagueA(Mediator* mediator) : Colleague(mediator) {}

    void receiveMessage(const std::string& message) const override {
        std::cout << "ConcreteColleagueA received message: " << message << std::endl;
    }
};

// Concrete Colleague B
class ConcreteColleagueB : public Colleague {
public:
    ConcreteColleagueB(Mediator* mediator) : Colleague(mediator) {}

    void receiveMessage(const std::string& message) const override {
        std::cout << "ConcreteColleagueB received message: " << message << std::endl;
    }
};

int main() {
    // Create instances of concrete colleagues and a mediator
    ConcreteColleagueA colleagueA(nullptr);
    ConcreteColleagueB colleagueB(nullptr);
    ConcreteMediator mediator;

    // Set the colleagues for the mediator
    mediator.setColleagues(&colleagueA, &colleagueB);

    // Set the mediator for the colleagues
    colleagueA = ConcreteColleagueA(&mediator);
    colleagueB = ConcreteColleagueB(&mediator);

    // Colleagues send messages through the mediator
    colleagueA.sendMessage("Hello from Colleague A!");
    colleagueB.sendMessage("Hi from Colleague B!");

    return 0;
}
