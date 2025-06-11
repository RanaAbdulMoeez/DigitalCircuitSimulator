#include "InputPin.h"

InputPin::InputPin() : connection(nullptr) {}

InputPin::InputPin(const InputPin& other) : connection(other.connection) {}

InputPin::InputPin(OutputPin* _connection) : connection(_connection) {}

InputPin& InputPin::operator=(const InputPin & other) {
	if (this != &other) {
		connection = other.connection;
	}
	return *this;
}

InputPin::~InputPin() {}

void InputPin::connect(OutputPin* pin) {
	connection = pin;
}

void InputPin::disconnect() {
	connection = nullptr;
}

bool InputPin::is_connected() {
	if (connection == nullptr)
		return false;
	else
		return true;
}

LogicValue InputPin::getValue() {
	if (is_connected())
		return connection->get_value();
	else
		return LogicValue::X;
}
