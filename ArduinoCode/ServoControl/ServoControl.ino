#include <Keyboard.h>
#include <Servo.h>

Servo servo;
int servoAngle;
const int xpin = A2; //x-axis of accelerometer
const int ypin = A1; //y-axis of accelerometer
const int zpin = A0; //z-axis of accelerometer

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(51); 
}

void loop() {
  // put your main code here, to run repeatedly:

  //Handles the servo
  servoAngle = random(1, 360);
/*  servo.write(servoAngle);
  Serial.print("ServoAngle: ");
  Serial.println(servoAngle);
 */ 
  //Handles the accelerometer
  int analogX = analogRead(xpin);
  int analogY = analogRead(ypin);
  int analogZ = analogRead(zpin);
  
  double gvalX = ( ( ( (double) (analogX * 5) /1024) - 1.65 ) / 0.330 ); //acceleration in x-direction in g units
  double gvalY = ( ( ( (double) (analogY * 5) /1024) - 1.65 ) / 0.330 ); //acceleration in y-direction in g units
  double gvalZ = ( ( ( (double) (analogZ * 5) /1024) - 1.80 ) / 0.330 ); //acceleration in z-direction in g units
  
  double roll = ( ( (atan2(gvalY,gvalZ) * 180) / 3.14 ) + 180 ); // Formula for roll 
  double pitch = ( ( (atan2(gvalZ,gvalX) * 180) / 3.14 ) + 180 ); // Formula for pitch
  double yaw = ( ( (atan2(gvalX,gvalY) * 180) / 3.14 ) + 180 ); // Formula for yaw

/*  
  //prints analog voltage values at each pin
  Serial.println("\nAnalogX\tAnalogY\tAnalogZ");
  Serial.print(analogX);
  Serial.print("\t");
  Serial.print(analogY);
  Serial.print("\t");
  Serial.print(analogZ);
  Serial.print("\n");
 
  //prints acceleration
  Serial.println("\nAcceleration in G values -- X, Y, Z");
  Serial.print(gvalX);
  Serial.print("\t");
  Serial.print(gvalY);
  Serial.print("\t");
  Serial.println(gvalZ);
*/

  //prints roll pitch and yaw angle values
  Serial.println("\nRoll\tPitch\tYaw");
  Serial.print(roll);
  Serial.print("\t");
  Serial.print(pitch);
  Serial.print("\t");
  Serial.println(yaw);
  Serial.println();
  delay(1000);
  

  if ( (roll > 360) || (pitch > 360) || (yaw > 360)) {
    Serial.println("ERROR: GREATER THAN 360!!!! NOTICE ME");
  }
  // test function to see if any of the angle values exceed 360.
  
  
}
