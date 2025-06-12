#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>  
#include <iostream> 

class Simulation;

class Interface {
private:

    static Interface* instance;
    Simulation* simulator;

    Interface();
    Interface(const Interface&) = delete;
    Interface& operator=(const Interface&) = delete;
    Interface(Interface&&) = delete;
    Interface& operator=(Interface&&) = delete;
    void displayMenu() const;
    void processCommand(const std::string& command);
    void handleAddComponent();
    void handleConnectPins();
    void handleDisconnectPins();
    void handleSetSwitchValue();
    void handleGetProbeValue();
    void handleRunSimulation();
    void handleListAvailableComponents() const;
    void handleListCurrentComponents() const;
    void handleHelp() const;
    void handleExit();

    int getIntInput(const std::string& prompt) const;
    std::string getStringInput(const std::string& prompt) const;
    bool getYesNoInput(const std::string& prompt) const;

public:
    static Interface* getInstance();

    static void cleanup() {
        if (instance != nullptr) {
            std::cout << "Interface instance being cleaned up.\n";
            delete instance;
            instance = nullptr;
        }
    }

    void run();
};

#endif
