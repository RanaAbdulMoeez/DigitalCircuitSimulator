#include "OutputPin.h"

OutputPin::OutputPin() : value(LogicValue::X) {}

OutputPin::OutputPin(const OutputPin& other) : value(other.value) {}

OutputPin::OutputPin(LogicValue _value) : value(_value) {}

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