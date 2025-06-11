#include "Component.h"

Component::Component(int n_input_pins, int n_output_pins, string _name) 
	: id(), name(_name), input_pins(n_input_pins, InputPin()) {
	for (int i = 0; i < n_output_pins; i++) {
		output_pins.push(new OutputPin());
	}
}

Component::Component(const Component& other) 
	: id(other.id), name(other.name), input_pins(other.input_pins) {

	for (int i = 0; i < other.output_pins.size(); i++) {
		output_pins.push(new OutputPin(*other.output_pins[i]));
	}
}

Component& Component::operator=(const Component& other) {
	if (this != &other) {
		id = other.id;
		name = other.name;
		input_pins = other.input_pins;
		for (int i = 0; i < output_pins.size(); i++) {
			delete output_pins[i];
		}
		MyVector<OutputPin*> temp;
		for (int i = 0; i < other.output_pins.size(); i++) {
			temp.push(new OutputPin(*other.output_pins[i]));
		}
		output_pins = temp;
	}
	return *this;
}

void Component::setID(int circuitNo, int componentNo) {
	id = to_string(circuitNo).append(string("-").append(to_string(componentNo)));
}

void Component::resetID() { id = string("\0"); }

string Component::getID() { return id; }

Component::~Component() {
	for (int i = 0; i < output_pins.size(); i++) {
		delete output_pins[i];
	}
};