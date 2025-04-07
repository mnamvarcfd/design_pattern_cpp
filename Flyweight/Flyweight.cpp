#include <iostream>
#include <string>
#include <unordered_map>

// Flyweight interface
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) const = 0;
};

// Concrete Flyweight
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState;  // Shared state

public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(const std::string& extrinsicState) const override {
        std::cout << "Concrete Flyweight with intrinsic state '" << intrinsicState
            << "' and extrinsic state '" << extrinsicState << "'\n";
    }
}; 

// Flyweight Factory
class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights;

public:
    Flyweight* getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            // Create a new flyweight if it doesn't exist
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }

    ~FlyweightFactory() {
        for (auto& pair : flyweights) {
            delete pair.second;
        }
    }
};

int main() {
    FlyweightFactory factory;

    // Clients requesting Flyweight objects
    Flyweight* flyweight1 = factory.getFlyweight("A");
    flyweight1->operation("X");

    Flyweight* flyweight2 = factory.getFlyweight("B");
    flyweight2->operation("Y");

    Flyweight* flyweight3 = factory.getFlyweight("A");
    flyweight3->operation("Z");

    return 0;
}
