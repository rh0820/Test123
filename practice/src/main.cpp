
#include "vex.h"
//Hi
//hello
using namespace vex;

float m=1;
bool toggle=true;
bool block=false;
controller ctrl;
motor f_Right(PORT10,true);
motor b_Right(PORT20,true);
motor f_Left(PORT12);
motor b_Left(PORT3);
motor_group c_left (f_Left,b_Left);
motor_group c_right (f_Right,b_Right);
competition cmp;

void userctrl() {
  while(true){
    
    if(ctrl.ButtonA.pressing()&&block){
      toggle=!toggle;
      block=false;
    }
    if(!ctrl.ButtonA.pressing()){
      block=true;
    }
    m=(toggle) ? 0.5 : 1;

    c_left.spin(directionType::fwd, ctrl.Axis3.value()*m, velocityUnits::pct);
    c_right.spin(directionType::fwd, ctrl.Axis2.value()*m, velocityUnits::pct);

    task::sleep(20);
  }
}



  void auton() {
    c_left.spin(directionType::fwd, 50, velocityUnits::pct);
    c_right.spin(directionType::fwd, 50, velocityUnits::pct);
    task::sleep(4000);

    c_left.spin(directionType::fwd, 20, velocityUnits::pct);
    c_right.spin(directionType::fwd, -20, velocityUnits::pct);
    task::sleep(3000);

    c_left.spin(directionType::fwd, -50, velocityUnits::pct);
    c_right.spin(directionType::fwd, -50, velocityUnits::pct);
    task::sleep(2000);

    c_left.stop();
    c_right.stop();

  }

  int main(){
    vexcodeInit();
    cmp.autonomous(auton);
    cmp.drivercontrol(userctrl);
  }
