#include <iostream>
#include <vector>

// Command interface: defines the operations that each state must handle
class Command {
public:
    virtual void execute() = 0;
};

// Receiver class: that will be affected/used when the command gets executed
// indeed it contains the action to be done finally
class Receiver {
public:
    void action() {
        std::cout << "Receiver is performing an action\n";
    }
};

// Concrete Command class: that contains the context necessary for the execution of 
// the operation, and the implementation of the 
// Command interface
class ConcreteCommand : public Command {
private:
    Receiver* receiver;

public:
    ConcreteCommand(Receiver* recv) : receiver(recv) {}

    void execute() override {
        receiver->action();
    }
};

// Invoker class: creates the command object to carry out the operation
// (list of commands to be executed). It knows which operation to be performed
class Invoker {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* command) {
        commands.push_back(command);
    }

    void executeCommands() {
        for (Command* command : commands) {
            command->execute();
        }
        commands.clear();
    }
};

int main() {
    // Create instances of Receiver and ConcreteCommand
    Receiver receiver;
    ConcreteCommand concreteCommand(&receiver);

    // Create an instance of Invoker and associate it with a ConcreteCommand
    Invoker invoker;
    invoker.addCommand(&concreteCommand);

    // Execute the command through the invoker
    invoker.executeCommands();  // Output: Receiver is performing an action

    return 0;
}
