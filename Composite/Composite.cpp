#include <iostream>
#include <vector>

// Component interface
class Component {
public:
    virtual void operation() const = 0;
    virtual ~Component() = default;
};

// Leaf class
class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Leaf operation\n";
    }
};

// Composite class
class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Composite operation\n";
        for (const auto& child : children) {
            child->operation();
        }
    }

    ~Composite() override {
        for (auto& child : children) {
            delete child;
        }
    }
};

int main() {
    // Create instances of Leaf
    Leaf leaf1, leaf2;

    // Create instance of Composite and add Leaf objects
    Composite composite;
    composite.add(&leaf1);
    composite.add(&leaf2);

    // Perform operations on both Leaf and Composite
    leaf1.operation();      // Output: Leaf operation
    leaf2.operation();      // Output: Leaf operation
    composite.operation();  // Output: Composite operation
    // Output: Leaf operation
    // Output: Leaf operation

    return 0;
}
