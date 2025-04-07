# Command Pattern

## Overview
The Command pattern is a behavioral design pattern that turns a request into a stand-alone object that contains all information about the request. This transformation lets you parameterize methods with different requests, delay or queue a request's execution, and support undoable operations.

## Real-Life Example: TV Remote Control

Imagine you have a TV remote control. The remote doesn't know how to turn the TV on/off or change channels - it just sends commands. The TV (receiver) knows how to perform these actions. This is a perfect example of the Command pattern.

### Components in the TV Remote Example:

1. **Command Interface** (Button on Remote)
   - Defines the interface for all commands
   - Has an `execute()` method that all commands must implement

2. **Receiver** (TV)
   - Knows how to perform the actual operations
   - Has methods like `turnOn()`, `turnOff()`, `changeChannel()`

3. **Concrete Commands** (Specific Buttons)
   - `TurnOnCommand`: Turns the TV on
   - `TurnOffCommand`: Turns the TV off
   - `ChangeChannelCommand`: Changes the TV channel

4. **Invoker** (Remote Control)
   - Holds the commands
   - Executes them when buttons are pressed

## Code Example
```cpp
#include <iostream>
#include <string>

// Command Interface
class Command {
public:
    virtual void execute() = 0;
};

// Receiver (TV)
class TV {
public:
    void turnOn() {
        std::cout << "TV is turned ON\n";
    }
    
    void turnOff() {
        std::cout << "TV is turned OFF\n";
    }
    
    void changeChannel(int channel) {
        std::cout << "Channel changed to " << channel << "\n";
    }
};

// Concrete Commands
class TurnOnCommand : public Command {
private:
    TV* tv;
public:
    TurnOnCommand(TV* tv) : tv(tv) {}
    void execute() override {
        tv->turnOn();
    }
};

class TurnOffCommand : public Command {
private:
    TV* tv;
public:
    TurnOffCommand(TV* tv) : tv(tv) {}
    void execute() override {
        tv->turnOff();
    }
};

class ChangeChannelCommand : public Command {
private:
    TV* tv;
    int channel;
public:
    ChangeChannelCommand(TV* tv, int channel) : tv(tv), channel(channel) {}
    void execute() override {
        tv->changeChannel(channel);
    }
};

// Invoker (Remote Control)
class RemoteControl {
private:
    Command* button;
public:
    void setCommand(Command* cmd) {
        button = cmd;
    }
    void pressButton() {
        button->execute();
    }
};

int main() {
    // Create the TV (receiver)
    TV tv;
    
    // Create commands
    TurnOnCommand turnOn(&tv);
    TurnOffCommand turnOff(&tv);
    ChangeChannelCommand changeChannel(&tv, 5);
    
    // Create remote control (invoker)
    RemoteControl remote;
    
    // Use the remote
    remote.setCommand(&turnOn);
    remote.pressButton();    // TV turns on
    
    remote.setCommand(&changeChannel);
    remote.pressButton();    // Channel changes to 5
    
    remote.setCommand(&turnOff);
    remote.pressButton();    // TV turns off
    
    return 0;
}
```

## Benefits in this Example
1. **Decoupling**: The remote control doesn't need to know how the TV works
2. **Flexibility**: Easy to add new commands (like volume control)
3. **Queue Support**: Could easily add a "program" feature to queue multiple commands
4. **Undo Support**: Could add an undo feature to reverse the last command

## Real-World Applications
1. **GUI Applications**: Menu items and buttons
2. **Transaction Systems**: Banking operations
3. **Multi-level Undo/Redo**: Text editors
4. **Macro Recording**: Recording and replaying sequences of commands
5. **Job Queues**: Scheduling and executing tasks

## When to Use
- When you want to parameterize objects with operations
- When you want to queue operations, schedule their execution, or execute them remotely
- When you need to implement reversible operations
- When you want to structure a system around high-level operations built on primitive operations 