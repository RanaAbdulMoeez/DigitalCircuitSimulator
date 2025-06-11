#ifndef NOT_H
#define NOT_H
#include "LogicGate.h"

class NOT : public LogicGate {
public:
	NOT();
	NOT(const NOT& other);
	void resolve_output() override;
	void connect_using_pointer(InputPin* in_pin, OutputPin* out_pin) override;
	void connect_using_index(int idx, OutputPin* out_pin) override;
	void disconnect(InputPin* in_pin) override;
	LogicValue get_value() override;
	OutputPin* get_pin() override;
};


#endif