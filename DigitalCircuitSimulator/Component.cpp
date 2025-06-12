#include "Component.h"

Component::Component(int n_input_pins, int n_output_pins, string _name) 
	: circuit_id(-1), name(_name), input_pins(n_input_pins, InputPin(this)) {
	for (int i = 0; i < n_output_pins; i++) {
		output_pins.push(new OutputPin(this));
	}
}

Component::Component(const Component& other) 
	: circuit_id(other.circuit_id), name(other.name), input_pins(other.input_pins) {

	for (int i = 0; i < other.output_pins.size(); i++) {
		output_pins.push(new OutputPin(*other.output_pins[i]));
	}
}

Component& Component::operator=(const Component& other) {
	if (this != &other) {
		circuit_id = other.circuit_id;
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

void Component::setID(int circuitNo) {
	circuit_id = circuitNo;
}

void Component::resetID() { circuit_id = -1; }

int Component::getID() { return circuit_id; }

Component::~Component() {
	for (int i = 0; i < output_pins.size(); i++) {
		delete output_pins[i];
	}
};

string Component::get_name() { return name; }

int Component::get_num_output_pins() {
	return output_pins.size();
}

int Component::get_num_input_pins() {
	return input_pins.size();
}
