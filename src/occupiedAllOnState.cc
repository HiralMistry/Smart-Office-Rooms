#include <iostream>
#include <chrono>

#include "stopwatch.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;

void Occupied_All_ON::exit(const Event& e) {
    // if ( e.name() == "start/stop" ) {
    //     // User started the stopwatch
    //     stopwatch().begin();
    // } else if ( e.name() == "reset" ) {
    //     // User rest the stopwatch
    //     stopwatch().reset();
    // }
}