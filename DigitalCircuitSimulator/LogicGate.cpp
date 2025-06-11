#include "LogicGate.h"

LogicGate::LogicGate(int n_input_pipns, int n_output_pins, string _name) : Component(n_input_pipns, n_output_pins, _name) {}

LogicGate::LogicGate(const LogicGate& other) : Component(other) {}