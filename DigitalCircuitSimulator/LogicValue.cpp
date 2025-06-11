#include "LogicValue.h"

string logic_value_to_string(LogicValue value) {
    switch (value) {
    case LogicValue::ZERO:
        return "0";
    case LogicValue::ONE:
        return "1";
    case LogicValue::X:
        return "X";
    }
}