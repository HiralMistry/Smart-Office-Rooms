#ifndef _ELMA_SMART_ROOM_IDLESTATE_H
#define _ELMA_SMART_ROOM_IDLESTATE_H

#include "stopwatch.h"

namespace stopwatch {

    using namespace std::chrono;
    using namespace elma;


    class IdleState : public State {
        public:
            IdleState(string name) : State(name) {}
            virtual void entry(const Event& e) {}
            virtual void during() {} 
            virtual void exit(const Event& e);
    };
}
#endif