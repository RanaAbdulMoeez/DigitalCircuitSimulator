#ifndef WIRE_H
#define WIRE_H
#include "Component.h"

class Wire : public Component {
public:
	Wire();
	Wire(const Wire& other);
	~Wire();
	void resolve_output() override;
	OutputPin* getPin(int idx);
	void connect(OutputPin* pin);
	void disconnect();
	void add_output_Pin();
	void remove_output_pin(OutputPin* pin);
};

#endif
