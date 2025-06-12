#ifndef BINARYPROBE_H
#define BINARYPROBE_H
#include "Component.h"

class BinaryProbe: public Component {
public:
	BinaryProbe();
	BinaryProbe(const BinaryProbe& other);
	void resolve_output() override;
	LogicValue get_value();
	void connect_input_pin(int idx, OutputPin* out_pin) override;
	void disconnect_input_pin(int idx) override;
	OutputPin* get_output_pin(int idx) override;
	InputPin* get_input_pin(int idx) override;
	BinaryProbe* clone() override;
};

#endif
