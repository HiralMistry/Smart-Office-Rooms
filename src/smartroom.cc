#include <chrono>
#include <vector>

#include "smartroom.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;

SmartRoom::SmartRoom() : StateMachine("smartroom") {

    //! Defining state machine initial states and transitions

    //! Statemachine goes to the initial state as idle state
    set_initial(idle);
    
    //! It goes form IdleState to Not_Occupied_All_OFF state when 'start' event is detected   
    add_transition("start", idle, not_occup);

    //! It remains in the same state state Not_Occupied_All_OFF when there is no motion in the room   
    add_transition("No Motion Detected", not_occup, not_occup);

    //! It goes form Not_Occupied_All_OFF to Occupied_All_ON state when motion is detected and lights are require to keep ON
    add_transition("Motion Detected & light required", not_occup, all_on);

    //! It goes form Occupied_All_ON to Not_Occupied_All_OFF state if motion no longer exists in the room
    add_transition("No Motion Detected", all_on, not_occup); 

    //! It goes form Occupied_All_ON to Occupied_OFF state when motion is still there and lights are no longer require to keep ON          
    add_transition("Motion Detected & light not required", all_on, light_off);

    //! It goes form Occupied_OFF to Occupied_All_ON state when motion is already there and lights are require to turn ON
    add_transition("Motion Detected & light required", light_off, all_on);

    //! It goes form Not_Occupied_All_OFF to Occupied_OFF state when motion is detected and lights are not require to keep ON
    add_transition("Motion Detected & light not required", not_occup, light_off);

    //! It goes form Occupied_OFF to Not_Occupied_All_OFF state if motion no longer exists in the room
    add_transition("No Motion Detected", light_off, not_occup);

    //! It stays in the same state if the event 'temperature change' is detected
    add_transition("temperature change", all_on, all_on);
    
    //! It stays in the same state if the event 'temperature change' is detected
    add_transition("temperature change", light_off, light_off);

}
