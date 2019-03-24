#ifndef _ELMA_SMART_ROOM_OCCUPIED_OFF_STATE_H
#define _ELMA_SMART_ROOM_OCCUPIED_OFF_STATE_H


namespace stopwatch {

    //! A class to represent occupied state of the Smartroom StateMachine
    //! Here lights are off and A.C. / Heaters are on
    class Occupied_OFF : public State {
        public:
            //! Construct a new Occupied_OFF state
            Occupied_OFF(string name) : State(name) {}
            virtual void entry(const Event& e) {}
            virtual void during() {} 
            virtual void exit(const Event& e) {}
    };
}
#endif