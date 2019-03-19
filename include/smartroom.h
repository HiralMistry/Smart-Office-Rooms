#ifndef _ELMA_SMARTROOM_H
#define _ELMA_SMARTROOM_H

#include "elma/elma.h" // Note installation directory for elma

#include "idleState.h"
#include "occupiedAllOnState.h"
#include "occupiedOffState.h"
#include "notOccupiedAllOffState.h"

namespace stopwatch {

    using namespace std::chrono;
    using namespace elma;    

    //! A stop watch class, that inherits from StateMachine
    class SmartRoom : public StateMachine {

        public:
        //! Make a new stopwatch
        SmartRoom();

        // //! Start the stopwatch
        // void begin();

        // //! Reset the stopwatch to zero and erase laps
        // void reset();

        // //! Stop the stopwatch
        // void stop();

        // //! Add a lap time to the list of lap times.
        // void lap();

        // //! Get the time stored by the stopwatch
        // high_resolution_clock::duration value();

        // //! Get a list of lap times
        // const vector<high_resolution_clock::duration>& laps() { return _laps; }

        private:

        // When overriding the StateMachine class, put state declarations here.
        Occupied_All_ON all_on = Occupied_All_ON("All_On");
        Occupied_OFF light_off = Occupied_OFF("Off");
        Not_Occupied_All_OFF not_occup = Not_Occupied_All_OFF("Not Occupied");
        IdleState idle = IdleState("Idle");

        // Other private variables
        // bool _running;
        // high_resolution_clock::time_point _start_time;
        // high_resolution_clock::duration _elapsed;
        // vector<high_resolution_clock::duration> _laps;

    };

}

#endif