#include "AND2.h"

AND2::AND2() : LogicGate(2,1,"2-AND") {}

AND2::AND2(const AND2& other) : LogicGate(other) {}

void AND2::resolve_output() {
	for (int i = 0; i < input_pins.size(); i++) {
		if (input_pins[i].getValue() == LogicValue::ZERO) {
			output_pins[0]->change_value(LogicValue::ZERO);
			return;
		}
		else if (input_pins[i].getValue() == LogicValue::X) {
			output_pins[0]->change_value(LogicValue::X);
			return;
		}
	}
	output_pins[0]->change_value(LogicValue::ONE);
}

LogicValue AND2::get_value() {
	return output_pins[0]->get_value();
}

void AND2::connect_input_pin(int idx, OutputPin* out_pin) { input_pins[idx].connect(out_pin); }

void AND2::disconnect_input_pin(int idx) { input_pins[idx].disconnect(); }

OutputPin* AND2::get_output_pin(int idx) { return output_pins[0]; }

InputPin* AND2::get_input_pin(int idx) { return &input_pins[idx]; }

AND2* AND2::clone() { return new AND2(); }