#ifndef BINARYPROBE_H
#define BINARYPROBE_H
#include "Component.h"

class BinaryProbe: public Component {
public:
	BinaryProbe();
	BinaryProbe(const BinaryProbe& other);
	~BinaryProbe();
	void resolve_output() override;
	LogicValue get_value();
	void connect(OutputPin* output_pin);
	void disconnect();
};

#endif
