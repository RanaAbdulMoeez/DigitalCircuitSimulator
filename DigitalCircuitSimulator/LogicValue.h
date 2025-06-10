#ifndef LOGICVALUE_H
#define LOGICVALUE_H
#include "String.h"

enum class LogicValue {
	ZERO = 0,
	ONE = 1,
	X = 2
};

String logic_value_to_string(LogicValue value);

#endif
