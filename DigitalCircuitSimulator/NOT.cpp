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

void NOT::connect_using_pointer(InputPin* in_pin, OutputPin* out_pin) {
    for (int i = 0; i < input_pins.size(); i++) {
        if (in_pin == &input_pins[i]) {
            input_pins[i].connect(out_pin);
        }
    }
}

void NOT::connect_using_index(int index, OutputPin* out_pin) {
    input_pins[index].connect(out_pin);
}

void NOT::disconnect(InputPin* in_pin) {
    for (int i = 0; i < input_pins.size(); i++) {
        if (in_pin == &input_pins[i]) {
            input_pins[i].disconnect();
        }
    }
}

LogicValue NOT::get_value() {
    return output_pins[0]->get_value();
}

OutputPin* NOT::get_pin() {
    return output_pins[0];
}
