#ifndef BINARYSWITCH_H
#define BINARYSWITCH_H
#include "Component.h"

class BinarySwitch : public Component {
public:
	BinarySwitch();
	BinarySwitch(const BinarySwitch& other);
	~BinarySwitch();
	void resolve_output() override;
	void change_value();
	LogicValue get_value();
	OutputPin* getPin();
};

#endif