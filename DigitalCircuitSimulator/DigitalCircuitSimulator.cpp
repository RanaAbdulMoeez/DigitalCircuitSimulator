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
		
	w1.connect(bs1.getPin());
	bp1.connect(w1.getPin(0));
	w1.add_output_Pin();
	w2.connect(w1.getPin(1));
	bp2.connect(w2.getPin(0));

	bs1.resolve_output();
	w1.resolve_output();
	w1.resolve_output();
	w2.resolve_output();
	
	cout << logic_value_to_string(bp1.get_value());
	cout << " " << logic_value_to_string(bp2.get_value());
	return 0;
}