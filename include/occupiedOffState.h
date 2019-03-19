#ifndef _ELMA_SMART_ROOM_OCCUPIED_OFF_STATE_H
#define _ELMA_SMART_ROOM_OCCUPIED_OFF_STATE_H


namespace stopwatch {
    class Occupied_OFF : public State {
        public:
            Occupied_OFF(string name) : State(name) {}
            virtual void entry(const Event& e) {}
            virtual void during() {} 
            virtual void exit(const Event& e);
    };
}
#endif