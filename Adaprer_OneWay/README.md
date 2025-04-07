# One-Way Adapter Pattern

## Overview
The One-Way Adapter pattern is a structural design pattern that allows objects with incompatible interfaces to work together by converting the interface of one class into another interface that clients expect. The "one-way" aspect means that the adapter only provides conversion in one direction - from the adaptee's interface to the target interface.

## Problem
When working with existing code or third-party libraries, you often encounter situations where:
- You need to use a class that has an interface different from what your client code expects
- You can't modify the existing class (e.g., it's from a third-party library)
- You want to maintain compatibility with existing client code

## Solution
The One-Way Adapter pattern solves this by:
1. Creating a target interface that defines the operations clients expect
2. Creating an adapter class that:
   - Implements the target interface
   - Contains an instance of the adaptee (the class to be adapted)
   - Translates calls from the target interface to the adaptee's interface

## Structure
- **Target Interface**: Defines the interface that clients expect
- **Target**: Concrete implementation of the target interface
- **Adaptee**: The existing class with an incompatible interface
- **Adapter**: Wraps the adaptee and implements the target interface

## Use Cases
1. **Legacy Code Integration**: When you need to integrate legacy code with new systems
2. **Third-Party Library Integration**: When you need to use a third-party library with a different interface
3. **Interface Standardization**: When you want to standardize multiple different interfaces
4. **Testing**: When you need to create mock objects that implement a specific interface

## Example Implementation
```cpp
// Target interface
class TargetInterface {
public:
    virtual std::string do_operation() = 0;
};

// Target implementation
class Target : public TargetInterface {
public:
    std::string do_operation() override {
        return "doing operation";
    }
};

// Adaptee (existing class)
class ExternalLibrary {
public:
    std::string useful_operation() {
        return "A useful operation performed";
    }
};

// Adapter
class Adapter : public TargetInterface {
private:
    ExternalLibrary externalLibrary;

public:
    Adapter(const ExternalLibrary& externalLibrary)
        : externalLibrary(externalLibrary) {}

    std::string do_operation() override {
        return externalLibrary.useful_operation();
    }
};
```

## Benefits
1. **Single Responsibility Principle**: Separates interface conversion from the main business logic
2. **Open/Closed Principle**: You can introduce new adapters without changing existing code
3. **Reusability**: The same adapter can be used in multiple places
4. **Flexibility**: Makes it easy to switch between different implementations

## Drawbacks
1. **Complexity**: Introduces additional classes and complexity
2. **Performance Overhead**: Additional layer of indirection may impact performance
3. **One-Way Limitation**: Only provides conversion in one direction

## When to Use
- When you need to use an existing class but its interface doesn't match what you need
- When you want to create a reusable class that cooperates with unrelated classes
- When you need to use several existing subclasses but it's impractical to adapt their interface by subclassing each one

## When Not to Use
- When the interfaces are already compatible
- When the performance impact of the additional layer is unacceptable
- When you need two-way adaptation (consider Two-Way Adapter pattern instead) 