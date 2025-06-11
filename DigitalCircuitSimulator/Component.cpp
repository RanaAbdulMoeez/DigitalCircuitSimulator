#include "Component.h"

Component::Component(int n_input_pins, int n_output_pins, string _name) 
	: id(), name(_name), output_pins(n_output_pins, OutputPin()), 
	input_pins(n_input_pins, InputPin()) {}

Component::Component(const Component& other) 
	: id(other.id), name(other.name), input_pins(other.input_pins), output_pins(other.output_pins) {}

Component& Component::operator=(const Component& other) {
	if (this != &other) {
		id = other.id;
		name = other.name;
		input_pins = other.input_pins;
		output_pins = other.output_pins;
	}
	return *this;
}

void Component::setID(int circuitNo, int componentNo) {
	id = to_string(circuitNo).append(string("-").append(to_string(componentNo)));
}

void Component::resetID() { id = string("\0"); }

string Component::getID() { return id; }

Component::~Component() {};