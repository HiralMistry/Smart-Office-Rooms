#include <iostream>
#include <chrono>

#include "stopwatch.h"

using namespace std::chrono;
using namespace elma;
using namespace stopwatch;

void IdleState::exit(const Event& e) {
    // Nothing to do here.
}