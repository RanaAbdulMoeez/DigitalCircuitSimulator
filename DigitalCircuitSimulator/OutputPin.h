#ifndef OUTPUTPIN_H
#define OUTPUTPIN_H
#include "LogicValue.h"

class InputPin;
class Component;

class OutputPin {
private:
	friend class InputPin;

	InputPin* input_pin;
	LogicValue value;
	Component* owner_component;

	void connect(InputPin* in_pin);
	void disconnect();
	void setOwnerComponent(Component* owner);
public:
	OutputPin();
	OutputPin(Component* owner);
	OutputPin(const OutputPin& other);
	OutputPin(LogicValue _value);
	OutputPin& operator=(const OutputPin& other);
	~OutputPin();
	void change_value(LogicValue _value);
	LogicValue get_value();
	InputPin* get_connection();
	Component* getOwnerComponent();
};

#endif