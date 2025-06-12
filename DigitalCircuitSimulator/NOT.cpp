#include "NOT.h"

NOT::NOT() : LogicGate(2, 1, "NOT") {}

NOT::NOT(const NOT& other) : LogicGate(other) {}

void NOT::resolve_output() {
    if (input_pins[0].getValue() == LogicValue::ZERO) {
        output_pins[0]->change_value(LogicValue::ONE);
    }
    else if (input_pins[0].getValue() == LogicValue::ONE) {
        output_pins[0]->change_value(LogicValue::ZERO);
    }
    else {
        output_pins[0]->change_value(LogicValue::X);
    }
}

LogicValue NOT::get_value() {
    return output_pins[0]->get_value();
}

void NOT::connect_input_pin(int idx, OutputPin* out_pin) { input_pins[idx].connect(out_pin); }

void NOT::disconnect_input_pin(int idx) { input_pins[idx].disconnect(); }

OutputPin* NOT::get_output_pin(int idx) { return output_pins[0]; }

InputPin* NOT::get_input_pin(int idx) { return &input_pins[0]; }

NOT* NOT::clone() { return new NOT(); }