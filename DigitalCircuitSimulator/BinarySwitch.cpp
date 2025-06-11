#include "BinarySwitch.h"

BinarySwitch::BinarySwitch() : Component(0, 1, "Binary Switch") {
	output_pins[0].change_value(LogicValue::ZERO);
}

BinarySwitch::BinarySwitch(const BinarySwitch& other) : Component(other) {}

BinarySwitch::~BinarySwitch() {}

void BinarySwitch::resolve_output() {}

void BinarySwitch::change_value() {
	if (output_pins[0].get_value() == LogicValue::ZERO)
		output_pins[0].change_value(LogicValue::ONE);
	else
		output_pins[0].change_value(LogicValue::ZERO);
	resolve_output();
}

LogicValue BinarySwitch::get_value() { return output_pins[0].get_value(); }
