#include "Wire.h"

Wire::Wire() : Component(1, 1, string("Wire")) {}

Wire::Wire(const Wire& other) : Component(other) {}

void Wire::resolve_output() {
	for (int i = 0; i < output_pins.size(); i++) {
		output_pins[i]->change_value(input_pins[0].getValue());
	}
}

void Wire::add_output_Pin() { output_pins.push(new OutputPin()); }

void Wire::remove_output_pin(OutputPin* pin) {
	for (int i = 0; i < output_pins.size(); i++) {
		if (output_pins[i] == pin) {
			output_pins.delete_at(i);
			break;
		}
	}
}

void Wire::connect_input_pin(int idx, OutputPin* out_pin) { input_pins[0].connect(out_pin); }

void Wire::disconnect_input_pin(int idx) { input_pins[0].disconnect(); }

OutputPin* Wire::get_output_pin(int idx) { 
	if (idx - output_pins.size() == 0) {
		add_output_Pin();
	}
	return output_pins[idx]; 
}

InputPin* Wire::get_input_pin(int idx) { return &input_pins[0]; }

Wire* Wire::clone() { return new Wire(); }
