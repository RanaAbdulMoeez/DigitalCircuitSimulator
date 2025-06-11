#include <iostream>
using namespace std;
#include "BinarySwitch.h"
#include "BinaryProbe.h"
#include "Wire.h"

int main() {
	BinarySwitch bs1;
	BinaryProbe bp1;
	BinaryProbe bp2;
	Wire w1;
	Wire w2;

	w1.add_output_Pin();
	w1.connect(bs1.getPin());
	bp1.connect(w1.getPin(0));
	w2.connect(w1.getPin(1));
	bp2.connect(w1.getPin(1));



	for (int i = 0; i < 5; i++) {
		bs1.resolve_output();
		w1.resolve_output();
		w2.resolve_output();
		cout << logic_value_to_string(bp1.get_value());
		cout << " " << logic_value_to_string(bp2.get_value());
		bs1.change_value();
	}
	return 0;
}