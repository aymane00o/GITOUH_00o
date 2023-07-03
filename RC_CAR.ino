
#include <AFMotor.h>

AF_DCMotor motor1(1);//define motor 1 as motor1
AF_DCMotor motor2(2);//define motor 2 as motor2
AF_DCMotor motor3(3);//define motor 3 as motor3
AF_DCMotor motor4(4);//define motor 4 as motor4
/*
 get percentage value  "0" to "100%"  and conversts it to "0" to "255" which is motor speed used by Arduino
 */
int speed(int b)
{
  return map(b, 0, 100, 0, 255);
}

void setup() {
  Serial.begin(9600); // SERIAL TEST // set up Serial library at 9600 bps
  Serial.println(" AYMANE-00o ");

  // initial state of motor turn on motor
  motor1.setSpeed(0);//motor 1 is turned off to turn on change 0, to 255
  motor2.setSpeed(0);//motor 2 is turned off  to turn on change 0, to 255
  motor3.setSpeed(0);//motor 3 is turned off to turn on change 0, to 255
  motor4.setSpeed(0); //motor 4 is turned off to turn on change 0, to 255
}
////////////////////////////////////////////////////////////////////////
void loop() {
  uint8_t i;
  
  Serial.println("Motor 1 FORWARD 50% speed");
  motor1.run(FORWARD);
  motor1.setSpeed(speed(50));
  Serial.println("Motor4 FORWARD 50%");
  motor4.run(FORWARD);
  motor4.setSpeed(speed(50));  
  delay(3000);//delay 
  // arret des moteurs//
  
  motor1.run(RELEASE);
  Serial.println("Motor1 RELEASE");
  motor4.run(RELEASE);
  Serial.println("Motor4 RELEASE");  
  delay(3000); 

  //marche arriere//

  Serial.println("Motor1 BACKWARD 80%");
  motor1.run(BACKWARD );
  motor1.setSpeed(speed(80));
  Serial.println("Motor4 BACKWARD 60%");
  motor4.run(BACKWARD );
  motor4.setSpeed(speed(60));
  delay(3000);
   // arret des moteurs//
  motor1.run(RELEASE);
  Serial.println("Motor1 RELEASE");
  motor4.run(RELEASE);
  Serial.println("Motor4 RELEASE");  
  delay(3000);   
  Serial.println("GOOD THINGS :)");
}
