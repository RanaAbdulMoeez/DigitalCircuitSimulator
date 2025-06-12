#include "Circuit.h"

Circuit::Circuit() : num_components(0), depth(1), circuitID(-1) {	
	MyVector<Component*> new_comp_layer;
	components.push(new_comp_layer);
	MyVector<Component*> new_wire_layer;
	wires.push(new_wire_layer);
}

Circuit::Circuit(int id) : circuitID(id), num_components(0), depth(1) {
	MyVector<Component*> new_comp_layer;
	components.push(new_comp_layer);
	MyVector<Component*> new_wire_layer;
	wires.push(new_wire_layer);
}

Circuit::Circuit(const Circuit& other)
	: components(other.components), wires(other.wires), circuitID(other.circuitID), 
	num_components(other.num_components), depth(other.depth) {}

Circuit& Circuit::operator=(const Circuit& other) {
	if (this != &other) {
		components = other.components;
		wires = other.wires;
		circuitID = other.circuitID;
		num_components = other.num_components;
		depth = other.depth;
	}
	return *this;
}

Circuit::~Circuit() {
	for (int i = 0; i < components.size(); i++) {
		for (int j = 0; j < components[i].size(); j++) {
			components[i][j]->resetID();
		}
	}
	for (int i = 0; i < wires.size(); i++) {
		for (int j = 0; j < wires[i].size(); j++) {
			wires[i][j]->resetID();
		}
	}
}

void Circuit::resolve_output() {
	int i = 0;
	for (; i < components.size(); i++) {
		for (int j = 0; j < components[i].size(); j++) {
			components[i][j]->resolve_output();
		}
		for (int j = 0; j < wires[i].size(); j++) {
			wires[i][j]->resolve_output();
		}
	}
}

void Circuit::add_component(Component* comp, int logic_depth) {
	if (logic_depth - depth == 1) {
		depth++;
		MyVector<Component*> new_comp_layer;
		components.push(new_comp_layer);
		MyVector<Component*> new_wire_layer;
		wires.push(new_wire_layer);
	}
	components[logic_depth - 1].push(comp);
}

void Circuit::add_wire(Component* comp, int logic_depth) {
	//if (logic_depth - depth == 1) {
	//	depth++;
	//	MyVector<Component*> new_comp_layer;
	//	components.push(new_comp_layer);
	//	MyVector<Component*> new_wire_layer;
	//	wires.push(new_wire_layer);
	//}
	wires[logic_depth - 1].push(comp);
}

bool Circuit::check_component(Component* comp) {
	for (int i = 0; i < components.size(); i++) {
		for (int j = 0; j < components[i].size(); j++) {
			if (components[i][j] == comp) {
				return true;
			}
		}
	}
	return false;
}

bool Circuit::check_wire(Component* wire) {
	for (int i = 0; i < wires.size(); i++) {
		for (int j = 0; j < wires[i].size(); j++) {
			if (wires[i][j] == wire) {
				return true;
			}
		}
	}
	return false;
}

