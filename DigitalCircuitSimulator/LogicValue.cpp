#include "LogicValue.h"

string logic_value_to_string(LogicValue value) {
    switch (value) {
    case LogicValue::ZERO:
        return string("0");
    case LogicValue::ONE:
        return string("1");
    case LogicValue::X:
        return string("X");
    }
}