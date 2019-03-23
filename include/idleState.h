#ifndef _ELMA_SMART_ROOM_IDLESTATE_H
#define _ELMA_SMART_ROOM_IDLESTATE_H

#include "stopwatch.h"

namespace stopwatch {

    using namespace std::chrono;
    using namespace elma;

    //! A State class to represent Idle state of the Smartroom StateMachine
    class IdleState : public State {
        public:
            //! Construct a new Idle state
            IdleState(string name) : State(name) {}
            
            virtual void entry(const Event& e) {}
            virtual void during() {} 
            virtual void exit(const Event& e);
    };
}
#endif