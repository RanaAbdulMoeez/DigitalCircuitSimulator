#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Component.h"
#include "Wire.h"

class Circuit {
public:
	MyVector<MyVector<Component*>> components;
	MyVector<MyVector<Component*>> wires;
	int circuitID;
	int num_components;
	int depth;
public:
	Circuit();
	Circuit(int id);
	Circuit(const Circuit& other);
	Circuit& operator=(const Circuit& other);
	~Circuit();
	void resolve_output();
	void add_component(Component* comp, int logic_depth);
	void add_wire(Component* comp, int logic_depth);
	bool check_component(Component* comp);
	bool check_wire(Component* wire);
};

#endif
