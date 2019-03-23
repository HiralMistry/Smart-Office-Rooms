#ifndef _ELMA_SMARTROOM_H
#define _ELMA_SMARTROOM_H

#include "elma/elma.h" 

#include "idleState.h"
#include "occupiedAllOnState.h"
#include "occupiedOffState.h"
#include "notOccupiedAllOffState.h"

namespace stopwatch {

    using namespace std::chrono;
    using namespace elma;    

    //! A SmartRoom class, that inherits from StateMachine
    class SmartRoom : public StateMachine {

        public:
        //! Make a new SmartRoom instance
        SmartRoom();

        private:

        // State Declaration
        Occupied_All_ON all_on = Occupied_All_ON("All_On");
        Occupied_OFF light_off = Occupied_OFF("Off");
        Not_Occupied_All_OFF not_occup = Not_Occupied_All_OFF("Not Occupied");
        IdleState idle = IdleState("Idle");

    };

}

#endif