#ifndef OR2_H
#define OR2_H
#include "LogicGate.h"

class OR2 : public LogicGate {
public:
	OR2();
	OR2(const OR2& other);
	void resolve_output() override;
	LogicValue get_value() override;
	void connect_input_pin(int idx, OutputPin* out_pin) override;
	void disconnect_input_pin(int idx) override;
	OutputPin* get_output_pin(int idx) override;
	InputPin* get_input_pin(int idx) override;
	OR2* clone() override;
};

#endif
