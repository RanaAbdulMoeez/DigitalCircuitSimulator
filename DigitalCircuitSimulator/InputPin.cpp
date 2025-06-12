#include "InputPin.h"

InputPin::InputPin() : connection(nullptr), owner_component(nullptr) {}

InputPin::InputPin(Component* owner) : connection(nullptr), owner_component(owner) {};

InputPin::InputPin(const InputPin& other) 
	: connection(other.connection), owner_component(other.owner_component) {}

InputPin& InputPin::operator=(const InputPin & other) {
	if (this != &other) {
		connection = other.connection;
		owner_component = other.owner_component;
	}
	return *this;
}

InputPin::~InputPin() {}

void InputPin::connect(OutputPin* pin) {
	if (is_connected()) {
		pin->disconnect();
	}
	connection = pin;
	connection->connect(this);
}

void InputPin::disconnect() {
	if (is_connected()) {
		connection->disconnect();
		connection = nullptr;
	}
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

void InputPin::setOwnerComponent(Component* owner) { owner_component = owner; }

Component* InputPin::getOwnerComponent() { return owner_component; }

OutputPin* InputPin::get_output_pin() {
	return connection;
}