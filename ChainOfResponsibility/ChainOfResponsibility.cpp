#include <iostream>
#include <string>

// Handler interface
class Handler {
public:
    virtual void handleRequest(const std::string& request) = 0;
    virtual void setnext(Handler* next) = 0;
};

// ConcreteHandler A
class ConcreteHandlerA : public Handler {
private:
    Handler* next;

public:
    void handleRequest(const std::string& request) override {
        if (request == "A") {
            std::cout << "ConcreteHandlerA handles the request: " << request << std::endl;
        }
        else if (next != nullptr) {
            next->handleRequest(request);
        }
    }

    void setnext(Handler* next) override {
        this->next = next;
    }
};

// ConcreteHandler B
class ConcreteHandlerB : public Handler {
private:
    Handler* next;

public:
    void handleRequest(const std::string& request) override {
        if (request == "B") {
            std::cout << "ConcreteHandlerB handles the request: " << request << std::endl;
        }
        else if (next != nullptr) {
            next->handleRequest(request);
        }
    }

    void setnext(Handler* next) override {
        this->next = next;
    }
};

// Client code
int main() {
    // Create instances of concrete handlers
    ConcreteHandlerA handlerA;
    ConcreteHandlerB handlerB;

    // Set the next for handlerA
    handlerA.setnext(&handlerB);

    // Make requests
    handlerA.handleRequest("A");  // Output: ConcreteHandlerA handles the request: A
    handlerA.handleRequest("B");  // Output: ConcreteHandlerB handles the request: B
    handlerA.handleRequest("C");  // Output: (no handler can handle the request)

    return 0;
}
