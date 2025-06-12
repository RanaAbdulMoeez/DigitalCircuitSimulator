#include "Simulation.h"

Simulation* Simulation::instance = nullptr;

Simulation::Simulation() {
    available_components.push(new BinaryProbe());
    available_components.push(new BinarySwitch());
    available_components.push(new Wire());
    available_components.push(new AND2());
    available_components.push(new OR2());
    available_components.push(new NOT());
}

Simulation* Simulation::get_instance() {
    if (instance == nullptr) {
        instance = new Simulation();
    }
    return instance;
}

void Simulation::add_component(int idx) {
    components.push(available_components[idx]->clone()); 
}

void Simulation::remove_component_pointer(Component* comp) {
    for (int i = 0; i < components.size(); i++) {
        if (comp == components[i]) {
            components.delete_at(i);
        }
    }
}

void Simulation::remove_component_index(int idx) {
    components.delete_at(idx);
}

void Simulation::map_components() {
    circuits.clear();
    MyVector<int> binary_switches;
    for (int i = 0; i < components.size(); i++) {
        if (components[i]->get_name() == "Binary Switch") {
            binary_switches.push(i);
        }
    }
    int circuit_no = 0;
    circuits.push(Circuit(1));
    MyVector<bool> visited(components.size(), false);
    MyVector<int> queue;

    int v;
    for (int j = 0; j < binary_switches.size(); j++) {
        if (components[binary_switches[j]]->getID() == -1) {
            circuit_no++;
            queue.clear();
            queue.push(binary_switches[j]);
            while (queue.size() > 0) {
                v = queue[0];
                queue.delete_at(0);
                if (visited[v] == false) {
                    components[v]->setID(circuit_no);
                    visited.assign_at(v, true);
                    for (int i = 0; i < components[v]->get_num_output_pins(); i++) {
                        int index = components.find(components[v]->get_output_pin(i)->get_connection()->getOwnerComponent());
                        if (visited[index] == false) {
                            queue.push(index);
                        }
                    }
                    for (int i = 0; i < components[v]->get_num_input_pins(); i++) {
                        int index = components.find(components[v]->get_input_pin(i)->get_output_pin()->getOwnerComponent());
                        if (visited[index] == false) {
                            queue.push(index);
                        }
                    }
                }
            }
        }
    }

    int circuit_id = 1;
    for (int i = 0; i < binary_switches.size(); i++) {
        int depth = 1;
        Component* current_comp = components[binary_switches[i]];
        circuit_id = current_comp->getID();

        do {

            if((!circuits[circuit_id - 1].check_component(current_comp)) && (current_comp->get_name() != "Wire"))
                circuits[circuit_id - 1].add_component(current_comp, depth);

            for (int j = 0; j < current_comp->get_num_output_pins(); j++) {
                Component* comp2 = current_comp->get_output_pin(j)->get_connection()->getOwnerComponent();
                if ((comp2->get_name() == "Wire") && !circuits[circuit_id - 1].check_wire(comp2)) {
                    circuits[circuit_id - 1].add_wire(comp2, depth);

                    for (int k = 0; k < comp2->get_num_output_pins(); k++) {
                        Component* comp3 = comp2->get_output_pin(k)->get_connection()->getOwnerComponent();
                        if ((comp3->get_name() == "Wire") && !circuits[circuit_id - 1].check_wire(comp3)) {
                            circuits[circuit_id - 1].add_wire(comp3, depth);
                        }
                    }
                }
                else {
                    current_comp = comp2;
                    if(current_comp->get_name() != "Wire")
                        depth++;
                    break;
                }
            } 
        } while (current_comp->get_output_pin(0) != nullptr);
        if ((current_comp->get_name() != "Wire"))
            circuits[circuit_id - 1].add_component(current_comp, depth);
        else
            circuits[circuit_id - 1].add_wire(current_comp, depth - 1);
    }
}



void Simulation::resolve_output() {
    map_components();
    for (int i = 0; i < circuits.size(); i++) {
        circuits[i].resolve_output();
    }
}

void Simulation::connect(int idx11, int idx12, int idx21, int idx22) {
    components[idx11]->connect_input_pin(idx12, components[idx21]->get_output_pin(idx22));
}

void Simulation::disconnect(int idx1, int idx2) {
    components[idx1]->disconnect_input_pin(idx2);
}