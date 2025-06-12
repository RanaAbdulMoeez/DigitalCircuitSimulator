#ifndef SIMULATION_H
#define SIMULATION_H
#include "Circuit.h"
#include "BinarySwitch.h"
#include "BinaryProbe.h"
#include "Wire.h"
#include "AND2.h"
#include "OR2.h"
#include "NOT.h"

class Simulation {
private:
	friend class Interface;
	static Simulation* instance;
	MyVector<Circuit> circuits;
	MyVector<Component*> components;
	MyVector<Component*> available_components;
	Simulation();
	Simulation(const Simulation&) = delete;
	Simulation& operator=(const Simulation&) = delete;

public:
	void add_component(int idx);
	void remove_component_pointer(Component* comp);
	void remove_component_index(int idx);
	void map_components();
	void resolve_output();
	void connect(int idx11, int idx12, int idx21, int idx22);
	void disconnect(int idx1, int idx2);
	static Simulation* get_instance();
};

#endif
