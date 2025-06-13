#include "Interface.h"
#include "Simulation.h"
#include "LogicValue.h"
#include "BinarySwitch.h"
#include "BinaryProbe.h"
#include <iostream>
using namespace std;

Interface* Interface::instance = nullptr;

Interface::Interface() : simulator(new Simulation()) {}

Interface* Interface::getInstance() {
    if (instance == nullptr) {
        instance = new Interface();
    }
    return instance;
}

void Interface::displayMenu() const {
    cout << "\n--- Commands ---\n";
    cout << "  1. add          - Add a new component\n";
    cout << "  2. connect      - Connect an output pin to an input pin\n";
    cout << "  3. disconnect   - Disconnect an input pin\n";
    cout << "  4. set_switch   - Set value of a Binary Switch\n";
    cout << "  5. get_probe    - Get value from a Binary Probe\n";
    cout << "  6. simulate     - Run circuit simulation (resolve outputs)\n";
    cout << "  7. list_avail   - List available component types\n";
    cout << "  8. list_current - List current components in simulation\n";
    cout << "  9. help         - Show this menu\n";
    cout << " 10. exit         - Exit the program\n";
    cout << "----------------\n";
}

void Interface::processCommand(const string& command_str) {
    string lower_command = command_str;
    for (char& c : lower_command) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
    }

    if (lower_command == "add") {
        handleAddComponent();
    }
    else if (lower_command == "connect") {
        handleConnectPins();
    }
    else if (lower_command == "disconnect") {
        handleDisconnectPins();
    }
    else if (lower_command == "set_switch") {
        handleSetSwitchValue();
    }
    else if (lower_command == "get_probe") {
        handleGetProbeValue();
    }
    else if (lower_command == "simulate") {
        handleRunSimulation();
    }
    else if (lower_command == "list_avail") {
        handleListAvailableComponents();
    }
    else if (lower_command == "list_current") {
        handleListCurrentComponents();
    }
    else if (lower_command == "help") {
        handleHelp();
    }
    else {
        cout << "Unknown command: '" << command_str << "'. Type 'help' for a list of commands.\n";
    }
}

void Interface::handleAddComponent() {
    cout << "\n--- Add Component ---\n";
    int type_idx = getIntInput("Enter component type index: ");
    simulator->add_component(type_idx);
}

void Interface::handleConnectPins() {
    cout << "\n--- Connect Pins ---\n";
    handleListCurrentComponents();
    cout << "\n--- Source Component (Output Pin) ---\n";
    int source_comp_idx = getIntInput("Enter index of source component: ");
    int source_pin_idx = getIntInput("Enter output pin index of source component: ");

    cout << "\n--- Target Component (Input Pin) ---\n";
    int target_comp_idx = getIntInput("Enter index of target component: ");
    int target_pin_idx = getIntInput("Enter input pin index of target component: ");

    simulator->connect(target_comp_idx, target_pin_idx, source_comp_idx, source_pin_idx);
}

void Interface::handleDisconnectPins() {
    cout << "\n--- Disconnect Pin ---\n";
    handleListCurrentComponents();

    int target_comp_idx = getIntInput("Enter index of component to disconnect input from: ");
    int target_pin_idx = getIntInput("Enter input pin index to disconnect: ");

    simulator->disconnect(target_comp_idx, target_pin_idx);
}

void Interface::handleSetSwitchValue() {
    cout << "\n--- Set Binary Switch Value ---\n";
    handleListCurrentComponents();

    int comp_idx = getIntInput("Enter index of Binary Switch: ");

    if (comp_idx >= 0 && comp_idx < simulator->components.size()) {
        Component* comp_ptr = simulator->components[comp_idx];
        BinarySwitch* bs_ptr = dynamic_cast<BinarySwitch*>(comp_ptr);
        if (bs_ptr) {
            string value_str = getStringInput("Enter value (0 or 1): ");
            if (value_str == "0") {
                bs_ptr->get_output_pin(0)->change_value(LogicValue::ZERO);
                cout << "Switch " << bs_ptr->getID() << " set to 0.\n";
            }
            else if (value_str == "1") {
                bs_ptr->get_output_pin(0)->change_value(LogicValue::ONE);
                cout << "Switch " << bs_ptr->getID() << " set to 1.\n";
            }
            else {
                cout << "Invalid value. Please enter '0' or '1'.\n";
            }
            simulator->resolve_output();
        }
        else {
            cout << "Component at index " << comp_idx << " is not a Binary Switch.\n";
        }
    }
    else {
        cout << "Invalid component index.\n";
    }
}

