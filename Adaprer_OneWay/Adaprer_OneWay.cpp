#include <iostream>

// Target interface class
class TargetInterface {
public:
    virtual std::string do_operation() = 0;
};

// Target class
class Target : public TargetInterface {
public:
    std::string do_operation() override {
        return "doing operation";
    }
};

// Client code function
std::string client_code(TargetInterface& target) {
    return target.do_operation();
}

// External library class
class ExternalLibrary {
public:
    std::string useful_operation() {
        return "A useful operation performed";
    }
};

// One-Way Adapter
class Adapter : public TargetInterface {
private:
    ExternalLibrary externalLibrary;

public:
    Adapter(const ExternalLibrary& externalLibrary)
        : externalLibrary(externalLibrary) {}

    std::string do_operation() override {
        // Adapt the legacy operation to the new interface
        return externalLibrary.useful_operation();
    }
};

int main() {
    // Usage with Target
    Target target;
    std::string result1 = client_code(target);
    std::cout << result1 << std::endl;

    // Usage with Adapter
    ExternalLibrary externalLibrary;
    Adapter adapter(externalLibrary);
    std::string result2 = client_code(adapter);
    std::cout << result2 << std::endl;

    return 0;
}
