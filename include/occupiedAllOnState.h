#ifndef _ELMA_SMART_ROOM_OCCUPIED_ALL_ON_STATE_H
#define _ELMA_SMART_ROOM_OCCUPIED_ALL_ON_STATE_H


namespace stopwatch {
    
    //! A class to represent occupied state of the Smartroom StateMachine
    //! Here lights and A.C. / Heater are working
    class Occupied_All_ON : public State {
        public:
            //! Construct a new Occupied_All_ON state
            Occupied_All_ON(string name) : State(name) {}
            virtual void entry(const Event& e) {}
            virtual void during() {} 
            virtual void exit(const Event& e) {}
    };
}
#endif