void Interface::handleGetProbeValue() {
    cout << "\n--- Get Binary Probe Value ---\n";
    handleListCurrentComponents();

    int comp_idx = getIntInput("Enter index of Binary Probe: ");

    if (comp_idx >= 0 && comp_idx < simulator->components.size()) {
        Component* comp_ptr = simulator->components[comp_idx];
        BinaryProbe* bp_ptr = dynamic_cast<BinaryProbe*>(comp_ptr);
        if (bp_ptr) {
            cout << "Probe " << bp_ptr->getID() << " value: " << logic_value_to_string(bp_ptr->get_value()) << endl;
        }
        else {
            cout << "Component at index " << comp_idx << " is not a Binary Probe.\n";
        }
    }
    else {
        cout << "Invalid component index.\n";
    }
}

void Interface::handleRunSimulation() {
    cout << "\n--- Running Simulation ---\n";
    if (!simulator) {
        cerr << "Simulator not initialized.\n";
        return;
    }
    simulator->map_components();
    simulator->resolve_output();
    cout << "Simulation complete. Check probe values.\n";
}

void Interface::handleListAvailableComponents() const {
    cout << "\n--- Available Component Types ---\n";
    cout << "  0: Binary Probe\n";
    cout << "  1: Binary Switch\n";
    cout << "  2: Wire\n";
    cout << "  3: AND2\n";
    cout << "  4: OR2\n";
    cout << "  5: NOT\n";
    cout << "------------------------------\n";
}

void print_padded(const string& s, int width) {
    cout << s;
    if (static_cast<int>(s.length()) < width) {
        for (int i = 0; i < width - static_cast<int>(s.length()); ++i) {
            cout << " ";
        }
    }
}

void Interface::handleListCurrentComponents() const {
    cout << "\n--- Current Components in Simulation ---\n";
    if (!simulator || simulator->components.empty()) {
        cout << "No components currently in simulation.\n";
        return;
    }

    print_padded("Idx", 5);
    print_padded("Type", 20);
    print_padded("ID", 15);
    print_padded("Inputs", 10);
    print_padded("Outputs", 10);
    cout << endl;
    cout << "------------------------------------------------------------------\n";

    for (int i = 0; i < simulator->components.size(); ++i) {
        Component* comp = simulator->components[i];
        if (comp) {
            print_padded(to_string(i), 5);
            print_padded(comp->get_name(), 20);
            print_padded(to_string(comp->getID()), 15);
            print_padded(to_string(comp->get_num_input_pins()), 10);
            print_padded(to_string(comp->get_num_output_pins()), 10);
            cout << endl;
        }
    }
    cout << "------------------------------------------------------------------\n";
}

void Interface::handleHelp() const {
    displayMenu();
}

void Interface::handleExit() {
    cout << "Initiating exit...\n";
}

int Interface::getIntInput(const string& prompt) const {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            char c;
            while (cin.get(c) && c != '\n');
        }
        else {
            char c;
            while (cin.get(c) && c != '\n');
            return value;
        }
    }
}

string Interface::getStringInput(const string& prompt) const {
    string value;
    cout << prompt;
    if (cin.peek() == '\n') {
        cin.ignore(1, '\n'); 
    }
    getline(cin, value);
    return value;
}

bool Interface::getYesNoInput(const string& prompt) const {
    string input;
    while (true) {
        cout << prompt << " (y/n): ";
        getline(cin, input);
        for (char& c : input) {
            if (c >= 'A' && c <= 'Z') {
                c = c + ('a' - 'A');
            }
        }
        if (input == "y" || input == "yes") {
            return true;
        }
        else if (input == "n" || input == "no") {
            return false;
        }
        else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }
}

void Interface::run() {
    cout << "\n--- Digital Circuit Simulator CLI ---\n";
    cout << "Type 'help' for commands.\n";
    string command_input;
    bool running = true;

    while (running) {
        cout << "\n> ";
        getline(cin, command_input);

        if (command_input == "exit") {
            handleExit();
            running = false;
        }
        else {
            processCommand(command_input);
        }
    }
    cout << "Exiting CLI. Goodbye!\n";
}
