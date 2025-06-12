#ifndef WIRE_H
#define WIRE_H
#include "Component.h"

class Wire : public Component {
public:
	Wire();
	Wire(const Wire& other);
	void resolve_output() override;
	void add_output_Pin();
	void remove_output_pin(OutputPin* pin);
	void connect_input_pin(int idx, OutputPin* out_pin) override;
	void disconnect_input_pin(int idx) override;
	OutputPin* get_output_pin(int idx) override;
	InputPin* get_input_pin(int idx) override;
	Wire* clone() override;
};

#endif
