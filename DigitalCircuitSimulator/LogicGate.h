#ifndef LOGICGATE_H
#define LOGICGATE_H
#include "Component.h"

class LogicGate : public Component {
protected:
	LogicGate(int n_input_pipns, int n_output_pins, string _name);
public:
	LogicGate(const LogicGate& other);
	virtual void resolve_output() override = 0;
	virtual void connect_using_pointer(InputPin* in_pin, OutputPin* out_pin) = 0;
	virtual void connect_using_index(int index, OutputPin* out_pin) = 0;
	virtual void disconnect(InputPin* in_pin) = 0;
	virtual LogicValue get_value() = 0;
	virtual OutputPin* get_pin() = 0;
};

#endif