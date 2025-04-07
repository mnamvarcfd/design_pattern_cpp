#include <iostream>
#include <vector>

// Forward declaration of classes to break circular dependency
class ConcreteElement;

// Visitor interface
class Visitor {
public:
    virtual void visit(ConcreteElement& element) const = 0;
};

// Element interface
class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

// Concrete Element
class ConcreteElement : public Element {
public:
    void accept(Visitor& visitor) override {
        visitor.visit(*this);
    }

    void operation() const {
        std::cout << "ConcreteElement did operation\n";
    }
};

// Concrete Visitor
class ConcreteVisitor : public Visitor {
public:
    void visit(ConcreteElement& element) const override {
        std::cout << "ConcreteVisitor visits ConcreteElement\n";
        element.operation();
    }
};

int main() {
    // Create instances of concrete elements and a concrete visitor
    ConcreteElement element;
    ConcreteVisitor visitor;

    // Elements accept the visitor
    element.accept(visitor);  

    return 0;
}
