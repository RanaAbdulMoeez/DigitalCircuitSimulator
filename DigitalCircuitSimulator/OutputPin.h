#ifndef OUTPUTPIN_H
#define OUTPUTPIN_H
#include "LogicValue.h"

class OutputPin {
private:
	LogicValue value;
public:
	OutputPin();
	OutputPin(const OutputPin& other);
	OutputPin(LogicValue _value);
	OutputPin& operator=(const OutputPin& other);
	~OutputPin();
	void change_value(LogicValue _value);
	LogicValue get_value();
};

#endif