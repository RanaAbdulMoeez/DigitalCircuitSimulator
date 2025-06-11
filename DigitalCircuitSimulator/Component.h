#ifndef COMPONENT_H
#define COMPONENT_H
#include "MyVector.h"
#include "InputPin.h"

class Component {
protected:
	string id;
	string name;
	MyVector<OutputPin> output_pins;
	MyVector<InputPin> input_pins;
	Component(int n_input_pins, int n_output_pins, string _name);
	Component(const Component& other);
public:
	Component& operator=(const Component& other);
	void setID(int circuitNo, int componentNo);
	void resetID();
	string getID();
	virtual void resolve_output() = 0;
	virtual ~Component();
};

#endif