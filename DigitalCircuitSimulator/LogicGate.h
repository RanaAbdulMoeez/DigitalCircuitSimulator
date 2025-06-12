#ifndef LOGICGATE_H
#define LOGICGATE_H
#include "Component.h"

class LogicGate : public Component {
protected:
	LogicGate(int n_input_pipns, int n_output_pins, string _name);
public:
	LogicGate(const LogicGate& other);
	virtual LogicValue get_value() = 0;
};

#endif