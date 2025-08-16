#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void test2(){  
    
     PIDDataSet TestPara={1.5,0.1,0.15};
    MoveEncoderPID(TestPara, 100, 12, 0.4, 0, true);
    TurnMaxTimePID(TestPara, 30, 0.5,true);
    MoveEncoderPID(TestPara, 100, 13, 0.4, 30, true);
    MoveEncoderPID(TestPara, 40, 13, 0.4, 30, true);
    Clamp.set(false);
    wait(200,msec);
    MoveEncoderPID(TestPara, 100, 0.2, 0.4,30, true);
    Tilt.set(false);
    MoveEncoderPID(TestPara, 100, 3, 0.4,30, true);
    TurnMaxTimePID(TestPara, -84, 0.8, true);
    RunRoller(-100);
    MoveEncoderPID(TestPara, -100, 25, 0.4,-84, true);
    TurnMaxTimePID(TestPara,60, 0.5, true);
    Pistake.set(true);
    MoveEncoderPID(TestPara, -100, 60, 0.4, 60, true);
    Pistake.set(false);
    wait(500,msec);
    MoveEncoderPID(TestPara, 100, 10, 0.4, 60, true);
    TurnMaxTimePID(TestPara, -12, 0.9, true);
    MoveEncoderPID(TestPara, 100, 23, 0.4, -12, false);

}