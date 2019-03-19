#ifndef _ELMA_SMART_ROOM_OCCUPIED_ALL_ON_STATE_H
#define _ELMA_SMART_ROOM_OCCUPIED_ALL_ON_STATE_H


namespace stopwatch {
    class Occupied_All_ON : public State {
        public:
            Occupied_All_ON(string name) : State(name) {}
            virtual void entry(const Event& e) {}
            virtual void during() {} 
            virtual void exit(const Event& e);
    };
}
#endif