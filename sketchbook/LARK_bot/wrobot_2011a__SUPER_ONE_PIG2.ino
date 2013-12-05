// Arduino PWM Speed Control：
// Pin definitions for PWM speed control using 
// DFRobot Arduino Compatible Motor Shield (2A):

// We comment out the 1st line below so that it will work on a 2013 motor shield, such 
// as used by the PIG:
// #define BOT_2011
#ifdef BOT_2011
#include "MotorRobotBase.h"
#define Motor MotorRobotBase
#else
#include "Motor.h" 
#endif

#include "Sensor.h"

#define FULL_SPEED 50
#define SLOW_SPEED 0
void go_right(Motor &m1, Motor &m2) 
{
     m1.reverse(SLOW_SPEED);
     m2.reverse(FULL_SPEED); 
}

void go_left(Motor &m1, Motor &m2) 
{
     m1.reverse(FULL_SPEED);
     m2.reverse(SLOW_SPEED);
}
void go_straight(Motor &m1, Motor &m2) 
{
     m1.reverse(FULL_SPEED);
     m2.reverse(SLOW_SPEED);
}

Motor right_motor(Motor::MOTOR_1);
Motor left_motor(Motor::MOTOR_2);
Sensor center_light(Sensor::SENSOR_0);
Sensor right_light(Sensor::SENSOR_3);

void setup () 
{ 
  Serial.begin(9600);
  
  right_motor.setup();
  left_motor.setup();
  center_light.setup();
  center_light.set_mode(Sensor::SIMPLEX_MODE);
  center_light.calibrate();
  right_light.setup();
  right_light.set_mode(Sensor::SIMPLEX_MODE);
  right_light.calibrate();
} 

#define RT_SENSE 100
#define CT_SENSE 100
void loop () 
{
  char light_str[255];

  int center_light_level;
  int right_light_level;
  int center_delta;
  int right_delta;

  int right = 0;
  int center = 0;
  
  center_light.read(center_light_level);
  center_delta = center_light_level - center_light.get_light_level();

  right_light.read(right_light_level);
  right_delta = right_light_level - right_light.get_light_level();

  if (abs(center_delta) >= CT_SENSE) {
      center = 1;
  }
  if (abs(right_delta) >= RT_SENSE) {
      right = 1;
  }
  
  if (right && !center) {
     go_right(left_motor, right_motor);
  }
  if (center && !right) {
     go_left(left_motor, right_motor);
  }
  if (!center && !right) {
     go_straight(left_motor, right_motor);
  }
  if (center && right) {
     go_straight(left_motor, right_motor);    
  }
  delay(5);

/*
  Serial.print(center_delta);
  Serial.print(":");
  Serial.print(center_light_level);
  Serial.print("\n");
  Serial.print(right_delta);
  Serial.print(":");
  Serial.print(right_light_level);
  Serial.print("\n");
*/ 


/*
  if (light_level > 1000) {  
    Serial.write("1000\n");    
  } else  if (light_level > 900) {  
    Serial.write("900\n");    
  } else  if (light_level > 800) {  
    Serial.write("800\n");    
  } else  if (light_level > 700) {  
    Serial.write("700\n");    
  }  else  if (light_level > 600) {  
    Serial.write("600\n");    
  }  else  if (light_level > 500) {  
    Serial.write("500\n");    
  }  else  if (light_level > 400) {  
    Serial.write("400\n");    
  }  else  if (light_level > 300) {  
    Serial.write("300\n");    
  }  else  if (light_level > 200) {  
    Serial.write("200\n");    
  }  else  if (light_level > 100) {  
    Serial.write("100\n");    
  }   else  { 
    Serial.write("00\n");    
  } 
*/
  
}



