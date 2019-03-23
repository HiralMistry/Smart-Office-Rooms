#include <chrono>
#include <vector>

#include "smartroom.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;

SmartRoom::SmartRoom() : StateMachine("smartroom") {

    // Define state machine initial states and transitions here
    set_initial(idle);
    
    add_transition("start", idle, not_occup);
    add_transition("No Motion Detected", not_occup, not_occup);
    add_transition("Motion Detected & light required", not_occup, all_on);
    add_transition("No Motion Detected", all_on, not_occup);            
    add_transition("Motion Detected & light not required", all_on, light_off);
    add_transition("Motion Detected & light required", light_off, all_on);
    add_transition("Motion Detected & light not required", not_occup, light_off);
    add_transition("No Motion Detected", light_off, not_occup);
    add_transition("temperature change", all_on, all_on);
    add_transition("temperature change", light_off, light_off);

}
