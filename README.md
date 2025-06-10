Digital Circuit Simulator
=========================

This project is a basic digital circuit simulator built using C++ and Object-Oriented Programming (OOP). It simulates circuits made up of components like binary switches, logic gates, and binary probes.

Project Overview
----------------

When the simulation is run, it starts from all binary switches and maps out the entire circuit/s. The simulator stores the circuit in a structured array based on logic depth. This ensures that all inputs are resolved before any outputs are computed.

Class Overview
--------------

1.  **LogicValue**An enum with three possible values:
    
    *   0 (Zero)
        
    *   1 (One)
        
    *   X (Unknown or Unresolved)
        
2.  **OutputPin**
    
    *   Holds a LogicValue.
        
3.  **InputPin**
    
    *   Points to an OutputPin.
        
4.  **Component** (Base Class)
    
    *   Has a dynamic array of input pins.
        
    *   Has a dynamic array of output pins.
        
    *   Has a virtual function resolve_output() which is overridden by derived classes.
        

Derived Component Classes
-------------------------

1.  **LogicGate**
    
    *   Inherits from Component.
        
    *   Has N input pins and 1 output pin.
        
        
2.  **BinarySwitch**
    
    *   Inherits from Component.
        
    *   Has 1 output pin and 0 input pins.
        
3.  **BinaryProbe**
    
    *   Inherits from Component.
        
    *   Has 1 input pin and 0 output pins.
        
4.  **Wire**
    
    *   Inherits from Component.
        
    *   Has 1 input pin and N output pins.
        

Circuit and Simulation
----------------------

*   The circuit is stored in  a 2d array of components with each rows indicating the logic depth.
    
*   Logic depth increases by one each time an output is passed to a new component.
    
*   Components are grouped in arrays by their logic depth.
    
*   These arrays are stored in a dynamic array, allowing the simulator to process components in the correct order.
    

Simulation Steps
----------------

1.  The simulation starts from all BinarySwitch components.
    
2.  The entire circuit is traversed and mapped into a structured format based on depth.

3. Each component is assigned a circuit ID, starting from a binary switch and theoretically it should map out all the components connected in the circuit. 
   If it encounters a circuit with an assigned id then it stops that path. 
   So, if you move onto the next binary switch that does not have an id it means it is a separate circuit.
    
4.  Components at each logic depth level are resolved in order.
    
5.  Outputs are computed only after all required inputs are resolved.

![image](https://github.com/user-attachments/assets/92a9d4f9-17f8-4c3f-9a86-1a3a3630019f)

![image](https://github.com/user-attachments/assets/9eb4e109-4ae5-478d-9f12-a0d14cfd8804)



