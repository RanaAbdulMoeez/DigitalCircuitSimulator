#include "Wire.h"

Wire::Wire() : Component(1, 1, string("Wire")) {}

Wire::Wire(const Wire& other) : Component(other) {}

Wire::~Wire() {}

void Wire::resolve_output() {
	for (int i = 0; i < output_pins.size(); i++) {
		output_pins[i]->change_value(input_pins[0].getValue());
	}
}

OutputPin* Wire::getPin(int idx) { return output_pins[idx]; }

void Wire::connect(OutputPin* pin) { input_pins[0].connect(pin); }

void Wire::disconnect() { input_pins[0].disconnect(); }

void Wire::add_output_Pin() { output_pins.push(new OutputPin()); }

void Wire::remove_output_pin(OutputPin* pin) {
	for (int i = 0; i < output_pins.size(); i++) {
		if (output_pins[i] == pin) {
			output_pins.delete_at(i);
			break;
		}
	}
}
