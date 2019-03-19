#ifndef _ELMA_SMART_ROOM_NOT_OCCUPIED_ALL_OFF_STATE_H
#define _ELMA_SMART_ROOM_NOT_OCCUPIED_ALL_OFF_STATE_H


namespace stopwatch {
    class Not_Occupied_All_OFF : public State {
        public:
            Not_Occupied_All_OFF(string name) : State(name) {}
            virtual void entry(const Event& e) {}
            virtual void during() {} 
            virtual void exit(const Event& e);
    };
}
#endif