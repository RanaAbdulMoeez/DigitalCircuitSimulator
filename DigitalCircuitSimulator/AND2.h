#ifndef AND2_H
#define AND2_H
#include "LogicGate.h"

class AND2 : public LogicGate {
public:
	AND2();
	AND2(const AND2& other);
	void resolve_output() override;
	LogicValue get_value() override;
	void connect_input_pin(int idx, OutputPin* out_pin) override;
	void disconnect_input_pin(int idx) override;
	OutputPin* get_output_pin(int idx) override;
	InputPin* get_input_pin(int idx) override;
	AND2* clone() override;
};

#endif