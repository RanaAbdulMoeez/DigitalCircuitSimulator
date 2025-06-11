#include "OR2.h"

OR2::OR2() : LogicGate(2, 1, "2-OR") {}

OR2::OR2(const OR2& other) : LogicGate(other) {}

void OR2::resolve_output() {
    bool found_one = false;
    bool found_x = false;

    for (int i = 0; i < input_pins.size(); ++i) {
        LogicValue input_val = input_pins[i].getValue();

        if (input_val == LogicValue::ONE) {
            found_one = true;
            break;
        }
        if (input_val == LogicValue::X) {
            found_x = true;
        }
    }

    if (found_one) {
        output_pins[0]->change_value(LogicValue::ONE);
    }
    else if (found_x) {
        output_pins[0]->change_value(LogicValue::X);
    }
    else {
        output_pins[0]->change_value(LogicValue::ZERO);
    }
}

void OR2::connect_using_pointer(InputPin* in_pin, OutputPin* out_pin) {
	for (int i = 0; i < input_pins.size(); i++) {
		if (in_pin == &input_pins[i]) {
			input_pins[i].connect(out_pin);
		}
	}
}

void OR2::connect_using_index(int index, OutputPin* out_pin) {
	input_pins[index].connect(out_pin);
}

void OR2::disconnect(InputPin* in_pin) {
	for (int i = 0; i < input_pins.size(); i++) {
		if (in_pin == &input_pins[i]) {
			input_pins[i].disconnect();
		}
	}
}

LogicValue OR2::get_value() {
	return output_pins[0]->get_value();
}

OutputPin* OR2::get_pin() {
	return output_pins[0];
}
