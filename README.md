Smart Office Rooms 
===

[Smart Office Rooms](https://github.com/HiralMistry/Smart-Office-Rooms) is an event loop manager designed to make the rooms of oofices smart which do not require active controlling. The rooms automatically turn ON/OFF the appliances such as lights, AC, Heater etc. It makes the offices Smart by turning ON the appliance as it detects anybody present in the room. It saves energy and prevents the wastage of electricity by automatically switching off all the appliances if the room is not occupied. 
The source code for this project is forked from [on github](https://github.com/klavinslab/elma_project).

StateMachine Diagram
===
Click [here](https://photos.app.goo.gl/CYFqcsyUnEZc4Pyc6) to see the statemachine diagram.

Installation
---

    git clone https://github.com/HiralMistry/Smart-Office-Rooms
    docker run -v $PWD:/source -it klavins/elma:latest bash
    make
    make docs


Testing
---
To run tests, do
```bash
bin/test
```

Architecture
---

This project makes use of statemachine, which uses 4 states and 10 events. 
The states are like these:
1) Idle : This is an entry point for statemachine "SmartRoom"
2) Not occupied : This state indicates no body is inside the room.
3) Occupied off : This state is for indicating lights in 'OFF' condition, Heater/AC are ON and works accoring to room temperature.
4) Occupied on : This state is for indicating lights in 'ON' condition, Heater/AC are ON and works accoring to room temperature.

The Events are like these:
1) add_transition("start", idle, not_occup) 
- - It goes form IdleState to Not_Occupied_All_OFF state when 'start' event is detected   
    
2) add_transition("No Motion Detected", not_occup, not_occup);
- - It remains in the same state state Not_Occupied_All_OFF when there is no motion in the room   
    
3) add_transition("Motion Detected & light required", not_occup, all_on);
- - It goes form Not_Occupied_All_OFF to Occupied_All_ON state when motion is detected and lights are require to keep ON
    
4) add_transition("No Motion Detected", all_on, not_occup); 
- - It goes form Occupied_All_ON to Not_Occupied_All_OFF state if motion no longer exists in the room
    
5) add_transition("Motion Detected & light not required", all_on, light_off);
- - It goes form Occupied_All_ON to Occupied_OFF state when motion is still there and lights are no longer require to keep ON          
    
6) add_transition("Motion Detected & light required", light_off, all_on);
- - It goes form Occupied_OFF to Occupied_All_ON state when motion is already there and lights are require to turn ON
    
7) add_transition("Motion Detected & light not required", not_occup, light_off);
- - It goes form Not_Occupied_All_OFF to Occupied_OFF state when motion is detected and lights are not require to keep ON
    
8) add_transition("No Motion Detected", light_off, not_occup);
- - It goes form Occupied_OFF to Not_Occupied_All_OFF state if motion no longer exists in the room
    
9) add_transition("temperature change", all_on, all_on);
- - It stays in the same state if the event 'temperature change' is detected
   
10) add_transition("temperature change", light_off, light_off);
- - It stays in the same state if the event 'temperature change' is detected


Acknowledgements / Reference
---
The source code for this project is forked from [on github](https://github.com/klavinslab/elma_project).

