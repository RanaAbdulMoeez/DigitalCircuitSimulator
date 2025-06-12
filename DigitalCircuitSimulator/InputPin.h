#ifndef INPUTPIN_H
#define INPUTPIN_H
#include "OutputPin.h"

class Component;

class InputPin {
private:
	friend class Component;
	OutputPin* connection;
	Component* owner_component;
	void setOwnerComponent(Component* owner);
public:
	InputPin();
	InputPin(const InputPin& other);
	InputPin(Component* owner);
	InputPin& operator=(const InputPin& other);
	~InputPin();
	void connect(OutputPin* pin);
	void disconnect();
	bool is_connected();
	LogicValue getValue();
	Component* getOwnerComponent();
	OutputPin* get_output_pin();
};

#endif