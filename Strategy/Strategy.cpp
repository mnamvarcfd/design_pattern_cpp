#include <iostream>

// Strategy interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
};

// Concrete Strategy 1
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paying " << amount << " using Credit Card" << std::endl;
    }
};

// Concrete Strategy 2
class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paying " << amount << " using PayPal" << std::endl;
    }
};

// Context
class ShoppingCart {
private:
    PaymentStrategy* paymentStrategy;

public:
    ShoppingCart(PaymentStrategy* strategy) : paymentStrategy(strategy) {}

    void checkout(int totalAmount) {
        paymentStrategy->pay(totalAmount);
    }
};

// Client code
int main() {
    // Client can choose the payment strategy at runtime
    CreditCardPayment creditCardPayment;
    PayPalPayment paypalPayment;

    // Create contexts with different payment strategies
    ShoppingCart cart1(&creditCardPayment);
    ShoppingCart cart2(&paypalPayment);

    // Checkout with different payment strategies
    cart1.checkout(1000); // Pays with Credit Card
    cart2.checkout(500);  // Pays with PayPal

    return 0;
}
