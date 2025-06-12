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

LogicValue OR2::get_value() {
	return output_pins[0]->get_value();
}

void OR2::connect_input_pin(int idx, OutputPin* out_pin) { input_pins[idx].connect(out_pin); }

void OR2::disconnect_input_pin(int idx) { input_pins[idx].disconnect(); }

OutputPin* OR2::get_output_pin(int idx) { return output_pins[0]; }

InputPin* OR2::get_input_pin(int idx) { return &input_pins[idx]; }

OR2* OR2::clone() { return new OR2(); }
