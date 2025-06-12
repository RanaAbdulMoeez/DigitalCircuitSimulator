#ifndef NOT_H
#define NOT_H
#include "LogicGate.h"

class NOT : public LogicGate {
public:
	NOT();
	NOT(const NOT& other);
	void resolve_output() override;
	LogicValue get_value() override;
	void connect_input_pin(int idx, OutputPin* out_pin) override;
	void disconnect_input_pin(int idx) override;
	OutputPin* get_output_pin(int idx) override;
	InputPin* get_input_pin(int idx) override;
	NOT* clone() override;
};


#endif