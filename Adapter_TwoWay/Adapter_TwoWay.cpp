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

// Adapter from TargetInterface to ExternalLibrary
class TargetAdapter : public TargetInterface {
private:
    ExternalLibrary externalLibrary;

public:
    TargetAdapter(const ExternalLibrary& externalLibrary)
        : externalLibrary(externalLibrary) {}

    std::string do_operation() override {
        // Adapt the legacy operation to the new interface
        return externalLibrary.useful_operation();
    }
};

// Adapter from ExternalLibrary to TargetInterface
class ExternalLibraryAdapter : public ExternalLibrary, public TargetInterface {
public:
    std::string do_operation() override {
        // Adapt the external library operation to the target interface
        return useful_operation();
    }
};

int main() {
    // Usage with Target
    Target target;
    std::string result1 = client_code(target);
    std::cout << result1 << std::endl;

    // Usage with TargetAdapter
    ExternalLibrary externalLibrary;
    TargetAdapter targetAdapter(externalLibrary);
    std::string result2 = client_code(targetAdapter);
    std::cout << result2 << std::endl;

    // Usage with ExternalLibraryAdapter
    ExternalLibraryAdapter externalLibraryAdapter;
    std::string result3 = client_code(externalLibraryAdapter);
    std::cout << result3 << std::endl;

    return 0;
}
