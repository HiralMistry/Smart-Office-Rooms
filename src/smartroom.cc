#include <chrono>
#include <vector>

#include "smartroom.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;


SmartRoom::SmartRoom() : StateMachine("smartroom") {

    // Define state machine initial states and transitions here
    set_initial(idle);
    // set_propagate(false);
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

    // // Make sure we start in the right condition
    // reset();
}

// high_resolution_clock::duration StopWatch::value() {
//     if ( current().name() == "on" ) {
//         return high_resolution_clock::now() - _start_time + _elapsed;
//     } else {
//         return _elapsed;
//     }
// }

// void StopWatch::begin() {
//     _start_time = high_resolution_clock::now();
// }

// void StopWatch::reset() {
//     _elapsed = high_resolution_clock::duration::zero();
//     _laps.clear();
// }

// void StopWatch::stop() {
//     _elapsed += high_resolution_clock::now() - _start_time;
// }

// void StopWatch::lap() {
//     _laps.insert(_laps.begin(), value());
// }