#ifndef INPUTPIN_H
#define INPUTPIN_H
#include "OutputPin.h"

class InputPin {
private:
	OutputPin* connection;
public:
	InputPin();
	InputPin(const InputPin& other);
	InputPin(OutputPin* _connection);
	InputPin& operator=(const InputPin& other);
	~InputPin();
	void connect(OutputPin* pin);
	void disconnect();
	bool is_connected();
};





#endif