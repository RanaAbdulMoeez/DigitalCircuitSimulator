#ifndef BINARYSWITCH_H
#define BINARYSWITCH_H
#include "Component.h"

class BinarySwitch : public Component {
public:
	BinarySwitch();
	BinarySwitch(const BinarySwitch& other);
	void resolve_output() override;
	void change_value();
	LogicValue get_value();
	void connect_input_pin(int idx, OutputPin* out_pin) override;
	void disconnect_input_pin(int idx) override;
	OutputPin* get_output_pin(int idx) override;
	InputPin* get_input_pin(int idx) override;
	BinarySwitch* clone() override;
};

#endif