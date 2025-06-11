#include "BinaryProbe.h"

BinaryProbe::BinaryProbe() : Component(1, 0, string("Binary Probe")) {}

BinaryProbe::BinaryProbe(const BinaryProbe& other) : Component(other) {}

void BinaryProbe::resolve_output() {}

LogicValue BinaryProbe::get_value() { return input_pins[0].getValue(); }

void BinaryProbe::connect(OutputPin* output_pin) { input_pins[0].connect(output_pin); }

void BinaryProbe::disconnect() { input_pins[0].disconnect(); }
