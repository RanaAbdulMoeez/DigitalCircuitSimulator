#ifndef COMPONENT_H
#define COMPONENT_H
#include "MyVector.h"
#include "InputPin.h"

class Component {
protected:
	int circuit_id;
	string name;
	MyVector<OutputPin*> output_pins;
	MyVector<InputPin> input_pins;
	Component(int n_input_pins, int n_output_pins, string _name);
	Component(const Component& other);
public:
	Component& operator=(const Component& other);
	void setID(int circuitNo);
	void resetID();
	int getID();
	virtual void resolve_output() = 0;
	virtual ~Component();
	virtual void connect_input_pin(int idx, OutputPin* out_pin) = 0;
	virtual void disconnect_input_pin(int idx) = 0;
	virtual OutputPin* get_output_pin(int idx) = 0;
	virtual Component* clone() = 0;
	string get_name();
	virtual InputPin* get_input_pin(int idx) = 0;
	int get_num_output_pins();
	int get_num_input_pins();
};

#endif