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

void AND2::connect_using_pointer(InputPin* in_pin, OutputPin* out_pin) {
	for (int i = 0; i < input_pins.size(); i++) {
		if (in_pin == &input_pins[i]) {
			input_pins[i].connect(out_pin);
		}
	}
}

void AND2::connect_using_index(int index, OutputPin* out_pin) {
	input_pins[index].connect(out_pin);
}

void AND2::disconnect(InputPin* in_pin) {
	for (int i = 0; i < input_pins.size(); i++) {
		if (in_pin == &input_pins[i]) {
			input_pins[i].disconnect();
		}
	}
}

LogicValue AND2::get_value() {
	return output_pins[0]->get_value();
}

OutputPin* AND2::get_pin() {
	return output_pins[0];
}
