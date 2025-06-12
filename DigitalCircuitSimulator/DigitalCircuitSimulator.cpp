#include <iostream>
using namespace std;
#include "Interface.h"
#include "Circuit.h"

int main() {

	Interface::getInstance()->run();

	return 0;
}