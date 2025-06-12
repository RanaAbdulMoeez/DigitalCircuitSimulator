#include "OutputPin.h"

OutputPin::OutputPin() : value(LogicValue::X), input_pin(nullptr), owner_component(nullptr) {}

OutputPin::OutputPin(Component* owner) : value(LogicValue::X), input_pin(nullptr), owner_component(owner) {};

OutputPin::OutputPin(const OutputPin& other) : value(other.value), input_pin(other.input_pin), owner_component(other.owner_component) {}

OutputPin::OutputPin(LogicValue _value) : value(_value), input_pin(nullptr), owner_component(nullptr) {}

OutputPin& OutputPin::operator=(const OutputPin& other) {
	if (this != &other) {
		value = other.value;
	}
	return *this;
}

OutputPin::~OutputPin() {}

void OutputPin::change_value(LogicValue _value){
	value = _value;
}

LogicValue OutputPin::get_value() { return value; }

void OutputPin::connect(InputPin* in_pin) { input_pin = in_pin;  }

void OutputPin::disconnect() { input_pin = nullptr; }

InputPin* OutputPin::get_connection() { return input_pin; }

void OutputPin::setOwnerComponent(Component* comp) {
	owner_component = comp;
}

Component* OutputPin::getOwnerComponent() {
	return owner_component;
}
