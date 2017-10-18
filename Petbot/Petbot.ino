#include <Servo.h>

Servo lServo;
Servo rServo;

const int trigPin = 2; //Ultrasonic Sensor
const int echoPin = 4; //Ports

void stopServos()             //Stops driving servos
{
  rServo.writeMicroseconds(1500);
  lServo.writeMicroseconds(1500);
}

void turnRight()              //Turns Right
{
  lServo.writeMicroseconds(1600);
  rServo.writeMicroseconds(1600);
}

void turnLeft()             //Turns Left
{
  lServo.writeMicroseconds(1400);
  rServo.writeMicroseconds(1400);
}

void forward()   //Drives forward
{
  rServo.writeMicroseconds(1400);
  lServo.writeMicroseconds(1600);
}

void rightCirc()
{
  lServo.writeMicroseconds(1800);
  rServo.writeMicroseconds(1400);
}

void leftCirc()
{
  lServo.writeMicroseconds(1400);
  rServo.writeMicroseconds(1800);
}

void setup() {
  rServo.attach(9);  // attaches the servos
  lServo.attach(10);
  stopServos();
  Serial.begin(9600);//initially stop servos
  delay (2500);   //wait 2.5 seconds until main loop starts
}

void loop() {
  //******Ping Sensor******//
  long duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  //******Ping Sensor******//

  /*if (cm < 15)
    {
    if(random(1,3)==1){
      turnLeft();
      delay(500);
      } else {
        turnRight();
        delay(500);
        }
    } else {
    stopServos();
    }*/

}

long microsecondsToCentimeters(long microseconds) //Ultrasonic Conversion
{
  return microseconds / 29 / 2;
}
