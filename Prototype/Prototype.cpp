#include <iostream>
#include <string>

// Prototype interface
class Prototype {
public:
    virtual Prototype* clone() const = 0;
    virtual void display() const = 0;
    virtual ~Prototype() = default;
};

// Concrete Prototype
class ConcretePrototype : public Prototype {
private:
    std::string data;

public:
    ConcretePrototype(const std::string& data) : data(data) {
        std::cout << "ConcretePrototype constructor " << std::endl;
    }

    Prototype* clone() const override {
        return new ConcretePrototype(*this);
    }

    void display() const override {
        std::cout << "ConcretePrototype with data: " << data << std::endl;
    }
};

int main() {
    // Create an instance of a concrete prototype
    ConcretePrototype original("Original Data");

    // Clone the prototype to create a new object
    Prototype* clonedObject = original.clone();

    // Display the original and cloned objects
    original.display();          // Output: ConcretePrototype with data: Original Data
    clonedObject->display();     // Output: ConcretePrototype with data: Original Data
   
    // Clean up
    delete clonedObject;

    return 0;
}
