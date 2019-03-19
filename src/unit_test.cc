#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "gtest/gtest.h"
#include "stopwatch.h"
#include "smartroom.h"

namespace {
 
    using namespace elma;
    using namespace stopwatch;

    // TEST(StopWatch,Construction) { 
    //     //hdvdhfdhfdhf
    //     StopWatch sw; 
    //     ASSERT_EQ("off", sw.current().name());
    // }

    // More tests go here. You should aim to test every
    // method of every object, either directly or indirectly,
    // although testing user interfaces is notoriously 
    // difficult.

    TEST(Check, States) {
        IdleState id("idle");
        Occupied_All_ON on("Ocu_on");
        Occupied_OFF off("Ocu_off");
        Not_Occupied_All_OFF not_on("Not_on");
    }

    TEST(Check, StateMachine) {
        Manager m;
        SmartRoom sm = SmartRoom();

        m.schedule(sm,100_ms)
        .init()
        .run(500_ms);

        //! SmartRoom is in Idle state as no 'start' event is emited yet.
        EXPECT_EQ(sm.current().name(),"Idle");

        //! Now, it goes to Not Occupied state as 'start' is emited.
        m.emit(Event("start"));
        EXPECT_EQ(sm.current().name(),"Not Occupied");

        //! Remains in the same state as no motion detected
        m.emit(Event("No Motion Detected"));
        EXPECT_EQ(sm.current().name(),"Not Occupied");

        //! Goes to Off state as light is not required but room is occupied as motion is there
        m.emit(Event("Motion Detected & light not required"));
        EXPECT_NE(sm.current().name(),"Not Occupied");
        EXPECT_EQ(sm.current().name(),"Off");
        
    }


}