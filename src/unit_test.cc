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

    TEST(Status, States) {
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

    TEST(Check, StateMachineAdditional) {

        Manager m;
        SmartRoom sm = SmartRoom();

        m.schedule(sm,100_ms)
        .init()
        .run(500_ms);
        m.emit(Event("start"));
        m.emit(Event("No Motion Detected"));
        m.emit(Event("Motion Detected & light not required"));

        //! Goes back to Not Occupied as ther is no motion in the room
        m.emit(Event("No Motion Detected"));
        EXPECT_EQ(sm.current().name(),"Not Occupied");

        //! Goes to All On state as motion is detected and light is required
        m.emit(Event("Motion Detected & light required"));
        EXPECT_EQ(sm.current().name(),"All_On");

        //! Remains in the same state
        m.emit(Event("temperature change"));
        EXPECT_EQ(sm.current().name(),"All_On");

        //! Goes to Off state as motion is detected but now light is no longer required
        m.emit(Event("Motion Detected & light not required"));
        EXPECT_EQ(sm.current().name(),"Off");

        //! Goes to Not Occupied state as motion is not detected
        m.emit(Event("No Motion Detected"));
        EXPECT_EQ(sm.current().name(),"Not Occupied");

        //! Remains in the same state
        m.emit(Event("temperature change"));
        EXPECT_EQ(sm.current().name(),"Not Occupied");

    }
}