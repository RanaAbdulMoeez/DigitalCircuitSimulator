#include "BinaryProbe.h"

BinaryProbe::BinaryProbe() : Component(1, 0, string("Binary Probe")) {}

BinaryProbe::BinaryProbe(const BinaryProbe& other) : Component(other) {}

void BinaryProbe::resolve_output() {}

LogicValue BinaryProbe::get_value() { return input_pins[0].getValue(); }


void BinaryProbe::connect_input_pin(int idx, OutputPin* out_pin) { input_pins[0].connect(out_pin); }

void BinaryProbe::disconnect_input_pin(int idx) { input_pins[0].disconnect(); }

OutputPin* BinaryProbe::get_output_pin(int idx) { return nullptr; }

InputPin* BinaryProbe::get_input_pin(int idx) { return &input_pins[0]; }

BinaryProbe* BinaryProbe::clone() { return new BinaryProbe(); }
