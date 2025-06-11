#ifndef LOGICVALUE_H
#define LOGICVALUE_H
#include <string>
using namespace std;

enum class LogicValue {
	ZERO = 0,
	ONE = 1,
	X = 2
};

string logic_value_to_string(LogicValue value);

#endif
