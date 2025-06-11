#ifndef AND2_H
#define AND2_H
#include "LogicGate.h"

class AND2 : public LogicGate {
public:
	AND2();
	AND2(const AND2& other);
	void resolve_output() override;
	void connect_using_pointer(InputPin* in_pin, OutputPin* out_pin) override;
	void connect_using_index(int idx, OutputPin* out_pin) override;
	void disconnect(InputPin* in_pin) override;
	LogicValue get_value() override;
	OutputPin* get_pin() override;
};

#endif
